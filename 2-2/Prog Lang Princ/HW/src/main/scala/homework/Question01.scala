package homework

object Question01 {
  def insertList(x: Any, l:List[Any]): List[Any] = {
    l ++ List(x)
  }

  def main(args: Array[String]): Unit = {
    var a = List(1,2,3,4,5)
    var b = List(2,3,4)
    var c = List()
    var x = 6
    var y = 10

    println(insertList(x,a))
    println(insertList(x,b))
    println(insertList(x,c))
    println(insertList(y,a))
    println(insertList(y,b))
    println(insertList(y,c))
  }
}
