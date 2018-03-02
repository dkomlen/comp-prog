import scala.collection.mutable.ListBuffer
import scala.io.StdIn._

object Main {

  case class Node (
    id: Int,
    xs: Int,
    ys: Int,
    xe: Int,
    ye: Int,
    st: Int,
    et: Int
  )

  def main(args: Array[String]): Unit = {
    val Array(r, c, f, n, b, t) = readLine().split(" ").map(_.toInt)
    var nodes = ListBuffer[Node]()

    for (i <- 1 to n) {
      val Array(xs, ys, xe, se, ts, te) = readLine().split(" ").map(_.toInt)
      nodes.append(Node(i - 1, xs, ys, xe, se, ts, te))
    }

    val root = Node(-1, 0, 0, 0, 0, 0, 0)
    for (i <- 1 to f; if !nodes.isEmpty) {
      val sol = run(root, nodes)
      println(s"${sol.length} ${sol.map(_.id).mkString(" ")}")
      nodes = nodes.diff(sol)
    }
  }

  def run(node: Node, nodes: ListBuffer[Node], t: Int = 0): List[Node] = {
    val next = nodes.filter(n => t + dist(node, n) + dist(n, n) <= n.et).sortBy(n => -dist(n, n)).headOption
    next match {
      case None => Nil
      case Some(n) => n :: run(n, nodes.diff(List(n)), Math.max(t + dist(n, n), n.st))
    }
  }

  def dist(start: Node, end: Node) = {
    Math.abs(start.xe - end.xs) + Math.abs(start.ye - end.ys)
  }
}
