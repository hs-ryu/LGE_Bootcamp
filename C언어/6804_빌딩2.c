#include <stdio.h>
#define MAXN ((int)1e5)
int N;//빌딩수
int H[MAXN+10];//빌딩높이
int sol[MAXN+10];//각 빌딩에서 보이는 빌딩 번호

int stack[MAXN+10];
int spoint;

void push(int k) {
    stack[spoint] = k;
    spoint++;
}

void pop(void) {
    spoint--;
}

int empty(void) {
    return spoint == 0;
}

int top(void) {
    return stack[spoint-1];
}


void InputData(void) {
	scanf("%d", &N);
	for (int i=1; i<=N; i++){
		scanf("%d", &H[i]);
	}
}
void OutputData(void) {
	for (int i=1; i<=N; i++){
		printf("%d\n", sol[i]);
	}
}

int main(void) {
	InputData();//입력받는 부분
	
    // 3, 2, 6, 1, 1, 2
    // 1, 2, 3, 4, 5, 6
	//여기서부터 작성
	for (int i=1; i<=N; i++) {
	    while (!empty() && H[top()] < H[i]) {
	        sol[top()] = i;
	        pop();
	    }
	    push(i);
	}
	
	
	OutputData();//출력하는 부분
	return 0;
}