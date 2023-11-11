
# 이분탐색? 아닌데.
# 만들 수 있는 개수를 갱신해 가면서 만들어 나가기..?
# DFS?


def DFS(total):
    if total > M:
        return
    
    possible_make = 50000000
    global maxV
    for i in range(N):
        possible_make = min(possible_make, having_cnt[i] // info[i][0])
    
    if maxV < possible_make:
        maxV = possible_make

    for i in range(N):
        for j in range(2):
            # j = 0 -> 작은 포장, j = 1 -> 큰 포장 구매
            # 구매시 가능한 식사 준비량 넘기기.
            buy_cnt[i][j] += 1
            having_cnt[i] += info[i][j*2 + 2]
            DFS(total + info[i][j*2+3])
            buy_cnt[i][j] -= 1
            having_cnt[i] -= info[i][j*2 + 2]

N,M = map(int,input().split())
info = [list(map(int,input().split())) for _ in range(N)]
buy_cnt = [[0,0] for _ in range(N)]
having_cnt = [0] * N
for i in range(N):
    having_cnt[i] = info[i][1]

maxV = 0
DFS(0)
print(maxV)
