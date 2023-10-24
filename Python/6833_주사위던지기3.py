N,M = map(int,input().split())

sel = [0] * N
check = [0] * 7
nums = [i for i in range(1,7)]

# M=1 -> 중복 순열
# 0 0 0
# 1 0 0
# 1 1 0
# 1 1 1
# 1 1 0
# 1 1 2
# ....
def solve1(level):
    if level == N:
        print(*sel)
        return
    for num in nums:
        sel[level] = num
        solve1(level+1)
        sel[level] = 0


# M=2 -> 중복 조합
# 1 1 1
# 1 1 2
# 1 1 3
# 1 2 2
# 1 2 3
# 2 2 2
# 2 2 3
# 2 3 3
# 3 3 3
def solve2(level,idx):
    if level == N:
        print(*sel)
        return
    
    for i in range(idx,len(nums)):
        sel[level] = nums[i]
        solve2(level+1,i)
        sel[level] = 0
    

# M=3 -> 순열
def solve3(level):
    if level == N:
        print(*sel)
        return
    for num in nums:
        if check[num] == 1:
            continue
        sel[level] = num
        check[num] = 1
        solve3(level+1)
        sel[level] = 0
        check[num] = 0


solve2(0,0)