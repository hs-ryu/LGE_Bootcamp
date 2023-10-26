def DFS(sum, start, cnt):
    global minS
    if cnt == N:
        # 돌아오는 것 계산
        if maps[start][0] != 0:
            sum += maps[start][0]
            if sum < minS:
                minS = sum
        return
    if sum > minS:
        return
    
    for i in range(N):
        if visited[i] == 1 or maps[start][i] == 0:
            continue
        visited[i] = 1
        DFS(sum + maps[start][i], i, cnt+1)
        visited[i] = 0

N = int(input())
maps = [list(map(int,input().split())) for _ in range(N)]
minS = 12 * 100
visited = [0] * N

DFS(0, 0, 0)
print(minS)