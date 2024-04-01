package finalExam

import scala.annotation.tailrec

object Q1 {
  def swapPair(l:List[Int]): List[Int] = {
    @tailrec
    def swapOneByOne(l:List[Int], storage:List[Int]): List[Int] = {
      if (l.isEmpty) {
        return storage
      }
      if (l.length == 1) {
        return storage ++ List(l.head)
      }
      swapOneByOne(l.tail.tail, storage ++ List(l.tail.head) ++ List(l.head))
    }

    swapOneByOne(l, List())
  }

  def main(args: Array[String]): Unit = {
    val list1 = List()
    val list2 = List(22)
    val list3 = List(1, 2, 3)
    val list4 = List(1, 2, 3, 4)
    val list5 = List(1, 2, 3, 4, 5)
    val list6 = List(1, 2, 3, 4, 5, 6)
    println(swapPair(list1) == List())
    println(swapPair(list2) == List(22))
    println(swapPair(list3) == List(2, 1, 3))
    println(swapPair(list4) == List(2, 1, 4, 3))
    println(swapPair(list5) == List(2, 1, 4, 3, 5))
    println(swapPair(list6) == List(2, 1, 4, 3, 6, 5))
  }
}
