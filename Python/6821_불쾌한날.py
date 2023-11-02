N = int(input())
C = [int(input()) for _ in range(N)]

stack = []

result = 0
for i in range(N):
    cnt = 0
    while stack and stack[-1] < C[i]:
        cnt += 1
        stack.pop()
    result += cnt
    stack.append(C[i])

# 1 (2)
# 3 (3)
# 6 (4)
# 10 (5)
# 15 (6)
# 21 (7)
# 28 (8)
# 36 (9)

for i in range(len(stack)):
    result += i

print(result)
