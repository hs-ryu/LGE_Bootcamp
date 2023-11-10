from pprint import pprint

def make_game():
    k = 0
    for i in range(5):
        for j in range(i+1,6):
            games[k][0] = i
            games[k][1] = j
            k += 1

def DFS(level):
    global result
    if result == 1:
        return
    # 이미 가능한 경우가 있다면, 더 탐색할 필요 없음.
    if level == 15:
        result = 1
        return
    
    first, second = games[level]
    
    # 승패
    if info[first][0] and info[second][2]:
        info[first][0] -= 1
        info[second][2] -= 1
        DFS(level+1)
        info[first][0] += 1
        info[second][2] += 1
    # 무무
    if info[first][1] and info[second][1]:
        info[first][1] -= 1
        info[second][1] -= 1
        DFS(level+1)
        info[first][1] += 1
        info[second][1] += 1
    # 패승
    if info[first][2] and info[second][0]:
        info[first][2] -= 1
        info[second][0] -= 1
        DFS(level+1)
        info[first][2] += 1
        info[second][0] += 1

    
# 0 : 승, 1 : 무, 2 : 패

for _ in range(4):
    inputs = list(map(int,input().split()))
    info = []
    idx = 0
    for i in range(6):
        info.append(inputs[idx*3: idx*3+3][:])
        idx += 1

    flag = True
    for i in range(6):
        if info[i][0] + info[i][1] + info[i][2] != 5:
            flag = False
            break
    if not flag:
        print(0)
    
    else:
        games = [[0,0] for _ in range(15)]
        make_game()
        result = 0
        DFS(0)
        print(result)
        