#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<pair<int,int>> lecs;
    lecs.reserve(n);
    
    // 입력 -> (d, p) 형태로 저장
    for (int i = 0; i < n; i++) {
        int p, d;
        cin >> p >> d;
        lecs.emplace_back(d, p);
    }
  
    // d 기준 오름차순 정렬 (마감일 순으로 정렬하기 위함)
    sort(lecs.begin(), lecs.end());
    
    // greater<int> : 최소힙 설정 (∵ 가장 작은 값이 top()에 위치하여 제거에 용이하도록)
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // heap에 넣기 -> 선택한 강연수(minHeap의 개수)가 현재 강연 마감일(d)를 초과할 경우 -> 제거
    for (auto &[d, p] : lecs) {
        minHeap.push(p);
        if ((int)minHeap.size() > d) minHeap.pop();
    }
    
    long long ans = 0;
    while (!minHeap.empty()) {
        ans += minHeap.top();
        minHeap.pop();
    }
    
    cout << ans << '\n';
    return 0;
}
