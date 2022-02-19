fun main(){
    val input = readLine()!!.split(' ')

    val mA = input[0].replace('6', '5')
    val mB = input[1].replace('6', '5')
    val MA = input[0].replace('5', '6')
    val MB = input[1].replace('5', '6')

    val min = mA.toInt() + mB.toInt()
    val max = MA.toInt() + MB.toInt()

    println("$min $max")
}
