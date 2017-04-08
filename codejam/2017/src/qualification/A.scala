package qualification

import scala.io.StdIn._

object A {
  def main(args: Array[String]): Unit = {
    for (t <- 1 to readInt) {
      val Array(pan, x) = readLine.split(" ")
      val n = x.toInt
      val arr: Array[Boolean] = pan.toCharArray.map(_ == '+')
      var times = 0

      for (i <- 0 until arr.size) {
        if (!arr(i) && i <= arr.size - n) {
          times += 1
          for (j <- 0 until n) {
            arr(i + j) = !arr(i + j)
          }
        }
      }

      val sol =  (if (arr.reduce(_ && _)) times.toString else "IMPOSSIBLE")
      println (s"Case #$t: $sol")
    }
  }
}
