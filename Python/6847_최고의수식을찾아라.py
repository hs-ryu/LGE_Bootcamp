N = int(input())
W = list(map(int,input().split()))
V = list(map(int,input().split()))
A = int(input())

check = [0] * 7
nums = [1,2,4,8,16,32,64]
result_check = [0] * 7

def DFS(level, total):
    if total > N:
        return
    if total == N:
        global max_v
        global result_check
        temp = 0
        for i in range(7):
            if check[i] < 5:
                temp += check[i] * W[i]
            else:
                temp += check[i] * V[i]

        k = 0
        for i in range(7):
            k += check[i]
        temp += A * k

        if temp > max_v:
            max_v = temp
            result_check = check[:]

    for i in range(level, 7):
        check[i] += 1
        DFS(i, total + nums[i])
        check[i] -= 1

max_v = 0
DFS(0, 0)
print(max_v)
print(*result_check)

