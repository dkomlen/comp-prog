import scala.io.StdIn._

object the_time_in_words {

  val numsMap = Map(0 -> "", 1 -> "one", 2 -> "two", 3 -> "three", 4 -> "four", 5 -> "five", 6 -> "six", 7 -> "seven", 8 -> "eight",
    9 -> "nine", 10 -> "ten", 11 -> "eleven", 12 -> "twelve", 13 -> "thirteen", 14 -> "fourteen", 15 -> "fifteen",
    16 -> "sixteen", 17 -> "seventeen", 18 -> "eighteen", 19 -> "nineteen", 20 -> "twenty")

  def main(args: Array[String]): Unit = {
    val (hour, min) = (readInt, readInt)
    println(convert(hour, min))
  }

  def convert(hour: Int, min: Int): String = {
    val (h, m) = if (min <= 30) (hour, min) else (hour + 1, 60 - min)
    val (hs, ms) = (numToString(h), numToString(m))

    min match {
      case 0 => s"$hs o' clock"
      case m if m < 10 => s"$ms minute past $hs"
      case 15 => s"quarter past $hs"
      case m if m < 30 => s"$ms minutes past $hs"
      case 30 => s"half past $hs"
      case 45 => s"quarter to $hs"
      case m if m > 10 => s"$ms minutes to $hs"
      case _ => s"$ms minute to $hs"
    }
  }

  private def numToString(num: Int): String = {
    if (num > 20) {
      "twenty " + numsMap(num % 20)
    } else {
      numsMap(num)
    }
  }
}
