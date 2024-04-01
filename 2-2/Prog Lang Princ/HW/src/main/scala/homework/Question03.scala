package homework

import scala.annotation.tailrec

object Question03 {
  @tailrec
  def subList(l1:List[Any], l2:List[Any]): Boolean = {
    @tailrec
    def contain(x: Any, l: List[Any]): Boolean = {
      if (l.isEmpty) false
      else (x == l.head) || contain(x, l.tail)
    }

    if (l1.isEmpty) true
    else contain(l1.head, l2) && subList(l1.tail, l2)
  }

  def main(args: Array[String]): Unit = {
    var a1 = List(1, 2, 3)
    var b1 = List(1, 2, 3, 4, 5)

    var a2 = List(1, 2, 3)
    var b2 = List(1, 2, 4, 5, 6)

    var a3 = List()
    var b3 = List(1, 2, 3, 4, 5)

    println(subList(a1, b1))
    println(subList(a2, b2))
    println(subList(a3, b3))
  }
}
