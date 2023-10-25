
def find(sum):
    global flag
    if flag == True:
        return
    if sum > K:
        return
    if sum == K:
        flag = True
        return
    
    for i in range(N):
        if visited[i] == 1:
            continue
        visited[i] = 1
        find(sum+d[i])
        visited[i] = 0


t = int(input())
for _ in range(t):
    N,K = map(int,input().split())
    d = list(map(int,input().split()))
    visited = [0] * N

    flag = False
    find(0)
    if flag:
        print("YES")
    else:
        print("NO")