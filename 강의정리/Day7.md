# 11/22 수업 정리

<br>

## 문제풀이

- 





## 연습문제 1 ()

- 

## 연습문제 2 ()

```c
// 시간초과 풀이
#include <stdio.h>
 
char str[100000+10];
char stack[100000+10];
int sp = 0;
 
void push(void) {
    stack[sp] = "(";
    sp++;
}
 
void pop(void) {
    sp--;
}
 
int isEmpty(void) {
    return sp == 0;
}
 
 
void InputData(void){
    scanf("%s", str);
}
 
int main(void){
    int ans = 0;
 
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
 
    for (int i = 0; str[i]; i++) {
        char bracket = str[i];
        if (bracket == '(') {
            str[i] = ')';
        } else {
            str[i] = '(';
        }
         
        int isPossible = 1;
        for (int k = 0; str[k]; k++) {
            if (str[k] == '(') {
                push();
            } else {
                if (!isEmpty()) {
                    pop();
                } else {
                    isPossible = 0;
                    break;
                }
            }
        }
        if (!isEmpty()) {
            isPossible = 0;
        }
        if (isPossible) {
            ans++;
        }
         
        sp = 0;
        str[i] = bracket;
    }
     
     
    printf("%d\n", ans);// 출력하는 부분
    return 0;
}
```











