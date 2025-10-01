#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    vector<string> maze(N);
    vector<vector<int>> dist(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        cin >> maze[i];
    }

    queue<pair<int, int>> q;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    q.push({0, 0});
    dist[0][0] = 1;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        int cur_x = current.first;
        int cur_y = current.second;

        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
                if (maze[next_x][next_y] == '1' && dist[next_x][next_y] == 0) {
                    dist[next_x][next_y] = dist[cur_x][cur_y] + 1;
                    q.push({next_x, next_y});
                }
            }
        }
    }

    cout << dist[N-1][M-1] << '\n';
    return 0;
}
