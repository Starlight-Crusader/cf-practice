fun main() {
    val t = readLine()!!.toInt()

    repeat(t) {
        val s = readLine()!!
        var ci: Int? = null

        for ((idx, char) in s.reversed().withIndex()) {
            if (char.isDigit() && char != '0') {
                ci = s.length - 1 - idx
                break
            } else if (char.isLetter()) {
                break
            }
        }

        if (ci != null) {
            println(s.substring(0, ci))
        }
    }
}
