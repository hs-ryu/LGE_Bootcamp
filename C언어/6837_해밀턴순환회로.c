#include <stdio.h>
#define MAXN (12)
int N;//대회수
int A[MAXN+10][MAXN+10];//[출발][도착]=항공료
int minS = 12 * 100;
int visited[MAXN+10];
void DFS(int sum, int start, int cnt) {
    if (sum > minS) {
        return;
    }
    if (cnt == N-1) {
        // 다시 1번으로 돌아가야하니까 계산해주기
        if (A[start][0] != 0) {
            sum = sum + A[start][0];
            if (sum < minS) {
                minS = sum;
            }
        }
        
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i] || A[start][i] == 0) {
            continue;
        }
        visited[i] = 1;
        DFS(sum + A[start][i], i, cnt+1);
        visited[i] = 0;
    }
}

void InputData(void){
	scanf("%d", &N);
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			scanf("%d", &A[i][j]);
		}
	}
}

int main(void){
	InputData();//입력

    // 시작포인트 0번째
    visited[0] = 1;
	//여기서부터 작성
    DFS(0, 0, 0);

	printf("%d\n", minS);//출력
	return 0;
}