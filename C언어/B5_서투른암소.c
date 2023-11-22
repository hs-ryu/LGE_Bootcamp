#include <stdio.h>

char str[100000+10];
void InputData(void){
    scanf("%s", str);
}

char stack[100010];
int sp;

void push() {
    stack[sp] = "{";
    sp++;
}

int pop() {
    sp--;
    return stack[sp];
}

int isEmpty() {
    return sp == 0;
}


int main(void){
    int ans = 0;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    for (int i = 0; i < 100010; i++) {
        if (str[i] == '\0') { break; }

        if (str[i] == '(') {
            push();
        }
        else {
            if (isEmpty()) {
                ans++;
                push();
            } else {
                pop();
            }
        }
    }

    if (!isEmpty()) {
        ans += sp / 2;
    }
    printf("%d\n", ans);// 출력하는 부분
    return 0;
}