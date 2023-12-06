#include <stdio.h>
int W;//사용할 금액
int A[6];//각 동전 개수(갖고 있는)
int sol[6];//답
int m[6] = {500, 100, 50, 10, 5, 1};

int k[6601];
void InputData(void){
	scanf("%d", &W);
	for (int i=0; i<6; i++){
		scanf("%d", &A[i]);
	}
}
void OutputData(int ans){
	printf("%d\n", ans);
	for (int i=0; i<6; i++){
		printf("%d ", sol[i]);
	}
	printf("\n");
}
int main(void){
	int ans = -1;
	InputData();//입력

	int sum = 0;
    int total = 0;
    for (int i=0; i<6; i++){
        total += A[i] * m[i];
    }
    total -= W;
    for (int i=0; i<6; i++){
        int cnt = total / m[i];
        if (cnt > A[i]){
            cnt = A[i];
        }
        sol[i] = A[i] - cnt;
        sum += sol[i];
        total -= m[i] * cnt;
    }
    ans = sum;
	OutputData(ans);//출력
	return 0;
}