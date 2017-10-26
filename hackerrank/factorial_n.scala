import scala.io.StdIn._

object factorial_n {

  def fact(a: BigInt, b: BigInt): Stream[BigInt] = a #:: fact(a * b, b + 1)

  def fact2 = Iterator.iterate((1, 1))(n => (n._1 * (n._2 + 1), n._2 + 1))

  def main(args: Array[String]): Unit = {
    println(readInt match {
      case 0 => 1
      case n => fact2.drop(n - 1).next._1
    })
  }
}
