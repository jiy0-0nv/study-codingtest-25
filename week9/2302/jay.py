n = int(input())
m = int(input())

vip = set(int(input()) for _ in range(m))

dp = [0] * 41
dp[0], dp[1] = 1, 1
for i in range(2, 41):
    dp[i] = dp[i-1] + dp[i-2]

answer = 1
cnt = 0  

for i in range(1, n+1):
    if i in vip:
        answer *= dp[cnt]
        cnt = 0
    else:
        cnt += 1

answer *= dp[cnt]  
print(answer)