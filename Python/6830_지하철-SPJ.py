N,M = map(int,input().split())

jihacheol = [list(map(int,input().split())) for _ in range(N)]

# visited 만들어서, 갈 수 있는 거리 최소 값으로 갱신하면서 보면 될듯.
# N <= 100 -> N^2 = 10000

