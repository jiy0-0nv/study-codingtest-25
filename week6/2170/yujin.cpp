#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> lines(N);
    for (int i = 0; i < N; i++) {
        cin >> lines[i].first >> lines[i].second;
    }

    sort(lines.begin(), lines.end());
    int current_start = lines[0].first;
    int current_end = lines[0].second;

    int total_length = 0;

    for (int i = 1; i < N; i++) {
        int next_start = lines[i].first;
        int next_end = lines[i].second;

        if (next_start <= current_end) {  // 겹치는 경우, 구간의 끝을 확장
            current_end = max(current_end, next_end);
        } else {
            total_length += current_end - current_start;  // 겹치지 않는 경우, 길이 업데이트
            current_start = next_start;
            current_end = next_end;
        }
    }

    // 마지막 구간의 길이 더하기
    total_length += current_end - current_start;

    cout << total_length << '\n';

    return 0;
}
