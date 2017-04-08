package qualification

import scala.io.StdIn._

object B {

  def main(args: Array[String]): Unit = {
    for (t <- 1 to readInt) {
      val xs:List[Int] = readLine.map(_ - '0').reverse.toList
      val (sol, _) = Iterator.iterate((List[Int](), xs)) {
        case (sol, a :: b :: xs) => if (a < b) (List.fill(sol.size + 1)(9), (b - 1) :: xs) else (a :: sol, b :: xs)
        case (sol, a) => (a.head :: sol, Nil)
      }.dropWhile( { case (sol, xs) => !xs.isEmpty} ).take(1).next

      println (s"Case #$t: ${sol.dropWhile(_ == 0).mkString("")}")
    }
  }
}
