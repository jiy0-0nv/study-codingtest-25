#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <cmath> 
using namespace std;

int N, M;
vector<pair<int, int>> house; // 집 좌표 
vector<pair<int, int>> chicken; // 치킨집 좌표 
vector<pair<int, int>> selected; // 현재 선택된 치킨집 좌표 
int answer = INT_MAX; // 최소 거리 초기화 

int get_city_distance() { // 치킨-집 거리 계산
    int total = 0;
    for (auto [hx, hy] : house) {
        int min_dist = INT_MAX;
        for (auto [cx, cy] : selected) {
            int dist = abs(hx - cx) + abs(hy - cy);
            min_dist = min(min_dist, dist);
        }
        total += min_dist; // 최소 거리 누적 
    }
    return total; // 전체 거리 
}

// 백트래킹 

void dfs(int start) { 
    if ((int)selected.size() == M) {
        answer = min(answer, get_city_distance());
        return; // M개면 최소 거리 갱신하고 종료 
    }

    for (int i = start; i < chicken.size(); i++) { 
        selected.push_back(chicken[i]);
        dfs(i + 1); // 재귀 호출 
        selected.pop_back(); // 모든 조합을 위한 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    vector<vector<int>> city(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> city[i][j];
            if (city[i][j] == 1) house.push_back({i, j});
            else if (city[i][j] == 2) chicken.push_back({i, j});
        }
    }

    dfs(0);
    cout << answer << "\n";
    return 0;
}
