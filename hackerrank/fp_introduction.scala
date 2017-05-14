import scala.io.StdIn

object fp_introduction {

  def list_replication(num:Int, arr:List[Int]): List[Int] = arr.flatMap(x => List.fill(num)(x))

  def array_filter(delim:Int,arr:List[Int]):List[Int] = arr match {
    case Nil => Nil
    case head :: tail if head < delim => head :: array_filter(delim, tail)
    case head :: tail => array_filter(delim, tail)
  }

  def filter_positions(arr:List[Int]):List[Int] = {
    def helper(arr: List[Int], odd: Boolean=false): List[Int] = arr match {
      case h :: t if odd => h :: helper(t, !odd)
      case h :: t if !odd => helper(t, !odd)
      case Nil => Nil
    }
    helper(arr)
  }

  def array_of_n_elements(num:Int) : List[Int] = {
    def helper(n: Int): List[Int] = {
      if (n > num) Nil
      else n :: helper(n + 1)
    }
    helper(1)
  }

  def reverse_a_list(arr:List[Int]):List[Int] = {
    def helper(input: List[Int], output: List[Int] = Nil): List[Int] = input match {
      case Nil => output
      case x :: xs => helper(xs, x :: output)
    }
    helper(arr)
  }

  def sum_of_odd_elements(arr:List[Int]):Int = arr match {
      case Nil => 0
      case x :: xs => (if (x % 2 != 0) x else 0) + sum_of_odd_elements(xs)
  }

  def list_length(arr:List[Int]):Int = {
    def len(arr: List[Int], ctr: Int = 0): Int = arr match {
      case Nil => ctr
      case x :: xs => len(xs, ctr + 1)
    }
    len(arr)
  }

  def update_list(arr:List[Int]):List[Int] = arr match {
    case Nil => Nil
    case x :: xs => Math.abs(x).toInt :: update_list(xs)
  }

  def main(args: Array[String]): Unit = {
    def ex(x: Double, n: Long = 0, m: Long = 1, z: Long = 1): Double = if (n < 10) {
      Math.pow(x, n) / m + ex(x, n + 1, (if (n == 0) m else m * z), z + 1)
    } else {
      0
    }

    for (i <- 1 to StdIn.readInt) {
      println(f"${ex(StdIn.readDouble)}%.4f")
    }
  }
}


