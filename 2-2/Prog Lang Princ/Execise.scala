object Exercise {
  def member(x: Any, l: List[Any]): Boolean = {
    if(l.isEmpty) return false
    if(l.head == x) return true
    member(x, l.tail)
  }

  def sorted(l: List[Int]): Boolean = {
    if (l.isEmpty || l.length == 1) return true
    return ((l.head <= (l.tail).head) && sorted(l.tail))
  }

  def delete(x: Any, l: List[Any]): List[Any] = {
    if (l.isEmpty) return List()
    else if (x == l.head) delete(x,l.tail)
    else l.head :: delete(x,l.tail)
  }

  def length(l: List[Any]): Int = {
    if (l.isEmpty) return 0
    else return 1 + length(l.tail)
  }

  def myReverse(l: List[Any]): List[Any] = {
    if (l.isEmpty) return List()
    myReverse(l.tail) ++ List(l.head)
  }

  def dot(l1: List[Int], l2: List[Int]): Int = {
    if (l1.isEmpty || l2.isEmpty) return 0
    else l1.head * l2.head + dot(l1.tail, l2.tail)
  }

  def maxx(l:List[Int]): Int = {
    if (l.isEmpty) throw Exception
    if (l.length == 1) return l.head
    if (l.head >= maxx(l.tail)) return l.head
    else return maxx(l.tail)
  }

  def setify(l:List[Any]): List[Any] = {
    if (l.isEmpty) return List()
    if (members(l.head, l.tail)) {
      return setify(l.tail)
    } else {
      return l.head :: setify(l.tail)
    }
  }

  def main(args: Array[String]) = {
    val x: List[Int] = List(2)

    println(member(2, x))
    println(sorted(x))
    println(delete(2,x))
    println(length(x))
    println(myReverse(x))
    println(maxx(x))
  }
}