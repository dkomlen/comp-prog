import scala.io.StdIn._

object string_compression {

  def solve(s: List[Char], sol: List[(Char, Int)]): List[(Char, Int)] = (s, sol) match {
    case (Nil, _) => sol.reverse
    case (x :: xs, Nil) => solve(xs, List((x, 1)))
    case (x :: xs, (c, ctr) :: ys) if (x == c) => solve(xs, (c, ctr + 1) :: ys)
    case (x :: xs, (c, ctr) :: ys) => solve(xs, (x, 1) :: sol)
  }

  def main(args: Array[String]): Unit = {
    println(solve(readLine.toList, Nil).map{case (c,i) => if (i > 1) s"$c$i" else c}.mkString)
  }
}
