#include <stdio.h>
#include <stdlib.h>
int N;

int times[10000+10][2];
int S[10000+10];
int E[10000+10];
int present;
int absent;
void InputData(void){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d %d", &times[i][0], &times[i][1]);
    }
}


int comp (const void *a, const void *b) {
    return ((int *)a)[0] - ((int *)b)[0];
}


int main(void){
    InputData();// 입력받는 부분

    // 여기서부터 작성
    qsort(times, N, sizeof(times[0]), comp);
    
    int s = times[0][0];
    int e = times[0][1];
    
    for (int i = 1; i < N; i++) {
        if (times[i][0] > e) {
            if (absent < times[i][0] - e) {
                absent = times[i][0] - e;
            }
            if (present < e - s) {
                present = e - s;
            }
            s = times[i][0];
            e = times[i][1];
        }
        
        else if (e < times[i][1]) {
            e = times[i][1];
        }
    }
    
    if (present < e - s) {
        present = e - s;
    }
    

    printf("%d %d\n", present, absent);// 출력하는 부분
    return 0;
}