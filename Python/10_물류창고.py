# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
import sys
from collections import deque
from pprint import pprint

def input_data():
	readl = sys.stdin.readline
	N, M = map(int, readl().split())
	infos = [list(map(int, readl().split())) for _ in range(M)]
	return N, M, infos

sol = 1000001

def BFS(idx):
	visited[0] = 0
	visited[idx] = 0
	q = deque()
	q.append(idx)
	maxV = 0
	
	while q:
		now_city = q.popleft()
		for next_city in loads[now_city]:
			if visited[next_city] >= visited[now_city] + map_info[now_city][next_city]:
				visited[next_city] = visited[now_city] + map_info[now_city][next_city]
				q.append(next_city)
	# print(visited)
	return max(visited)


# 입력받는 부분
N, M, infos = input_data()

# 여기서부터 작성
map_info = [[10001] * (N+1) for _ in range(N+1)]
loads = [[] for _ in range(N+1)]
for i in range(M):
	now_info = infos[i]
	map_info[now_info[0]][now_info[1]] = now_info[2]
	map_info[now_info[1]][now_info[0]] = now_info[2]
	loads[now_info[0]].append(now_info[1])
	loads[now_info[1]].append(now_info[0])
# pprint(loads)

# 출력하는 부분
for i in range(1,N):
	visited = [1000000] * (N+1)
	k = BFS(i)
	sol = min(sol, k)

print(sol)
