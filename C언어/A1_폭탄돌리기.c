#include <stdio.h>
#define MAXN (100)
int K;//처음 폭탄을 가진 사람 번호
int N;//퀴즈 개수
int T[MAXN+10];//걸린 시간
char Z[MAXN+10];//정답 여부

int timer;  // 현재 시간
int i;      // 현재 명령
void InputData(void){
    scanf("%d", &K);
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d %c", &T[i], &Z[i]);
    }
}

int main(void){
    int ans = -1;
    InputData();//입력받는 부분
    
    //여기서부터 작성
    while (i < N) {
        int temp_T = T[i];
        int temp_Z = Z[i];
        
        timer += temp_T;
        if (timer >= 210) {
            break;
        }
        if (temp_Z == 'T') {
            K++;
            if (K == 9) {
                K = 1;
            }
        } 
        
        
        i++;
    }
    ans = K;
    printf("%d\n", ans);//출력하는 부분
    return 0;
}