import scala.io.StdIn._

object string_mingling {

  def main(args: Array[String]): Unit = {
    println(readLine.zip(readLine).flatMap{case (a,b) => List(a,b)}.mkString(""))
  }
}
