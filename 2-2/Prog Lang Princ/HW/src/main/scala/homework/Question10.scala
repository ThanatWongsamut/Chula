package homework

import scala.annotation.tailrec

object Question10 {
  def alternate(f1: (Int, Int) => Int, f2: (Int, Int) => Int, list: List[Int]): Int = {
    @tailrec
    def cal(f: (Int, Int) => Int, remain: List[Int], result: Int): Int = {
      if (remain.isEmpty) return result
      var head = remain.head
      var tail = remain.tail

      if (tail.isEmpty) return f(result, head)
      else if (f == f1) return cal(f2, tail, f1(result, head))
      else return cal(f1, tail, f2(result, head))
    }

    if (list.isEmpty) 0
    else cal(f1, list.tail, list.head)
  }

  def main(args: Array[String]): Unit = {
    val plus = (x: Int, y: Int) => x + y
    val minus = (x: Int, y: Int) => x - y

    println(alternate(plus,minus, List()))
    println(alternate(plus,minus, List(55)))
    println(alternate(plus,minus, List(1, 2)))
    println(alternate(plus,minus, List(1, 2, 3)))
    println(alternate(plus,minus, List(1, 2, 3, 4)))
  }
}
