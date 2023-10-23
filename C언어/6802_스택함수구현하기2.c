#include <stdio.h>
#define MAXN ((int)1e4)
int N;//명령개수
int cmd[MAXN + 10];
int a[MAXN + 10];

int stk[MAXN + 10];
int sp;
void push(int d){
    stk[sp] = d;
    sp++;
}
void pop(void) {
    sp--;
    stk[sp] = 0;
}
int top(void) {
    return stk[sp-1];
}
int empty(void) {
    return sp <= 0;
}
int size(void) {
    return top;
}
void Solve(void){
	sp = 0;//초기화
	for (int i=0; i<N; i++){
		switch(cmd[i]){
		case 0://읽고 제거
			if (empty()) {
				printf("E\n");
			}
			else{
				printf("%d\n", top());
				pop();
			}
			break;
		case 1://저장
			push(a[i]);
			break;
		default://2 : 저장 개수
			printf("%d\n", size());
		}
	}
}
void InputData(void){
	scanf("%d", &N);
	for (int i=0; i<N; i++){
		scanf("%d", &cmd[i]);
		if (cmd[i] == 1){
			scanf("%d", &a[i]);
		}
	}
}
int main(void){
	InputData();
	Solve();
	return 0;
}