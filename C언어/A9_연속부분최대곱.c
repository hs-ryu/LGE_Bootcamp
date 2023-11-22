#include <stdio.h>
 
int N;
double D[10000+10];
double gob[10000+10];
void InputData(void){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%lf", &D[i]);
    }
}
 
int main(void){
    double ans = -1;
 
    InputData();// 입력받는 부분
 
    // 여기서부터 작성

    gob[0] = D[0];
    ans = gob[0];
    for (int i = 1; i < N; i++) {
        if (gob[i-1] * D[i] > D[i]) {
            gob[i] = (gob[i-1] * D[i]);
        }
        else {
            gob[i] = D[i];
        }
        if (gob[i] > ans) {
            ans = gob[i];
        }
    }
 
    printf("%.3lf\n", ans);// 출력하는 부분
    return 0;
}