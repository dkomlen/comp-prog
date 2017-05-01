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
}


