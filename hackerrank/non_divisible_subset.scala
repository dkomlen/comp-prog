import java.lang.Math.max

import scala.io.StdIn._

object non_divisible_subset {

  def main(args: Array[String]): Unit = {
    val Array(n, k) = readLine().split(" ").map(_.toInt)
    val nums = readLine().split(" ").map(_.toInt)
    val reminders: Map[Int, Array[Int]] = nums.map(_ % k).groupBy(a => a)

    val sol = (for (i <- 0 to k / 2) yield {
      val x = reminders.getOrElse(i, Array()).length
      val y = reminders.getOrElse(k - i, Array()).length

      if ((i == 0 || 2 * i == k) && x >= 1) {
        1
      } else {
        max(x, y)
      }
    }).sum

    println(sol)
  }
}
