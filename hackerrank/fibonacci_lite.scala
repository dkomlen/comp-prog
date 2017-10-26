import scala.annotation.tailrec
import scala.io.StdIn._

object fibonacci_lite {

  @tailrec
  def fib(a: BigInt, b: BigInt, n: Int, i: Int): (BigInt, BigInt) = n match {
    case n if n == 0 => (-1, a)
    case n if n == i => (a, b)
    case _ => fib(b, a + b, n, i + 1)
  }

  @tailrec
  def fibs(a: BigInt, b: BigInt, ns: List[Int], i: Int, sol: List[BigInt]): List[BigInt] = ns match {
    case Nil => sol.reverse
    case n :: ntail if n == 0 => fibs(a, b, ntail, i, 0 :: sol)
    case n :: ntail if n == i => fibs(a, b, ntail, i, b :: sol)
    case _ => fibs(b, a + b, ns, i + 1, sol)
  }

  def main(args: Array[String]): Unit = {

    val xs = Iterator.continually(readLine).takeWhile(_ != null).map(_.toInt).toList

    val sols = fibs(0, 1, xs.sorted, 1, List())

    xs.zipWithIndex.sorted.zip(sols).sortBy { case ((n, i), f) => i }
      .map { case ((n, i), f) => println(f) }
  }
}
