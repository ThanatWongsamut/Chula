package homework

object Question02 {
  def insertInOrder(x: Int, list: List[Int]): List[Int] = {
    if (list.isEmpty) List(x)
    else if (list.head >= x) List(x) ++ list
    else List(list.head) ++ insertInOrder(x, list.tail)
  }

  def main(args: Array[String]): Unit = {
    var a = List(1, 2, 4, 5)
    var b = List(2, 4)
    var c = List()
    var x = 3
    var y = 6

    println(insertInOrder(x, a))
    println(insertInOrder(x, b))
    println(insertInOrder(x, c))
    println(insertInOrder(y, a))
    println(insertInOrder(y, b))
    println(insertInOrder(y, c))
  }
}
