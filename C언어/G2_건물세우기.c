#include <stdio.h>
#include <string.h>
#define MAXN (10)
int N;
int cost[MAXN+10][MAXN+10];
int solpath[MAXN+10];//답 경로
int minSum = 1000;
int ans;
void InputData(void){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            scanf("%d", &cost[i][j]);
        }
    }
}
void OutputData(int sol){
    printf("%d\n", sol);
    for (int i=0; i<N; i++){
        printf("%d ", solpath[i]);
    }
    printf("\n");
}

int used[MAXN + 10];
int sel[MAXN + 10];
void DFS(int level) {
    if (level >= N) {
        
        int tempSum = 0;
        for (int i = 0; i < N; i++) {
            tempSum += cost[i][sel[i]-1];
            // printf("%d ", sel[i]);
        }
        
        if (ans > tempSum) {
            for (int i = 0; i < N; i++) {
                solpath[i] = sel[i];
            }
            ans = tempSum;
        }
        
        // printf("\n");
        // if (minSum > sum) {
        //     for (int i = 0; i < N; i++) {
        //         solpath[i] = used[i];
        //     }
        //     minSum = sum;
        // }
        return;
    }
    
    
    // i: 장소 번호
    // used[i] : 해당 장소가 선정이 되었나?
    for (int i = 0; i < N; i++) {
        if (used[i] != 0) {
            continue;
        }
        used[i] = 1;
        sel[level] = i+1;
        DFS(level+1);
        used[i] = 0;
        sel[level] = 0;
    }
    
    
}


int main(void){
    ans = 1000000;

    InputData();//입력받는 부분

    //여기서부터 작성
    memset(used, 0, sizeof(used));
    
    
    DFS(0);
    

    OutputData(ans);//출력하는 부분
    return 0;
}