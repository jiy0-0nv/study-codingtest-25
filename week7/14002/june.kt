@file:JvmName("Week7_14002_June")

import java.lang.System
import java.util.Scanner


fun main() {
    val sc = Scanner(System.`in`)
    val N = sc.nextLine().toInt()
    val array = sc.nextLine().split(" ").map { it -> it.toInt() }

    val dp = MutableList<Int>(array.size, {0})
    val el = MutableList<Int>(array.size, {0})

    var longest_index = 0

    for (i in 0 until array.size ){
        var max: Int = 0
        var tempEl :Int = i
        for (j in 0 .. i){
            if ( array[i] > array[j] && dp[j] > max ) {
                max = dp[j]
                tempEl = j
            }
        }
        dp[i] = max +1
        el[i] = tempEl

        if(dp[longest_index] < max+1){
            longest_index = i
        }
    }

    // answer print ... 아주 비효율적이다
    println(dp[longest_index])
    var count = dp[longest_index]
    var printList = mutableListOf<Int>()
    while(count!=0){
        printList.add(array[longest_index])
        longest_index = el[longest_index]

        count--
    }
    printList.reverse()
    println( printList.joinToString(separator = " "))

}