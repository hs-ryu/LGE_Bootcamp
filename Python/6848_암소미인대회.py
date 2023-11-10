from collections import deque
from pprint import pprint

N,M = map(int,input().split())
pre = [list(input()) for _ in range(N)]
arr = [[0] * M for _ in range(N)]

dr = [-1,1,0,0]
dc = [0,0,-1,1]

pre_visited = [[0] * M for _ in range(N)]
visited = [[0] * M for _ in range(N)]

count = [[0, 2500, 2500, 2500],[2500, 0, 2500, 2500],[2500, 2500, 0, 2500],[2500, 2500, 2500, 0]]

result = 7500

def change(r,c,id):
    q = deque()
    q.append([r,c])
    pre_visited[r][c] = 1
    arr[r][c] = id

    while q:
        cr, cc = q.popleft()
        for i in range(4):
            nr = cr + dr[i]
            nc = cc + dc[i]
            if 0 <= nr <  N and 0 <= nc <  M:
                if pre[nr][nc] == 'X' and pre_visited[nr][nc] == 0:
                    q.append([nr,nc])
                    arr[nr][nc] = id
                    pre_visited[nr][nc] = 1

def BFS1(r,c,id):
    q = deque()
    q.append([r,c])

    while q:
        cr, cc = q.popleft()
        for i in range(4):
            nr = cr + dr[i]
            nc = cc + dc[i]
            if 0 <= nr <  N and 0 <= nc <  M:
                if visited[nr][nc] == 0 and arr[nr][nc] != id:
                    if arr[nr][nc] == 0:
                        q.append([nr,nc])
                        visited[nr][nc] = visited[cr][cc] + 1
                    else:
                        if count[id][arr[nr][nc]] > visited[cr][cc]:
                            count[id][arr[nr][nc]] = visited[cr][cc]

def BFS2(r,c):
    q = deque()
    q.append([r,c])
    visited[r][c] = 1
    one_point_count = [0, 2500, 2500, 2500]
    while q:
        cr, cc = q.popleft()
        for i in range(4):
            nr = cr + dr[i]
            nc = cc + dc[i]
            if 0 <= nr <  N and 0 <= nc <  M:
                if visited[nr][nc] == 0:
                    if arr[nr][nc] == 0:
                        q.append([nr,nc])
                        visited[nr][nc] = visited[cr][cc] + 1
                    else:
                        if one_point_count[arr[nr][nc]] > visited[cr][cc]:
                            one_point_count[arr[nr][nc]] = visited[cr][cc]
    k = 0
    for i in range(1,4):
        if one_point_count[i] == 2500:
            return 7500
        k += one_point_count[i]
    return k-2

id = 1
for i in range(N):
    for j in range(M):
        if pre[i][j] == 'X':
            if pre_visited[i][j] == 0:
                change(i,j,id)
                id += 1

for i in range(N):
    for j in range(M):
        if arr[i][j] != 0:
            BFS1(i,j,arr[i][j])
            visited = [[0] * M for _ in range(N)]
            
for i in range(1,4):
    total = 0
    for j in range(1,4):
        if i == j:
            continue
        total += count[i][j]
    if total <  result:
        result = total

for i in range(N):
    for j in range(M):
        if arr[i][j] == 0:
            k = BFS2(i,j)
            visited = [[0] * M for _ in range(N)]
            if k <  result:
                result = k
                        
print(result)