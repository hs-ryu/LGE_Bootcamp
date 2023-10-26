
def find(sum, idx):
    
    global flag
    if flag == True:
        return
    if idx == N+1:
        return
    if sum == 0:
        flag = True
        return
    if sum > hab[N] - hab[idx-1]:
        return
    
    for i in range(idx, N):
        find(sum-A[i],i+1)

t = int(input())
for _ in range(t):
    N,K = map(int,input().split())
    A = list(map(int,input().split()))
    hab = [0] * (N)
    visited = [0] * N
    hab[0] = A[0]
    for i in range(1,N):
        hab[i] = hab[i-1] + A[i]
    hab = [0] + hab
    flag = False
    find(K,0)
    if flag:
        print("YES")
    else:
        print("NO")