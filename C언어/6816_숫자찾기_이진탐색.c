#include <stdio.h>
#include <string.h>
#define MAXN ((int)5e4)
#define MAXT ((int)1e4)
int N;
int A[MAXN+10];
int T;
int B[MAXT+10];

void InputData(void){
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++){
		scanf("%d", &A[i]);
	}
	scanf("%d", &T);
	for(int i=0 ; i<T ; i++){
		scanf("%d", &B[i]);
	}
}
void OutputData(void){
	for(int i=0; i<T ; i++){
		printf("%d\n", B[i]);
	}
}
int main(void){
	InputData();// 입력받는 부분

	// 여기서부터 작성
    
    for (int i = 0; i < T; i++) {
        int l = 0;
        int r = N-1;
        int target = B[i];
        
        int flag = 0;
        
        while (l <= r) {
            int middle = (l + r) / 2;
            int tempNum = A[middle];
            
            if (tempNum == target) {
                B[i] = middle+1;
                flag = 1;
                break;
            }
            
            if (tempNum > target) {
                r = middle - 1;
            }
            else if (tempNum < target) {
                l = middle + 1;
            }
        }
        if (!flag) {
            B[i] = 0;
        }
    }
    

    
	OutputData();// 출력하는 부분
	return 0;
}