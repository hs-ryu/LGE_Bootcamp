// 스택으로 지워가고, 다 돌았을 때 남은 스택을 앞에서부터 읽으면..?
#include <stdio.h>
#include <string.h>

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
	int boomLength = strlen(boom);
    int strLength = strlen(str);
    for (int i = 0; i < strLength; i++) {
        
        push(str[i]);
        if (strlen(stack) < boomLength) {
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
        char result[sp];
        for (int i = 0; i < sp; i++) {
            result[i] = stack[i];
        }
        printf("%s", result);
    }
	return 0;
}