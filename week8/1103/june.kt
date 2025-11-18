@file:JvmName("Week8_1103_June")

import kotlin.system.exitProcess

var N:Int = 0
var M:Int = 0

val dy = intArrayOf(-1,0,1,0)
val dx = intArrayOf(0,1,0,-1)
var max = 0
fun main(){
    """
    형택이는 1부터 9까지의 숫자와, 구멍이 있는 직사각형 보드에서 재밌는 게임을 한다.
    
    일단 보드의 가장 왼쪽 위에 동전을 하나 올려놓는다. 그다음에 다음과 같이 동전을 움직인다.
    
    동전이 있는 곳에 쓰여 있는 숫자 X를 본다.
    위, 아래, 왼쪽, 오른쪽 방향 중에 한가지를 고른다.
    동전을 위에서 고른 방향으로 X만큼 움직인다. 이때, 중간에 있는 구멍은 무시한다.
    만약 동전이 구멍에 빠지거나, 보드의 바깥으로 나간다면 게임은 종료된다. 형택이는 이 재밌는 게임을 되도록이면 오래 하고 싶다.
    
    보드의 상태가 주어졌을 때, 형택이가 최대 몇 번 동전을 움직일 수 있는지 구하는 프로그램을 작성하시오.
    
    입력
    줄에 보드의 세로 크기 N과 가로 크기 M이 주어진다. 이 값은 모두 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 보드의 상태가 주어진다. 쓰여 있는 숫자는 1부터 9까지의 자연수 또는 H이다. 가장 왼쪽 위칸은 H가 아니다. H는 구멍이다.
    
    출력
    첫째 줄에 문제의 정답을 출력한다. 만약 형택이가 동전을 무한번 움직일 수 있다면 -1을 출력한다.
    """

    val (n,m) = readln().split(" ").map { it -> it.toInt() }
    N = n
    M = m
    val a = Array(N) {IntArray(M)}
    val visited = Array(N) {BooleanArray(M)}
    val dp = Array(N) {IntArray(M)}


    for (i in 0 until  N){
        a[i] = readln()
            .map { if(it == 'H') -1 else it.digitToInt() }
            .toIntArray()
    }
    println(dfs(a,visited,dp,0,0))

}

fun dfs(a: Array<IntArray>, visited: Array<BooleanArray>, dp: Array<IntArray> , y:Int, x:Int): Int{
    visited[y][x] = true

    if(dp[y][x] != 0){
        return dp[y][x]
    }
    val mult = a[y][x]

    var best = 0
    for ( i in 0 .. 3){
        val ny = y + dy[i] * mult
        val nx = x + dx[i] * mult
        if( ny >= N || nx >= M || ny <0 || nx <0 || a[ny][nx] ==-1) continue
        if( visited[ny][nx] ){ // 지금 돌고 있는
                println(-1)
                exitProcess(0)
        }
        val next = dfs(a,visited,dp,ny,nx)
        if (best < next) best = next

        visited[ny][nx] = false // reset
    }
    dp[y][x] = best+1
    return dp[y][x]
}