#include <stdio.h>
#define MAXN (100)
int N;
int sol[MAXN + 10];
int queue[MAXN * MAXN + 10];
int wpoint;
int rpoint;

void push(int x) {
    queue[wpoint] = x;
    wpoint++;
}

int pop(void) {
    int x = queue[rpoint];
    rpoint++;
    return x;
}

int top(void) {
    return queue[wpoint-1];
}

int empty(void) {
    return wpoint == rpoint;
}

void InputData(void){
    scanf("%d", &N);
}


void OutputData(void){
    for (int i=0; i<N; i++){
        printf("%d ", sol[i]);
    }
}


// 1번이 위, N번이 아래
// N번에 있는 카드 번호 / 2  -> pop(0) 해서 push
// pop(0) 해서 상대방에게 넘긴다.

int main(void){
    InputData();//입력
    //여기서부터 작성
    for (int i=1; i<=N; i++) {
        push(i);
    }
    
    int i = 0;
    while (i < N-1) {
        int cnt = top() / 2;
        while (cnt > 0) {
            int temp = pop();
            push(temp);
            cnt--;
        }
        int yours = pop();
        sol[i] = yours;
        i++;
    }
    sol[N-1] = pop();
    
    OutputData();//출력
    return 0;
}