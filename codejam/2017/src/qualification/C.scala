package qualification

import scala.io.StdIn._

object C {

  case class Seg (size: BigInt, count: BigInt) {
    def split(xs: List[Seg]) = {
      if (size % 2 > 0) Seg((size - 1) / 2, count * 2) :: xs
      else Seg((size - 1) / 2 + 1, count) :: Seg((size - 1) / 2, count) :: xs
    }
    val sol = {
      val ls = (size - 1) / 2
      val rs = if (size > 0 && size % 2 == 0) ls + 1 else ls
      if (ls > rs) s"$ls $rs" else s"$rs $ls"
    }
  }

  def reduce(segs: List[Seg]): List[Seg] = {
    segs.groupBy(s => s.size)
      .map({case (k,v) => Seg(v.head.size, v.map(_.count).sum)})
      .toList
      .sortBy(s => s.size)
      .reverse
  }

  def main(args: Array[String]): Unit = {
    for (t <- 1 to readInt) {
      val Array(n, k) = readLine.split(" ").map(BigInt(_))
      val (segs, x) = Iterator.iterate((List(Seg(n, 1)), k)) {
        case (seg :: xs, x) => (reduce(seg.split(xs)), x - seg.count)
      }.dropWhile({
        case (segs, x) => x > segs.head.count
      }).take(1).next

      println (s"Case #$t: ${segs.head.sol}")
    }
  }
}
