package homework

import scala.annotation.tailrec

object Question04 {
  def mergesort(list: List[Int]): List[Int] = {
    def merge(l: List[Int], r: List[Int]): List[Int] = {
      if (l.isEmpty) r
      else if (r.isEmpty) l
      else if (l.head <= r.head) l.head :: merge(l.tail, r)
      else r.head :: merge(l, r.tail)
    }

    @tailrec
    def split(list: List[Int], index: Int, l: List[Int], r: List[Int]): (List[Int], List[Int]) = {
      if (list.isEmpty) (l, r)
      else if (index % 2 == 0) split(list.tail, index + 1, list.head :: l, r)
      else split(list.tail, index + 1, l, list.head :: r)
    }

    val length = list.length
    if (length < 2) list
    else {
      val (left, right) = split(list, 0, Nil, Nil)
      merge(mergesort(left), mergesort(right))
    }
  }

  def main(args: Array[String]): Unit = {
    var l1 = List(3, 7, 1, 9, 2)
    var l2 = List(5, 6, 4, 8)

    println(mergesort(l1))
    println(mergesort(l2))
    println(mergesort(l1 ++ l2))
    println(mergesort(l2 ++ l1))
  }
}
