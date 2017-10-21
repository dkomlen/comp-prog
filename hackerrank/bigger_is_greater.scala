import scala.io.StdIn._

object bigger_is_greater {

  def main(args: Array[String]): Unit = {
    for (_ <- 1 to readInt) {

      solve(readLine) match {
        case Some(sol) => println(sol)
        case None => println("no answer")
      }
    }
  }

  private def solve(s: String): Option[String] = {
    if (s.length > 1) {
      val sol = s.toCharArray
      for (x <- s.length - 2 to 0 by -1) {
        for (y <- s.length - 1 to (x + 1) by -1) {
          if (s(x) < s(y)) {
            val tmp = sol(x)
            sol(x) = sol(y)
            sol(y) = tmp
            return Some((sol.take(x + 1) ++ sol.drop(x + 1).reverse).mkString(""))
          }
        }
      }
    }
    return None
  }
}
