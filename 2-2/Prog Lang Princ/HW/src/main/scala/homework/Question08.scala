package homework

object Question08 {
  def sumAll(lists: List[List[Int]]): List[Int] = {
    def sumFirstPosition(remain: List[List[Int]]): (Int, List[List[Int]]) = {
      if (remain.isEmpty) return (0, List(List()))
      var firstHead = remain.head
      var tailHead = remain.tail

      if (firstHead.isEmpty) return sumFirstPosition(tailHead)

      var h = firstHead.head
      var t = firstHead.tail

      val (s, l) = sumFirstPosition(tailHead)

      return (s + h, t :: l)
    }

    val (s, r) = sumFirstPosition(lists)
    if (r.tail.isEmpty) return List()
    return List(s) ++ sumAll(r)
  }

  def main(args: Array[String]): Unit = {
    println(sumAll(List()))
    println(sumAll(List(List())))
    println(sumAll(List(List(1, 2, 3, 4), List(), List(4, 5), List(1, 2, 3, 4, 5, 6))))
    println(sumAll(List(List(3, 4), List(1, 2, 3, 4, 5, 6), List(1, 2, 3, 4))))
    println(sumAll(List(List(1, 2, 3, 4, 5, 6), List(1, 2, 3, 4), List(1, 2), List(0, 0, 0, 0, 0, 0, 0, 0, 9))))
  }
}
