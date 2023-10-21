from collections import deque

N,M = map(int, input().split())
R,C,S,K = map(int, input().split())

# BFS 렛츠고

# 갈 수 있는 방향
# 1시, 2시, 4시, 5시, 7시, 8시, 10시, 11시
dr = [-2, -1, 1, 2, 2, 1, -1, -2]
dc = [1, 2, 2, 1, -1, -2, -2, -1]

def BFS(sr,sc):
    
    visited[sr][sc] = 1
    q = deque()
    q.append([sr,sc])

    while q:
        cr, cc = q.popleft()

        for i in range(8):
            nr = cr + dr[i]
            nc = cc + dc[i]
            if 0 <= nr < N and 0 <= nc < M and visited[nr][nc] == 0:
                q.append([nr,nc])
                visited[nr][nc] = visited[cr][cc] + 1
                if nr == S-1 and nc == K-1:
                    return
visited = [[0] * M for _ in range(N)]
BFS(R-1, C-1)
print(visited[S-1][K-1] - 1)