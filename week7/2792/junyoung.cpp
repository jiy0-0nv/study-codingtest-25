#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    vector<long long> jewels(M);
    long long maxJewel = 0;
    for (int i = 0; i < M; i++) {
        cin >> jewels[i];
        maxJewel = max(maxJewel, jewels[i]);
    }
    
    // 제일 많은 보석을 기준으로 탐색 범위를 (1~최대개수) 로 지정
    long long left = 1;
    long long right = maxJewel;
    long long answer = maxJewel;
    
    while (left <= right) {
        // 우리가 찾고자 하는 값 : mid (순차적으로 하지 않고 이분 탐색 진행)
        long long mid = (left + right) / 2;
        long long needed = 0;
        
        for (long long j : jewels) {
            // 모든 보석값에 대해 몇명이 필요한지 구하고, 해당 값의 총합 계산
            needed += (j + mid - 1) / mid;
            // 학생 수를 초과한다면 나가기
            if (needed > N) break;
        }
        
        if (needed <= N) {
            answer = mid;
            right = mid - 1; // 상한 낮춰서 진행
        } else { // 학생이 모자람
            left = mid + 1;  // 하한 높여서 진행
        }
    }
    
    cout << answer << "\n";
    return 0;
}
