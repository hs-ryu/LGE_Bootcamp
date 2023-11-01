from pprint import pprint
from collections import deque

dr = [-1,1,0,0]
dc = [0,0,-1,1]

def BFS(r, c):
    q = deque()
    q.append([r,c])
    visited[r][c] = 1
    cnt = 0
    while q:
        cr,cc = q.popleft()
        for i in range(4):
            nr = cr + dr[i]
            nc = cc + dc[i]
            if 0 <= nr <= 100 and 0 <= nc <= 100 and maps[nr][nc] == 0:
                if visited[nr][nc] == 0:
                    q.append([nr,nc])
                    visited[nr][nc] = 1
                    for j in range(4):
                        nnr = nr + dr[j]
                        nnc = nc + dc[j]
                        if 0 <= nnr <= 100 and 0 <= nnc <= 100 and maps[nnr][nnc] == 1:
                            cnt += 1
    return cnt


n = int(input())
maps = [[0] * 101 for _ in range(101)]
visited = [[0] * 101 for _ in range(101)]
for _ in range(n):
    c,r = map(int, input().split())
    maps[r][c] = 1
result = BFS(0,0)
print(result)

