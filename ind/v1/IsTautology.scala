trait Expr
case class Prop(value:Char) extends Expr
case class Not(expr:Expr) extends Expr
case class And(left:Expr, right:Expr) extends Expr
case class Or(left:Expr, right:Expr) extends Expr
case class Paren(value:Expr) extends Expr

trait Result
case class Success(expr:Expr,rem:String) extends Result
case class Failure() extends Result

object IsTautology { 

    def getAndOr(op:Char,left:Result,right:Result) = {
        (op,left,right) match {
            case ('&',Success(le,lr),Success(re,rr)) => 
                Success(And(le,re),rr)
            case ('|',Success(le,lr),Success(re,rr)) => 
                Success(Or(le,re),rr)
        }
    }

    def prop(s:String): Result =  s.size match { 
        case x if x <= 0 => Failure()
        case _ => s.charAt(0).isLetter match {
            case true => Success(Prop(s.charAt(0)),s.substring(1))
            case _    => { // only remaining option is parenthesis
                expr(s.substring(1)) match { 
                    case Success(e,r) => Success(Paren(e),r.substring(1))
                }
            }
        }
    }

    def elem(s:String): Result = s.charAt(0) match {
        case '!' => {
            elem(s.substring(1)) match { 
                case Success(e,r) => 
                    Success(Not(e),r)
            }
        }
        case _   => prop(s)
    }

    def expr(s:String): Result = {
        val left = elem(s)
        left match { 
            case Success(exp,rem) => {
                rem.size match { // if left and right match then And or Or
                    case x if x > 0 => {
                        val right = elem(rem.substring(1))
                        getAndOr(rem.charAt(0),left,right)
                    }
                    case _ => left // only left only one expression
                }
            }
        }
    }
                            
    def parse(s:String) = expr(s.replace(" ","")) match { 
        case Success(result,_) => result
        case _ => scala.sys.error("Failure")
    }

    def variables(e:Expr):Set[Char] = e match { 
        case Prop	(x)   => Set(x)
        case Paren	(x)   => variables(x)
        case Not	(x)   => variables(x)
        case And	(x,y) => (variables(x) ++ variables(y))
        case Or	    (x,y) => (variables(x) ++ variables(y))
    }

    def evaluate(e:Expr,truths:Set[Char]):Boolean = e match { 
        case Prop	(x)   => truths.contains(x)
        case Paren	(x)   => evaluate(x,truths)
        case Not	(x)   => !evaluate(x,truths)
        case And	(x,y) => evaluate(x,truths) & evaluate(y,truths) 
        case Or	    (x,y) => evaluate(x,truths) | evaluate(y,truths)
    }

    def apply(s:String): Boolean =  { 
        val tree = parse(s)
        variables(tree).subsets
            .map((x:Set[Char]) => evaluate(tree,x))
            .fold(true)((ans,curr) => ans & curr ) 
    }
}
