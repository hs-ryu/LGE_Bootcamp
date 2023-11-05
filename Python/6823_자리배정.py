from pprint import pprint

c,r = map(int,input().split())
k = int(input())

# 상, 우, 하, 좌
dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

maps = [[0] * c for _ in range(r)]
visited = [[0] * c for _ in range(r)]

if c * r < k:
    print(0)
else:
    # c = 7, r = 6 일때
    # 그림 : 실제 배열
    # (c,r) -> (r-j, c-1)
    # (1,1) -> (5,0)
    # (1,2) -> (4,0)
    # (1,3) -> (3,0)
    # (1,6) -> (0,0)

    # (7,6) -> (0,6)
    # (7,5) -> (1,6)
    # (7,4) -> (2,6)
    # (7,3) -> (3,6)

    # (2,1) -> (5,1)
    # (3,1) -> (5,2)
    # (4,1) -> (5,3)

    # i -> 1 ~ r
    # j -> 1 ~ c
    
    # [r-j][c-i]
    cr = r-1
    cc = 0
    direction = 0
    x = 1
    visited[cr][cc] = 1
    while x != k:
        nr = cr + dr[direction]
        nc = cc + dc[direction]
        if 0 <= nr < r and 0 <= nc < c and visited[nr][nc] == 0:
            x += 1
            visited[nr][nc] = x
            cr = nr
            cc = nc
        else:
            direction += 1
            if direction == 4:
                direction = 0
        
    # (0,5) -> 6,6
    # (2,6) -> 7,4
    # (0,6) -> 7,6

    # (r,c) -> (nc+1, r-nr)
    print(nc+1,r-nr)

    


        