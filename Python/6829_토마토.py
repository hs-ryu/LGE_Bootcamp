from collections import deque

dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

def BFS(k):
    Q = [start_point.pop() for _ in range(k)]
    while Q:
        cr, cc = Q.pop(0)
        for i in range(4):
            r = cr + dr[i]
            c = cc + dc[i]
            if 0 <= r < N and 0 <= c < M and visited[r][c] == 0:
                if tomato[r][c] == -1:
                    visited[r][c] = -1
                elif tomato[r][c] == 0:
                    Q.append([r,c])
                    tomato[r][c] = 1
                    visited[r][c] = visited[cr][cc] + 1

def dayday(visited):
    maxV = 0
    for i in range(N):
        for j in range(M):
            if visited[i][j] == -1:
                continue
            if visited[i][j] == 0:
                if tomato[i][j] == -1:
                    continue
                return -1
            elif visited[i][j] > maxV:
                maxV = visited[i][j]
    return maxV

M, N = map(int, input().split())

tomato = [list(map(int, input().split())) for _ in range(N)]
visited = [[0 for _ in range(M)] for _ in range(N)]
start_point = []

for i in range(N):
    for j in range(M):
        if tomato[i][j] == 1:
            start_point.append([i, j])
            visited[i][j] = 1
k = len(start_point)
BFS(k)
result = dayday(visited)
if result != -1:
    res = result-1
else:
    res = -1
print(res)