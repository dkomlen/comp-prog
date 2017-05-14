import scala.io.StdIn._

object string_o_permute {

  def main(args: Array[String]): Unit = {
    val n = readInt
    for (i <- 1 to n) {
      println(readLine.grouped(2).flatMap(_.reverse).mkString(""))
    }
  }
}
