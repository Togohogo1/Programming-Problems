fun main() {
    val a = readLine()!!.toInt()
    val b = readLine()!!.toInt()

    if (a <= 1)
        println("Before")
    else if (a == 2) {
        if (b < 18)
            println("Before")
        else if (b == 18)
            println("Special")
        else
            println("After")
    } else
        println("After")
}
