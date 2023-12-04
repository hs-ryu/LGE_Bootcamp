#include <stdio.h>
#include <string.h>
int N;//마을 수
int A[100000+10];//마을 위치
int B[100000+10];//잡힌 물고기 양
void InputData(void){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d %d", &A[i], &B[i]);
    }
}
int main(void){
    long long ans = -1;
    InputData();//입력받는부분
    
    //여기서부터작성
    
    int l = 0;
    int r = 1000000000;
    
    long long total_fish = 0;
    for (int i = 0; i < N; i++) {
        total_fish += B[i];
    }
    
    while (l <= r) {
        
        int middle = (l + r) / 2;
        
        if (middle > total_fish) {
            r = middle - 1;
            continue;
        }
        // printf("---------------");
        // printf("%d \n", middle);

        long long now = 0;
        int isPossible = 0;
        for (int i = 0; i < N-1; i ++) {
            now = now + B[i] - middle;
            if (now < 0) {
                now = now - (A[i+1] - A[i]);
            }
            else {
                now = now - (A[i+1] - A[i]);
                if (now < 0) {
                    now = 0;
                }
            }
        }
        if (now + B[N-1] - middle >= 0) {
            isPossible = 1;
        } 
        
        
        
        // printf("\n");
        // printf("---------------");
        if (isPossible) {
            l = middle + 1;
            ans = middle;
        } else  {
            r = middle - 1;
        }
        
    }
    
    
    printf("%d\n", ans);//출력하는부분
    return 0;
}