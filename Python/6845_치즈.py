import sys
from collections import deque

def input_data():
    readl = sys.stdin.readline
    R, C = map(int, readl().split())
    map_ch = [list(map(int, readl().split())) for _ in range(R)]
    return R, C, map_ch   

sol_hour, sol_last_cnt_ch = 0,0
# 입력받는 부분
R, C, map_ch = input_data()

# 여기서부터 작성
dr = [-1,1,0,0]
dc = [0,0,-1,1]

def BFS():
    visited = [[0] * C for _ in range(R)]
    q = deque()
    q.append([0,0])

    remove_cnt = 0
    while q:
        cr, cc = q.popleft()
        for i in range(4):
            nr = cr + dr[i]
            nc = cc + dc[i]
            if 0 <= nr < R and 0 <= nc < C:
                if visited[nr][nc] == 0:
                    visited[nr][nc] = 1
                    if map_ch[nr][nc] == 0:
                        q.append([nr,nc])
                    elif map_ch[nr][nc] == 1:
                        map_ch[nr][nc] = 2
                        remove_cnt += 1
    return remove_cnt

total_cheeze = 0
for i in range(R):
    for j in range(C):
        if map_ch[i][j] == 1:
            total_cheeze += 1

while True:
    sol_hour += 1
    remove_cnt = BFS()
    if total_cheeze - remove_cnt == 0:
        sol_last_cnt_ch = remove_cnt
        break
    total_cheeze -= remove_cnt

    for i in range(R):
        for j in range(C):
            if map_ch[i][j] == 2:
                map_ch[i][j] = 0

# 출력하는 부분
print(sol_hour, sol_last_cnt_ch, sep='\n')