import org.scalatest.FunSuite
import scala.util.parsing.combinator._


class VerifierSuite extends FunSuite {
  
  val v = IsTautology

  test("All the correct cases should pass") {
    assert(IsTautology("(!a | (a & a))") == true)
    assert(IsTautology("(!a | (b & !a))") == false)
    assert(IsTautology("(!a | a)") == true)
    assert(IsTautology("((a & (!b | b)) | (!a & (!b | b)))") == true)
  }
  
  test("Should succsfully parse prop") {
    v.parseAll(v.prop, "a").get match {
      case Prop(c) => assert(c=='a')
    }
  }
  
  test("Should succsfully parse not") {
    v.parseAll(v.elem, "!a").get match {
      case Not(c) => assert(true)
      case _ => assert(false)
    }
  }
  
  test("Should succsfully parse paren") {
    v.parseAll(v.prop, "(a)").get match {
      case Prop(c) => assert(true)
      case _ => assert(false)
    }
  }

  test("Should succsfully parse And") {
    v.parseAll(v.expr, "a&b").get match {
      case And(c,d) => assert(true)
      case _ => assert(false)
    }
  }
  
  test("Should succsfully parse Or") {
    v.parseAll(v.expr, "a|b").get match {
      case Or(c,d) => assert(true)
      case _ => assert(false)
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