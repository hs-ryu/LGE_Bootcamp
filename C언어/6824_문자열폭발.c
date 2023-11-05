// 스택으로 지워가고, 다 돌았을 때 남은 스택을 앞에서부터 읽으면..?
// 하.. strlen 쓰니까 시간 초과나서 안되넹...
// 그냥 반복문 돌려서 길이 계산함...
#include <stdio.h>

#define MAXN ((int)1e6)
#define MAXB (36)
char str[MAXN + 10];
char boom[MAXB + 10];
char stack[MAXN + 10];
char temp[MAXB+10];
int sp;

// 4
// 0
// 5
// 1
// 4
// 0

void push(char x) {
    stack[sp] = x;
    sp++;
}

void pop() {
    sp--;
}

int isEmpty() {
    return (sp==0);
}

void InputData(void) {
	scanf("%s", str);
	scanf("%s", boom);
}
int main(void) {
	InputData();
	int boomLength = 0;
    for (int i = 0; i < MAXN; i++) {
        if (boom[i] == '\0') {
            break;
        }
        boomLength++;
    }

    int strLength = 0;
    for (int i = 0; i < MAXN; i++) {
        if (str[i] == '\0') {
            break;
        }
        strLength++;
    }

    for (int i = 0; i < strLength; i++) {
        push(str[i]);
        if (sp < boomLength) {
            continue;
        }
        else {
            int j = 0;
            int flag = 1;
            while (j < boomLength) {
                char boomTemp = boom[j];
                char stackTemp = stack[sp - boomLength + j];
                if (boomTemp != stackTemp){
                    flag = 0;
                    break;
                }
                j++;
            }
            if (flag) {
                for (int k = 0; k < boomLength; k++) {
                    pop();
                }
            }
        }
    }
    if (isEmpty()) {
        char result[5] = "FRULA";
        printf("%s", result);
    } else {
        char result[MAXN];
        for (int i = 0; i < sp; i++) {
            result[i] = stack[i];
        }
        printf("%s", result);
    }
	return 0;
}