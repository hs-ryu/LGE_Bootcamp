st = input()
target = input()

stack = []
# 스택으로 지워가고, 다 돌았을 때 남은 스택을 앞에서부터 읽으면..?

for i in range(len(st)):
    stack.append(st[i])
    if len(stack) < len(target):
        continue
    else:
        tempSt = "".join(stack[len(stack)-len(target):])
        if tempSt == target:
            for _ in range(len(target)):
                stack.pop()

result = "".join(stack)
print(result if len(result) else "FRULA")