import scala.io.StdIn._

object missing_numbers_fp {

  def main(args: Array[String]): Unit = {
    val n = readInt
    val as = readLine.split(" ").map(_.toInt).groupBy(p => p).mapValues(_.size)
    val m = readInt
    val bs = readLine.split(" ").map(_.toInt)

    val sol = bs.foldLeft((as, List[Int]()))({ case ((mp, sol), b) => {
      mp.get(b) match {
        case Some(l) if l > 0 => (mp.updated(b, l - 1), sol)
        case _ => (mp, b :: sol)
      }
    }})._2.distinct.sorted

    println(sol.mkString(" "))
  }
}
