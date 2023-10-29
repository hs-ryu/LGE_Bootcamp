#include <stdio.h>
#define MAX ((int)2e5)
int N;
int A[MAX+10];
int M;
int B[MAX+10];

void InputData(void){
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &M);
	for(int i=0 ; i<M ; i++) {
		scanf("%d", &B[i]);
	}
}

void OutputData(void){
	for(int i=0 ; i<M ; i++) {
		printf("%d ", B[i]);
	}
}

int main(void){
	// 입력받는 부분
	InputData();

	// 여기서부터 작성
    for (int i = 0; i < M; i++) {
        int l = 0;
        int r = N-1;
        int target = B[i];
        int flag = 0;
        int idx = 0;
        while (l <= r) {
            int middle = (l+r) / 2;
            int temp = A[middle];
            
            if (temp == target) {
                flag = 1;
                idx = middle;
                break;
            }
            
            if (temp > target) {
                r = middle - 1;
            }
            else if (temp < target) {
                l = middle + 1;
            }
        }
        
        B[i] = 0;
        if (flag) {
            for (int j = idx; j < N; j++) {
                if (A[j] == target) {
                    B[i]++;
                }
                else {
                    break;
                }
            }
            
            for (int j = idx-1; j > -1; j--) {
                if (A[j] == target) {
                    B[i]++;
                }
                else {
                    break;
                }
            }
        }
    }
    
    

	// 출력하는 부분
	OutputData();
	return 0;
}