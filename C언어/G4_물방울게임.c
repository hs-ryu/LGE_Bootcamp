#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN (100)
int A;
int N;
int W[MAXN+10];
int ans;
void InputData(void){
    scanf("%d %d", &A, &N);
    for (int i=0; i<N; i++){
        scanf("%d", &W[i]);
    }
}

int comp (const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int min(int a, int b) {
    return a > b ? b : a;
}

// 스킬 0을 선택, 스킬 1을 선택, 스킬 2를 선택
// 스킬 0 선택시, 먹는다.
// 스킬 1 선택시 : 현재 point - 1을 더해줌
// 스킬 2 선택시 : 그냥 다음걸로 넘어감
// 스킬을 가장 적게 선택하는 경우의 수
void DFS(int level, int total, int cnt) {   // 현재 단계, 현재까지의 몸집, 현재까지 사용한 스킬 수
    if (level >= N) {
        ans = min(cnt, ans);
        return;
    }
    
    // 스킬 수가 ans보다 크다면 볼 필요도 없음. 최대 depth = 100;
    if (cnt > ans) {
        return;
    }
    
    
    
    // 또? 언제 안봐도 될까?
    
    
    // 만약 먹을 수 있다면 스킬 사용 안함. 그게 이득임
    if (total > W[level]) {
        DFS(level+1, total + W[level], cnt);
    }
    // 못먹으면 스킬 1번, 2번 써봄
    else {
        if(total > 1) {
            // 스킬 1번. 먹을수 있는 제일 최대를 추가로 먹자.
            DFS(level, total + total - 1, cnt + 1);
        }
        
        // 스킬 2번. 그냥 생략임.
        // ans = ans > cnt + (N - level) ? cnt + (N - level) : ans;
        DFS(level + 1, total, cnt + 1);
    }
}



int main(void){
    int t, T;
    scanf("%d", &T);
    for (t=1; t<=T; t++){
        memset(W, 0, sizeof(int));
        
        InputData();//입력받는 부분
        ans = N; 
        //여기서부터 작성
        qsort(W, N, sizeof(int), comp);
        
        DFS(0,A,0);
        
        

        printf("Case #%d: %d\n", t, ans);//출력하는 부분
    }
    return 0;
}