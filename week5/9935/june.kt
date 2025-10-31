fun main(){
    var s1 = readln()
    var s2 = readln()
    var len = s2.length
    val result = StringBuilder(s1.length)

    // 처음 string의 character 순회
    s1.forEach { char->
        // result string에 붙여가면서 이번 char이 s2의 마지막 char이고 길이가 더 길면
        result.append(char)
        if( char == s2[len-1] && result.length >= len  ){

            if( result.substring( result.length - len) == s2){ // match
                result.setLength( result.length - len)
                return@forEach
            }
        }
    }

    if(result.isEmpty()) println("FRULA")
    else println(result.toString())


}