
def DFS(idx, sum):
    global max_sum
    if sum > max_sum:
        return
    if idx == n:
        if sum < max_sum:
            max_sum = sum
        return
    
    for i in range(n):
        if visited[i]:
            continue
        visited[i] = 1
        DFS(idx+1, sum + maps[idx][i])
        visited[i] = 0
    



n = int(input())
maps = [list(map(int,input().split())) for _ in range(n)]
visited = [0] * n
max_sum = 100 * 10
DFS(0,0)
print(max_sum)