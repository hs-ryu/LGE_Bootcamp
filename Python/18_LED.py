import sys

def input_data():
	readl = sys.stdin.readline
	N = int(readl())
	led = readl().split()
	return N, led

sol = 0
# 입력받는 부분
N, led = input_data()

# 여기서부터 작성
# 방법: N으로 끝내야함.
# 패턴이 형성되는 구간 나누기.
# 1번 패턴부터, M번 패턴까지 한번씩 순서를 바꿔가면서 
# 3개 연속 패턴이 발생하는 경우가 최대가 될 확률이 높음. 그 갚을 최대값과 비교하여 저장한다.

patterns = []

section_s = 0
section_e = 0
pre = led[0]
for i in range(1, N):
    if led[i] != pre:
        section_e = i
    else:
        patterns.append([section_s, section_e])
        sol = max(sol, section_e - section_s + 1)
        section_s = i
        section_e = i
    pre = led[i]
patterns.append([section_s, section_e])
sol = max(sol, section_e - section_s + 1)
# print(patterns)

if len(patterns) > 1:
    # 섹션 하나하나 선택하여, 순서 바꾸기
    for i in range(len(patterns)):
        # 1번, -1번 섹션은 2번, -2번 섹션과만 연산한다.
        pre_pattern = led[patterns[i-1][0] : patterns[i-1][1] + 1]
        now_pattern = led[patterns[i][0] : patterns[i][1] + 1]
        now_pattern = list(reversed(now_pattern))
        if i == 0:
            next_pattern = led[patterns[i+1][0] : patterns[i+1][1] + 1]
            total_patterns = now_pattern + next_pattern
        elif i == len(patterns) - 1:
            total_patterns = pre_pattern + now_pattern
        else:
            next_pattern = led[patterns[i+1][0] : patterns[i+1][1] + 1]
            total_patterns = pre_pattern + now_pattern + next_pattern
        print(total_patterns)
        
        cnt = len(total_patterns)
        sol = max(sol, cnt)

# 출력하는 부분
print(sol)
