#include <stdio.h>
#define MAXN (100)

#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif


int N, M;//재료종류수, 가진돈
int X[MAXN + 10];//1인분당 필요한 양
int Y[MAXN + 10];//주방에 있는 양
int Sm[MAXN + 10];//작은 포장 재료 양
int Pm[MAXN + 10];//작은 포장 가격
int Sv[MAXN + 10];//큰포장 재료 양
int Pv[MAXN + 10];//큰포장 가격

int maxV = 0;

void DFS(int total) {
    if (total > M) {
        return;
    }

    int possible_make = 50000000;
    for (int i = 0; i < N; i++) {
        possible_make = min(possible_make, Y[i] / X[i]);
    }

    if (maxV < possible_make) {
        maxV = possible_make;
    }

    for (int i = 0; i < N; i++) {
        Y[i] += Sm[i];
        DFS(total + Pm[i]);
        Y[i] -= Sm[i];
        
        Y[i] += Sv[i];
        DFS(total + Pv[i]);
        Y[i] -= Sv[i];
    }
}


void InputData(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d %d %d", &X[i], &Y[i], &Sm[i], &Pm[i], &Sv[i], &Pv[i]);
	}
}
int main(void) {
	int ans = -1;
	InputData();//입력 받는 부분

	//여기서부터 작성
    
    // 방법 1. 현재 금액으로 구매할 수 있는 경우의 수 구하기. 큰 포장, 작은 포장까지 모두 확인. -> 시간초과
    // DFS(0);

    // 방법 2. 이분탐색..?
	printf("%d\n", maxV);//출력 하는 부분
	return 0;
}