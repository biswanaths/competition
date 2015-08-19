import org.scalatest.FunSuite

class VerifierSuite extends FunSuite {
  
  val v = IsTautology

  test("All the correct cases should pass") {
    assert(IsTautology("(!a | (a & a))") == true)
    assert(IsTautology("(!a | (b & !a))") == false)
    assert(IsTautology("(!a | a)") == true)
    assert(IsTautology("((a & (!b | b)) | (!a & (!b | b)))") == true)
  }
  
  test("Get And expression from the successful left and right results") {
    val left = Success(Prop('A'),"")
    val right= Success(Prop('A'),"")
    val andExp = v.getAndOr('&', left, right)
    assert(andExp.isInstanceOf[Success])
    andExp match { 
      case Success(x,y) => assert(x.isInstanceOf[And])
    }
  }

  test("Get Or expression from the successful left and right results") {
    val left = Success(Prop('A'),"")
    val right= Success(Prop('A'),"")
    val andExp = v.getAndOr('|', left, right)
    assert(andExp.isInstanceOf[Success])
    andExp match { 
      case Success(x,y) => assert(x.isInstanceOf[Or])
    }
  }
  
  test("Proposition parse should return a propostion") {
    v.prop("A") match {
      case Success(x,y) => {
        x match { 
          case Prop(c) => assert(c=='A')
        }
      }
    }
  }

  test("Proposition parse should return a propostion and reminder ") {
    v.prop("ABC") match {
      case Success(x,y) => {
        x match { 
          case Prop(c) => { 
            assert(c=='A')
          }
        }
      }
      assert(y=="BC")
    }
  }
  
  test("Element should return a Not expression") {
    v.elem("!A") match {
      case Success(x,y) => {
        x match { 
          case Not(c) =>  assert(true)
          case _ => assert(false)
        }
      }
    }
  }
  
  test("Element should return a recursive Not expression") {
    v.elem("!!A") match {
      case Success(x,y) => {
        x match { 
          case Not(c) =>  c match {
            case Not(d)=> assert(true)
            case _ => assert(false)
          }
          case _ => assert(false)
        }
      }
    }
  }
  
  test("Element should return a Paren Expression") {
    v.expr("(a&b)") match {
      case Success(x,y) => {
        x match {
          case Paren(x) => assert(true)
          case _ => assert(false)
        }
      }
    }
  }
  
  test("Parse should result in a success") { 
    v.parse("(a&b)") match { 
      case e:Expr => assert(true)
      case _ => assert(false)
    }
  }
  
  test("Variables x,y,z should exist in the expression") {
    val e = Not(And(Not(Prop('z')),Paren(Or(Prop('y'),Prop('x')))))
    val vars = v.variables(e)
    assert(vars.contains('x'))
    assert(vars.contains('y'))
    assert(vars.contains('z'))
    assert(vars.size == 3)
  }
  
  test("Evaluate should return false") {
    val e = Not(And(Not(Prop('z')),Paren(Or(Prop('y'),Prop('x')))))
    assert(v.evaluate(e, Set()))
  }
  
  test("Evaluate should return true") {
    val e = Not(And(Not(Prop('z')),Paren(Or(Prop('y'),Prop('x')))))
    assert(v.evaluate(e, Set('x','y','z')))
  }
  
}