import sys

def input_data():
    readl = sys.stdin.readline
    N, *list_height = map(int,readl().split())
    return N, list_height

stack = []
sol = []
while 1:
    # 입력받는 부분
    N, list_height = input_data()
    if N == 0: break

    ans = 0

    stack.append([0, list_height[0]])
    for i in range(1,N):
        nowI = i
        nowH = list_height[i]
        while (stack):
            topI, topH = stack[-1]
            if topH > nowH:
                stack.pop()
                ans = max(ans, topH * (nowI - topI))
                stack.append([topI, nowH])
            elif topH < nowH:
                stack.append([nowI,nowH])
                break
            else:
                break
        print(stack)
                
    print(ans)


