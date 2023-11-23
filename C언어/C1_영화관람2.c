#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)1e5)
int N;//영화수
typedef struct{
    int s, e;
}DATA;
DATA A[MAXN + 10];
DATA B[MAXN + 10];
void InputData(void){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d %d", &A[i].s, &A[i].e);
    }
}

int comp (const void *a, const void *b) {
    DATA x = *(DATA *)a;
    DATA y = *(DATA *)b;
    
    return y.e - x.e;
}



int main(void){
    int ans = 0;
    InputData();// 입력받는 부분

    // 여기서부터 작성
    
    int n = 0;
    for (int i = 0; i < N; i++) {
        if (A[i].e - A[i].s < 2) {
            continue;
        }
        B[n].s = A[i].s;
        B[n].e = A[i].e;
        // printf("%d %d\n", B[n].s, B[n].e);
        
        n++;
    }
    // printf("-------------\n");
    qsort(B, n, sizeof(B[0]), comp);
    
    // for (int i = 0; i < n; i++) {
    //     printf("%d %d\n", B[i].s, B[i].e);
    // }
    
    int s = B[0].s;
    int e = B[0].e;
    ans = 1;
    for (int i = 1; i < n; i++) {
        // 보기로 한 영화 시작시간 < 고민중인 영화 끝 시간
        // 안본다.
        // 근데, 생각해야할건 
        if (s < B[i].e) {
            if (s > B[i].s) {
                continue;
            }
            s = B[i].s;
            e = B[i].e;
        }
        else {
            s = B[i].s;
            e = B[i].e;
            ans++;
        }
    }

    printf("%d\n", ans);// 출력하는 부분
    return 0;
}