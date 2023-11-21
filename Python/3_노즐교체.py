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

# 열에서 1가지 경우
# 홀짝 or 짝홀을 정하는 경우

# 행에서 1가지 경우
# 홀짝 or 짝홀을 정하는 경우

# 열로 먼저 확인
temp1 = 0
temp2 = 0
better_result1 = 0
for c in range(N):
	for r in range(N):	
		# 홀수번 노즐만 채택하는 경우
		if r % 2:
			temp1 += A[r][c]
		# 짝수번 노즐만 채택하는 경우
		else:
			temp2 += A[r][c]
	better_result1 += max(temp1, temp2)
	temp1, temp2 = 0, 0

	
# 행에서도 마찬가지
# 
temp1 = 0
temp2 = 0
better_result2 = 0
for r in range(N):
	for c in range(N):
		# 홀수번 노즐만 채택하는 경우
		if c % 2:
			temp1 += A[r][c]
		# 짝수번 노즐만 채택하는 경우
		else:
			temp2 += A[r][c]

	better_result2 += max(temp1, temp2)
	temp1 = 0
	temp2 = 0

sol = max(better_result1, better_result2)

# 출력
print(sol)
