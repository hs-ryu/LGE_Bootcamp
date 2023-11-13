
# 만들 수 있는 개수를 갱신해 가면서 만들어 나가기..?
# DFS? 시간초과
# 이분탐색 -> 만들 수 있는 개수를 탐색하자
# 만들 수 있는 개수 -> 1 ~ 100000

N,M = map(int,input().split())
X = [0] * 101
Y = [0] * 101
Sm = [0] * 101
Pm = [0] * 101
Sv = [0] * 101
Pv = [0] * 101

for i in range(N):
    X[i], Y[i], Sm[i], Pm[i], Sv[i], Pv[i] = map(int,input().split())

result = 0


l = 0
r = 100000

while l <= r:
    # middle : 만들 수 있는 개수
    middle = (r + l) // 2

    need_money = 0

    # 필요한 양을 살 수 있는 최소 비용? 작은애들 먼저? 
    # 반복문 -> 작은 애들로만 채웠을때 -> 작은 애들을 하나씩 줄이면서 큰 애들을 넣어주기?
    # 모든 재료들이 middle개 만들 수 있는 상태가 되어야한다.
    # Y + Yplus // X[i] == 50000
    # 8 + x // 10 == 50000
    # x = middel * X[i] - Y[i]
    
    # 작은 팩과 큰 팩을 사는 것 중 어느 것을 사는게 더 이득인가?
    for i in range(N):
        need = middle * X[i] - Y[i]
        min_money = 1000000
        # 작은 팩으로 하나씩 늘려가면서, 큰 팩으로 몇개 사야하는지 확인.

        # middle = 23 만들어야함
        # need = 222개
        # small의 범위 -> 0 ~ 23
        # temp_money = 

        
        for small in range(need // Sm[i] + 1):
            temp_money = small * Pm[i]
            more_need = need - Sm[i] * small
            big = more_need // Sv[i]

            if more_need % Sv[i]:
                big += 1
            
            temp_money += big * Pv[i]

            if min_money > temp_money:
                min_money = temp_money

        need_money += min_money
    
    # middle만큼 만드는데 필요한 돈이 현재 가지고 있는 금액보다 크다면 -> r 하향
    # 작다면 -> l 상향, result 갱신
    if need_money > M:
        r = middle - 1
    elif need_money < M:
        l = middle + 1
        result = middle
    else:
        result = middle
        break
print(result)
