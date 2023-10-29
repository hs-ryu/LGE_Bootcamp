#include <stdio.h>
#define MAXN ((int)1e3)
int N;//연잎수
int A[MAXN+10];//연잎좌표

int comp(const void *a, const void *b) {
    return *(int *)a > *(int *)b;
}



void InputData(void){
	scanf("%d", &N);
	for (int i=0; i<N; i++){
		scanf("%d", &A[i]);
	}
}
int main(void){
	int ans = 0;
	InputData();//입력받는부분

	//여기서부터작성
    qsort(A, N, sizeof(int), comp);

    for (int i = 0; i < N-2; i++) {
        for (int j = i+1; j< N-1; j++) {
            int jump1 = A[j] - A[i];
            int minTarget = A[j] + jump1;
            
            int l = 0;
            int r = N-1;
            int minIdx = -1;
            while (l <= r) {
                int middle = (l + r) / 2;
                int tempNum = A[middle];
                if (tempNum >= minTarget) {
                    r = middle - 1;
                    minIdx = middle;
                }
                else {
                    l = middle + 1;
                }
            }
            
            if (minIdx != -1) {
                l = 0;
                r = N-1;
                int maxIdx = -1;
                int maxTarget = A[j] + jump1 * 2;
                while (l <= r) {
                    int middle = (l+r) / 2;
                    int tempNum = A[middle];
                    if (tempNum <= maxTarget) {
                        maxIdx = middle;
                        l = middle + 1;
                    } else {
                        r = middle - 1;
                    }
                }
                ans += maxIdx - minIdx + 1;
            }
        }
    }

	printf("%d\n", ans);//출력하는부분
	return 0;
}