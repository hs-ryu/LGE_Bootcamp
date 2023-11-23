#include <stdio.h>
#include <stdlib.h>

int N, C, M;
int state[10000+10];

typedef struct{
    int s;
    int e;
    int cnt;
} BOX;

BOX A[10000 + 10];
 
int comp (const void *a, const void *b) {
    BOX x = *(BOX *)a;
    BOX y = *(BOX *)b;
    if (x.e == y.e) {
        return x.s - y.s;
    }
    return x.e - y.e;
}

void InputData(void){
    scanf("%d %d", &N, &C);
    scanf("%d", &M);
    for (int i=0; i<M; i++){
        scanf("%d %d %d", &A[i].s, &A[i].e, &A[i].cnt);
    }
}


int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

int main(void){
    int ans = -1;

    InputData();// 입력받는 부분
    qsort(A, M, sizeof(A[0]), comp);
    // 여기서부터 작성
    int send = 0;
    for (int i = 0; i < M; i++) {
        int s = A[i].s;
        int e = A[i].e;
        int boxCnt = A[i].cnt;
        
        int maxV = 0;
        for (int idx = s; idx < e+1; idx++) {
            maxV = max(maxV, state[idx]);
        }
        // 보낼 수 있는 양
        int possibleBoxCnt = min(C - maxV, boxCnt);
        send += possibleBoxCnt;
        
        for (int idx = s; idx < e; idx++) {
            state[idx] += possibleBoxCnt;
        }
    }

    printf("%d\n", send);// 출력하는 부분
    return 0;
}