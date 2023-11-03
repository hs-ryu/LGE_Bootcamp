N = int(input())
C = [int(input()) for _ in range(N)]

stack = []

result = 0
for i in range(N):
    while stack and stack[-1] < C[i]:
        stack.pop()
    result += len(stack)
    stack.append(C[i])

# 1 (2)
# 3 (3)
# 6 (4)
# 10 (5)
# 15 (6)
# 21 (7)
# 28 (8)
# 36 (9)

print(result)
