#include <stdio.h>
#include <string.h>
#define MAXN (20)
int N, B;
int H[MAXN + 10];
int ans = 1000000 * 21;

void InputData(void){
    scanf("%d %d", &N, &B);
    for (int i=0; i<N; i++){
        scanf("%d", &H[i]);
    }
}

int min(int a, int b) {
    return a > b ? b : a;
}

int used[MAXN + 10];

void DFS(int level, int sum) {
    if (sum >= B) {
        ans = min(ans, sum);
        return;
    }
    
    if (level >= N) {
        return;
    }
    DFS(level+1, sum + H[level]);
    DFS(level+1, sum);
    // for (int i = level; i < N; i++) {
    //     if (used[i]) {
    //         continue;
    //     }
    //     used[i] = 1;
    //     DFS(level+1, sum + H[i]);
    //     used[i] = 0;
    // }
    
}


int main(void){
    int T;
    scanf("%d", &T);
    for (int t=1; t<=T; t++){
        InputData();//입력받는 부분
        ans = 1000000 * 21;
        memset(used, 0, sizeof(used));
        //여기서부터 작성
        DFS(0, 0);
        

        printf("%d\n", ans - B);
    }
    return 0;
}