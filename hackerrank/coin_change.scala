import scala.io.StdIn._

object coin_change {

  def main(args: Array[String]): Unit = {
    val Array(n, m) = readLine().split(" ").map(_.toInt)
    val coins = readLine().split(" ").map(_.toInt)

    val dp = Array.fill[Long](n + 1)(0)
    dp(0) = 1

    for (c <- coins) {
      for (i <- 1 to n if i - c >= 0) {
        dp(i) += dp(i - c)
      }
    }

    println(dp(n))
  }
}
