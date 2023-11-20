# 바이러스 



import sys

def InputData():
	readl = sys.stdin.readline
	N, M = map(int, readl().split())
	A = list(map(int, readl().split()))
	B = list(map(int, readl().split()))

	return N, M, A, B

def Find(start):
    A_split = sorted(A[start: start + M])
    diff_check = 0
    diff = A_split[0] - B[0]
    for i in range(M):
		# M이 5라면
        # B에서 0 ~ 4까지
        # A에서 s+0 ~ s + 4까지
        # 순서가 다르다? -> 배열 개수로 확인.
        # 어떤 일정한 값의 차이가 있다? 배열 개수 + 차이까지 다 본다.
        if A_split[i] != B[i]:
			# 다르더라도, 일정한 차이가 있을 수 있으니 차이를 보고 한번 더 체크해야지
            if A_split[i] - B[i] == diff:
                diff_check = 1
                continue
            return 0
        if diff_check:
            return 0
    # print(A_split, B)
    return 1

def Solve():
	sol = 0
	for i in range(N - M + 1):
		sol += Find(i)
	return sol

sol = 0

# 입력
# N: 실행 코드의 데이터 개수
# M: 바이러스의 데이터 개수
# A: 실행 코드의 데이터
# B: 바이러스의 데이터
N, M, A, B = InputData()

B.sort()

# 코드를 작성하세요
sol = Solve()

# 출력
print(sol)




# 28 37 39 42 63
# 3