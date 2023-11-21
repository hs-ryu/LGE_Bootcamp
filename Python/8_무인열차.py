# 각 점에서 BFS 렛츠고

import sys
from collections import deque
from pprint import pprint

dr = [-1,1,0,0]
dc = [0,0,-1,1]

def input_data():
	readl = sys.stdin.readline
	R, C = map(int, readl().split())
	map_line = [list(map(int,input().split())) for _ in range(R)]
	return R, C, map_line

def change_map(r, c, num):
	q = deque()
	q.append([r,c])
	map_line[r][c] = num
	visited[r][c] = 1
	while q:
		cr, cc = q.popleft()
		for i in range(4):
			nr = cr + dr[i]
			nc = cc + dc[i]
			if 0 <= nr < R and 0 <= nc < C and map_line[nr][nc] == 1 and visited[nr][nc] == 0:
				map_line[nr][nc] = num
				visited[nr][nc] = 1
				q.append([nr,nc])

def BFS(r,c):
	q = deque()
	q.append([r,c])
	visited[r][c] = 0

	minVal = 1000000000
	while q:
		cr, cc = q.popleft()
		for i in range(4):
			nr = cr + dr[i]
			nc = cc + dc[i]
			if 0 <= nr < R and 0 <= nc < C and visited[nr][nc] == 0:
				visited[nr][nc] = visited[cr][cc] + 1
				if map_line[nr][nc] == 0:
					q.append([nr,nc])
				elif map_line[nr][nc] == 2:
					minVal = min(minVal, visited[cr][cc])
	return minVal
sol = -1
# 입력받는 부분
R, C, map_line = input_data()


visited = [[0] * C for _ in range(R)]
# 여기서부터 작성
num = 1
for i in range(R):
	for j in range(C):
		if map_line[i][j] == 1 and visited[i][j] == 0:
			change_map(i,j,num)
			num += 1
if num == 2:
	print(0)
else:
	minV = 1000000000
	for i in range(R):
		for j in range(C):
			if map_line[i][j] == 1:
				visited = [[0] * C for _ in range(R)]
				k = BFS(i,j)
				minV = min(minV, k)
	print(minV)
			

# 출력하는 부분

