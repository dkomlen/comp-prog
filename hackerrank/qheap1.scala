import scala.collection.mutable
import scala.io.StdIn._

object qheap1 {

  object MinOrder extends Ordering[Int] {
    def compare(x: Int, y: Int) = x.compare(y)
  }

  def main(args: Array[String]): Unit = {
    val heap = mutable.SortedSet.empty(MinOrder)
    for (i <- 1 to readInt()) {
      val x = readLine().split(" ").map(_.toInt)
      x.head match {
        case 1 => heap.add(x(1))
        case 2 => heap.remove(x(1))
        case 3 => println(heap.head)
      }
    }
  }
}
