#include <stdio.h>
#include <stdlib.h>
 
int N;
struct Info {
    int n;
    int s;
    int e;
};
 
struct Info info[510];
int sol[500+10];
int reserved[500+10];
void InputData(void){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d %d %d", &info[i].n, &info[i].s, &info[i].e);
    }
}
void OutputData(int ans){
    printf("%d\n", ans);
    for (int i=0; i<ans; i++){
        printf("%d ", reserved[i]);
    }
}
 
int comp(const void *a, const void *b) {
    struct Info *x = (struct Info *)a;
    struct Info *y = (struct Info *)b;
     
    return x -> e - y -> e;
}
 
int main(void){
    int ans = 1;
 
    InputData();// 입력받는 부분
 
    qsort(info, N, sizeof(info[0]), comp);
    // 여기서부터 작성
    int e = info[0].e;
    reserved[0] = info[0].n;
     
    for (int i = 1; i < N; i++) {
        if (e > info[i].s) {
            continue;
        }
        reserved[ans++] = info[i].n;
        e = info[i].e;
    }
 
    OutputData(ans);// 출력하는 부분
    return 0;
}
/**************************************************************
    Problem: 1134
    Language: C
    Result: Accepted
    Time:15 ms
    Memory:1168 kb
****************************************************************/