package homework

object Question07 {
  def myFilter(f: Int => Boolean) (list: List[Int]): List[Int] = {
    if (list.isEmpty) return List()
    else if (f(list.head)) return list.head :: myFilter(f)(list.tail)
    else return myFilter(f)(list.tail)
  }

  def main(args: Array[String]): Unit = {
    var l1 = List(1, 2, 3, 4, 5)
    var l2 = List(2, 4, 6, 8, 10)

    def isLessThan3 (x: Int) = x < 3

    println(myFilter(x => x % 2 == 0)(l1))
    println(myFilter(x => x % 2 == 0)(l2))
    println(myFilter(isLessThan3)(l1))
    println(myFilter(isLessThan3)(l2))
  }
}
