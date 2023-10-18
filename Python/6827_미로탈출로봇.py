from collections import deque
from pprint import pprint
dr = [-1,1,0,0]
dc = [0,0,-1,1]

def BFS(r,c):
    q = deque()
    
    q.append([r,c])
    visited[r][c] = 1

    while q:
        cr,cc = q.popleft()
        for i in range(4):
            nr = cr + dr[i]
            nc = cc + dc[i]
            if 0 <= nr < R and 0 <= nc < C and miro[nr][nc] == '0':
                if visited[nr][nc] == 0:
                    q.append([nr,nc])
                    visited[nr][nc] = visited[cr][cc] + 1
                if nr == (er-1) and nc == (ec-1):
                    return


C,R = map(int,input().split())

sc,sr,ec,er = map(int,input().split())

miro = [list(input()) for _ in range(R)]
visited = [[0] * C for _ in range(R)]
BFS(sr-1,sc-1)

print(visited[er-1][ec-1] - 1)