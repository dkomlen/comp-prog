package main.scala

import scala.io.StdIn.readLine

object make_it_anagram {

  def main(args: Array[String]): Unit = {
    val (a, b) = (readLine(), readLine())
    val x = 2 * (if (a.length < b.length) a.diff(b) else b.diff(a)).length
    val y = Math.abs(a.length - b.length)
    println(x + y)
  }
}
