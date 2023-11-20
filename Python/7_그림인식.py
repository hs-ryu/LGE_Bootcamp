# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
import sys
from collections import deque

dr = [-1,1,0,0]
dc = [0,0,-1,1]

def input_data():
	readl = sys.stdin.readline
	N = int(readl())
	map_pic = [list(map(int, readl().strip())) for _ in range(N)]
	return N, map_pic


def BFS(r,c):
	q = deque()
	q.append([r,c])
	visited[r][c] = 1
	
	while q:
		cr, cc = q.popleft()
		for i in range(4):
			nr = cr + dr[i]
			nc = cc + dc[i]
			if 0 <= nr < N and 0 <= nc < N and visited[nr][nc] == 0:
				visited[nr][nc] = 1
				q.append([nr,nc])
				
				
	
	

sol = -1
# 입력받는 부분
N, map_pic = input_data()


exist_nums = [0] * 10
hider = [0] * 10

# 각각의 색을 BFS로 돌린다고 했을때
# 1. 만약 영역이 2개 이상 발생 시 덧칠 당한 것.
# 2. 만약 직사각형의 크기가 아닌 경우 덧칠 당한 것.

# 아니면, 사각형의 영역을 구하고,
# 사각형의 영역 내에 있는 다른 색들을 구하고
# 속하지 않는 색들만 구한다.

# 각 색깔의 꼭지점들을 구한다.
for num in range(1, 10):
	t, b, l, r = 10, -1, 10, -1
	for i in range(N):
		for j in range(N):
			if map_pic[i][j] == num:
				exist_nums[num] = 1
				if t > i:
					t = i
				if b < i:
					b = i
				if l > j:
					l = j
				if r < j:
					r = j
	for i in range(t,b+1):
		for j in range(l, r+1):
			if map_pic[i][j] != num:
				hider[map_pic[i][j]] = 1

not_hider_cnt = 0
for i in range(1,10):
	if exist_nums[i]:
		not_hider_cnt += 1
	if hider[i]:
		not_hider_cnt -= 1
	# 사각형의 범위가 나왔다면
	# 사각형의 범위로 반복문을 돌리면서 내부에 있는 다른 사각형을 찾는다.
	

# 출력하는 부분
print(not_hider_cnt)
