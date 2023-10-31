from collections import deque

dr = [-1,1,0,0]
dc = [0,0,-1,1]

def BFS1(r,c,color):
    q = deque()
    q.append([r,c])
    visited1[r][c] = 1

    while q:
        cr, cc = q.popleft()
        for i in range(4):
            nr = cr + dr[i]
            nc = cc + dc[i]
            if 0 <= nr < n and 0 <= nc < n:
                if visited1[nr][nc] == 0 and pixels[nr][nc] == color:
                    q.append([nr,nc])
                    visited1[nr][nc] = 1

def BFS2(r,c,color):
    q = deque()
    q.append([r,c])
    visited2[r][c] = 1

    if color == "R":
        colors = {"R", "G"}
    else:
        colors = {"B"}

    while q:
        cr, cc = q.popleft()
        for i in range(4):
            nr = cr + dr[i]
            nc = cc + dc[i]
            if 0 <= nr < n and 0 <= nc < n:
                if visited2[nr][nc] == 0 and pixels[nr][nc] in colors:
                    q.append([nr,nc])
                    visited2[nr][nc] = 1   

n = int(input())
pixels = [list(input()) for _ in range(n)]
visited1 = [[0] * n for _ in range(n)]
visited2 = [[0] * n for _ in range(n)]
ans1 = 0
ans2 = 0
for i in range(n):
    for j in range(n):
        if visited1[i][j] == 0:
            BFS1(i,j,pixels[i][j])
            ans1 += 1
        if visited2[i][j] == 0:
            BFS2(i,j,pixels[i][j])
            ans2 += 1

print(ans1, ans2)
