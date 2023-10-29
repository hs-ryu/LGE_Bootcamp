#include <stdio.h>
#define MAXN ((int)1e4)
int N, M;
int A[MAXN+10];

int comp(const void *a, const void *b) {
    return *(int *)a > *(int *)b;
}


void InputData(void){
	scanf("%d", &N);
	for (int i=0 ; i<N ; i++){
		scanf("%d", &A[i]);
	}
	scanf("%d", &M);
}

int main(void){
	int ans = -1;

	InputData();// 입력받는 부분

	// 여기서부터 작성
    qsort(A, N, sizeof(int), comp);

    int l = 0;
    int r = A[N-1];
    int result = 0;
    while (l <= r) {
        int middle = (l + r) / 2;
        int total = 0;
        int flag = 1;
        for (int i = 0; i < N; i++) {
            if (middle >= A[i]) {
                total += A[i];
            }
            else {
                total += middle;
            }
            if (total > M) {
                flag = 0;
                break;
            }
        }

        if (flag) {
            result = middle;
            l = middle + 1;
        } else {
            r = middle - 1;
        }
    }
	printf("%d\n", result);// 출력하는 부분
	return 0;
}