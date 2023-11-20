# 물품들 중 연속 3개 선택하여 선호도 최대
# 

import sys

def input_data() :
	readl = sys.stdin.readline
	N = int(readl())#협찬 물품의 수
	D = list(map(int, readl().split()))#선호도 
	return N, D

def Solve():
	sol = -30001#첫번째 방법의 최대 선호도
	
    # 누적합?
    # 3, 1, -2, 5, -3
    # 3, 4, 2, 7, 4
    
    # -3, 2, 4, 5, -6, 3, 8
    # -3, -1, 3, 8, 2, 5, 13

	for i in range(0,N-2):
		t = sum(D[i:i+3])
		if(t > sol):
			sol = t
	return sol

#입력받는 부분
N, D = input_data()
sol = Solve()
print(sol)#출력하는 부분
