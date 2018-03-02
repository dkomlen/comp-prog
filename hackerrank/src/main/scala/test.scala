import scala.collection.mutable
// (String, int) ->


object test {

  def ngram(word: String, n: Int): String = {
    val ngrams = word.sliding(n).toList

    var max = 0
    var result = ""
    val occurances = new mutable.HashMap[String, Int]

    for (ngram <- ngrams) {
      if (occurances.contains(ngram)) {
        occurances(ngram) = occurances(ngram) + 1
      } else {
        occurances.put(ngram, 1)
      }
      if (occurances(ngram) > max) {
        max = occurances(ngram)
        result = ngram
      }
    }

    result
  }

  def main(args: Array[String]): Unit = {
    println(ngram("eerengineeringing", 3))
  }
}
