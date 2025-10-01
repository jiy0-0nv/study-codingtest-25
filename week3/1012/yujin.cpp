#include <iostream>
#include <vector>
using namespace std;

int M, N, K;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y, vector<vector<int>>& field, vector<vector<bool>>& visit, vector<vector<int>>& cab) {
    visit[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
            if (field[ny][nx] == 1 && !visit[ny][nx]) {
                dfs(nx, ny, field, visit, cab);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    cin >> T;
    while (T--) {
        cin >> M >> N >> K;

        vector<vector<int>> field(N, vector<int>(M, 0));
        vector<vector<bool>> visit(N, vector<bool>(M, 0));
        vector<vector<int>> cab(K, 2);
        for (int i = 0; i < K; i++) {
            int X, Y;
            cin >> X >> Y;
            field[Y][X] = 1;
            cab[i][0] = X;
            cab[i][1] = Y;
        }

        int count = 0;
        int x, y;
        for (int i = 0; i < K; i++) {
            x = cab[i][0];
            y = cab[i][1];
            if (!visit[y][x]) {
                count++;
                dfs(x, y, field, visit, cab);
            }
        }
        cout << count << '\n';
    }
}
