#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> board;

int dp[50][50];
bool visited[50][50];         // 계산이 끝났는지 여부
bool inStack[50][50];         // 현재 경로에 포함되었는지 여부
bool infiniteLoop = false;    // 무한 루프 발견 여부

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int dfs(int y, int x) {
    if (infiniteLoop) return 0;
    if (board[y][x] == 'H') return 0;
    if (visited[y][x]) return dp[y][x];
    
    visited[y][x] = true;
    inStack[y][x] = true;
    
    int move = board[y][x] - '0';  // 정수 변환
    int best = 0;                  // 이후 가능한 최대 이동 횟수
    
    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir] * move;
        int nx = x + dx[dir] * move;

        // 보드 밖을 벗어날 경우 해당 방향 무시
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        
        // 만약 다음 칸이 현재 DFS 경로에 이미 포함되어 있으면 사이클 발생
        if (inStack[ny][nx]) {
            infiniteLoop = true;
            return 0;
        }
        
        // 다음 칸에서의 최대 이동 횟수를 재귀 호출로 구하고, 최댓값 기록
        best = max(best, dfs(ny, nx));
    }
    
    inStack[y][x] = false;        // 탐색 후 경로에서 제거
    dp[y][x] = best + 1;          // 현재 칸에서 한번 이동 + 이후 최대 이동 횟수
    return dp[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    board.resize(N);
    for (int i = 0; i < N; i++) cin >> board[i];
    
    int answer = dfs(0, 0);      // 왼쪽 상단에서 시작
    
    if (infiniteLoop) cout << -1 << "\n";
    else cout << answer << "\n";
    
    return 0;
}
