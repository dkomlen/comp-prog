import scala.io.StdIn.readLine

object Solution {

  def main(args: Array[String]): Unit = {
    def getInts = readLine.split(" ").map(_.toInt)
    val sol = getInts.zip(getInts).map(x => x._1 - x._2)
    println(s"${sol.count(_ > 0)} ${sol.count(_ < 0)}")
  }
}
