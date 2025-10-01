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
    for(int i=0; i<N; i++) cin >> maze(N);
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    vector<vector<int>> dist(N, vector<int>(M,0));
    queue<pair<int,int>> q;
    
    dist[0][0] = 1;
    q.push({0,0});
    
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        
        if (x == N-1 && y == M-1) break;
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < M){
                if(maze[nx][ny] == '1' && dist[nx][ny] == 0){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
    
    cout << dist[N-1][M-1] << '\n';
    
    return 0;
}
