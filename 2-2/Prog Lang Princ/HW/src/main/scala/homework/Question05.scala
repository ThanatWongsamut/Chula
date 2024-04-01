package homework

object Question05 {
  def palindrome(list: List[Any]):Boolean = {
    def rev(l: List[Any]): List[Any] = {
      if (l.isEmpty) return List()
      rev(l.tail) ++ List(l.head)
    }

    list == rev(list)
  }

  def main(args: Array[String]): Unit = {
    val l1 = List(1, 2, 3, 2, 1)
    val l2 = List(1, 2, 3, 4, 5)
    val l3 = List(1, 2, 2, 1)
    val l4 = List(1, 2, 3, 4)

    println(palindrome(l1))
    println(palindrome(l2))
    println(palindrome(l3))
    println(palindrome(l4))
  }
}
