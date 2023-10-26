minS = 20 * 20 + 1
def DFS(sum, l, r, idx):
    global minS
    if sum > minS:
        return
    if idx == s:
        if sum < minS:
            minS = sum
        return
    
    # case1: 타겟 오른쪽에 열린 문이 둘 다 있는 경우 (왼쪽 문보다 작은 경우)
    # case2: 타겟 왼쪽 오른쪽에 열린 문이 양쪽으로 있는 경우 (왼쪽 문 < x < 오른쪽 문인 경우)
    # case3: 타겟 왼족에 열린 문이 둘 다 있는 경우 (오른쪽 문보다 큰 경우)

    # case1. 왼쪽 문 이용
    if target[idx] <= l:
        DFS(sum+abs(target[idx]-l), target[idx], r, idx+1)
    # case3. 오른쪽 문 이용
    elif target[idx] >= r:
        DFS(sum + abs(target[idx] - r), l, target[idx], idx+1)
    # case2. 왼쪽 문, 오른쪽 문 이용.
    else:
        DFS(sum+abs(target[idx]-l), target[idx], r, idx+1)
        DFS(sum + abs(target[idx] - r), l, target[idx], idx+1)
    
    # if target[idx] < r:
    #     DFS(sum + abs(target[idx] - l), target[idx], r, idx+1)
    # if target[idx] > l:
    #     DFS(sum + abs(target[idx] - r), l, target[idx], idx+1)



n = int(input())
open1, open2 = map(int,input().split())
s = int(input())
target = [int(input()) for _ in range(s)]
    
DFS(0, open1, open2, 0)

print(minS)