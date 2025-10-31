#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    int n, pay, day;

    cin >> n;
    vector<pair<int, int>> a;

    while (n--) {
        cin >> pay >> day;
        //
        // 1. 앞 날짜부터 오늘 가능한거에서 가장 높은걸 선택 -> 뒤로 미룰 수 있는데 미리 땡겨쓸수도 있다
        // 2. 뒤 날짜부터 높은거? 이상
        // 3. 날짜 오름차순 돈 내림차순 정렬한다. 다음걸로 가면서, 내가 갖고 있는 애들의 최소보다 크면 먹는다.

        a.push_back({day, pay});
    }

    // auto comp = [](pair<int, int> a, pair<int, int> b) {
    //     return
    // }
    sort(a.begin(), a.end());

    for (auto &my_pair : a) {

        if (my_pair.first > pq.size()) { // pq 들어있는 개수보다 내 날짜가 크면 받음.
            pq.push(my_pair.second);    // 돈 넣기 ( 날짜 안 넣어도 됨)
        } 
        else {
            if (pq.top() < my_pair.second) {
                pq.pop();
                pq.push(my_pair.second);
            }
        }
        
    }

    // print하는 로직
    int sum = 0;
    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
    }

    cout << sum << '\n';

    return 0;
}