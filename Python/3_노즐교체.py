import sys

def input_data():
	readl = sys.stdin.readline
	n = int(readl())
	a = [list(map(int, readl().split())) for y in range(n)]
	return n, a


# 입력
# N : 장비에 장착된 노즐의 가로, 세로 개수
# A : 각 노즐의 오염도 정보
sol = -1
N, A = input_data()

# 코드를 작성하세요

# 출력
print(sol)
