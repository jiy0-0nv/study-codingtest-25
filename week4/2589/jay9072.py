from collections import deque

n, m = map(int, input().split())
board = [list(input().strip()) for _ in range(n)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(x, y):
    q = deque([(x, y, 0)])
    visited = [[False]*m for _ in range(n)]
    visited[x][y] = True
    max_d = 0
    while q:
        x, y, d = q.popleft()
        max_d = max(max_d, d)
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny] and board[nx][ny] == 'L':
                visited[nx][ny] = True
                q.append((nx, ny, d + 1))
    return max_d

ans = 0
for i in range(n):
    for j in range(m):
        if board[i][j] == 'L':
            ans = max(ans, bfs(i, j))
print(ans)
