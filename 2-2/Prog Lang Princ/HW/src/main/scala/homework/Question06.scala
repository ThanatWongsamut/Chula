package homework

object Question06 {
  def myMap(f: Int => Int) (list: List[Int]): List[Int] = {
    if (list.isEmpty) return List()
    f(list.head) :: myMap(f)(list.tail)
  }

  def main(args: Array[String]): Unit = {
    var l1 = List(1, 2, 3, 4, 5)
    var l2 = List(2, 4, 6, 8)

    val square = (x: Int) => x * x

    println(myMap(x => x * 2)(l1))
    println(myMap(x => x * 2)(l2))
    println(myMap(square)(l1))
    println(myMap(square)(l2))
  }
}
