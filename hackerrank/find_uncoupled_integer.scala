import scala.io.StdIn._

object find_uncoupled_integer {

  def main(args: Array[String]): Unit = {
    println(readLine().split(",").map(_.trim.toInt).reduce(_ ^ _))
  }
}
