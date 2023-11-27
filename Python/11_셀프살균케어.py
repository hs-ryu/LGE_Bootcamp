# 가능한 모든 크기를 만든다.
# 해당 크기 별로 배열을 돌면서 확인한다?
# 근데, N이 10000 * 10000 배열이라, 여러번 돌면 안될듯
# 그럼 한번씩?

import sys


def input_data():
	readl = sys.stdin.readline
	N, L, M = map(int, readl().split())
	list_pos = [tuple(map(int, readl().split())) for _ in range(M)]
	return N, L, M, list_pos


sol = -1
# 입력받는 부분
N, L, M, list_pos = input_data()

# 여기서부터 작성


# 출력하는 부분
print(sol)
