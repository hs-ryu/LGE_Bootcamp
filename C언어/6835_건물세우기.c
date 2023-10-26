#include <stdio.h>
#define MAXN (10)
int N;//빌딩개수(장소개수)
int A[MAXN+10][MAXN+10];//[빌딩][장소]=비용

int sel[MAXN+10];
int minS = 100 * 10;
void DFS(int sum, int idx) {
    if (idx == N+1) {
        if (minS > sum) {
            minS = sum;
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (sel[i]) {
            continue;
        }
        sel[i] = 1;
        DFS(sum + A[idx][i], idx+1);
        sel[i] = 0;
        
    }
    
    
}


void InputData(void){
	scanf("%d", &N);
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			scanf("%d", &A[i][j]);
		}
	}
}

int main(void){
	int ans = -1;
	InputData();//입력

	//여기서부터 작성
    DFS(0,1);
    
	printf("%d\n", minS);//출력
	return 0;
}