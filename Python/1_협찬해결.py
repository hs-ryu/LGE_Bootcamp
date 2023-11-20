# 물품들 중 연속 3개 선택하여 선호도 최대
# 누적합?
# 누적합이긴 누적합인데, 누적합 결과가 음수가 나오는 경우는 다시 해당 수부터 집어넣는다 나이스
# 하면서 바로바로 결과값 갱신 렛츠고

# 물품 개수 N -> 3 <= 100,000
# 선호도 Di -> 10000 <= Di <= 10000

# 2중 loop -> 100000 * 100000 = 10,000,000,000 무조건 시간초과

# 누적합 만드는 부분 -> 최대 100,000


import sys

def input_data() :
	readl = sys.stdin.readline
	N = int(readl())#협찬 물품의 수
	D = list(map(int, readl().split()))#선호도 
	return N, D


def Solve():
    sol = -30001#첫번째 방법의 최대 선호도
    for i in range(1,N+1):
        if hab[i-1] >= 0:
            hab[i] = D[i-1] + hab[i-1]
        else:
            hab[i] = D[i-1]
        if hab[i] > sol:
            sol = hab[i]
    return sol

#입력받는 부분
N, D = input_data()
hab = [0] * (N+1)
sol = Solve()
print(sol)#출력하는 부분
