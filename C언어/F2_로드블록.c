#include <stdio.h>

int N, M;
int A[10000 + 10];
int B[10000 + 10];
int L[10000 + 10];
int loadInfo[100+10][100+10];
int newloadInfo[100+10][100+10];
int visited[100+10];
int path[100+10];
int wp;
int rp;


void InputData(void){
    scanf("%d %d", &N, &M);
    for (int i = 0; i<M; i++){
        scanf("%d %d %d", &A[i], &B[i], &L[i]);
        loadInfo[A[i]][B[i]] = L[i];
        loadInfo[B[i]][A[i]] = L[i];
    }
}

int queue[500000];


void push(int idx) {
    queue[wp] = idx;
    wp++;
}

void pop(void) {
    rp++;
}

int front(void) {
    return queue[rp];
}

int isEmpty(void) {
    return wp == rp;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int BFS() {
    for (int i = 0; i <= N; i ++) {
        visited[i] = 200000000;
        path[i] = 0;
    }
    push(1);

    visited[1] = 0;

    while(!isEmpty()) {
        int nowLocation = front();
        pop();
        // printf("%d\n", nowLocation);
        for (int e = 1; e <= N; e++) {
            if (newloadInfo[nowLocation][e]) {
                int nowTime = visited[nowLocation] + newloadInfo[nowLocation][e];
                if (visited[e] >= nowTime) {
                    push(e);
                    visited[e] = nowTime;
                    path[e] = nowLocation;
                }
            }
        }
    }
    
    return visited[N];
}

int willChangeLoad[100+10];
int willChangeLoadlen = 0;

void check(int a, int idx) {
    if (path[a] == 0) {
        return;
    }
    check(path[a], idx+1);
    willChangeLoad[idx] = path[a];
    willChangeLoadlen = max(willChangeLoadlen, idx);
    // printf("%d ", path[a]);
}


int main(void){
    int ans = -1;

    InputData();// 입력받는 부분

    
    
    // 여기서부터 작성
    // 1. BFS 돌려서 최단 경로 찾기
    // 1-1. 최단경로 찾을때, 이전에 어디서 왔는지 확인해야함.
    // 1-2. 이전에 어디서 왔는지 확인하면서, 하나씩 * 2로 설정해 나감
    // 2. map 다시 그리기
    // 3. 하나씩 BFS 최단 경로 찾기
    for (int r = 0; r <= N; r++) {
        for (int c = 0; c <= N; c++) {
            newloadInfo[r][c] = loadInfo[r][c];
        }
    }
    
    int beforeMinLoad = BFS();
    
    check(N,1);
    willChangeLoad[0] = N;
    int afterMinLoad = 0;
    
    // for (int i = 0; i < willChangeLoadlen+1; i++) {
    //     printf("%d ", willChangeLoad[i]);
    // }
    
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            
        }
    }
    
    
    
    for (int i = 0; i < willChangeLoadlen; i++) {
        // 초기화 해주기
        wp = 0;
        rp = 0;
        
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                newloadInfo[r][c] = loadInfo[r][c];
            }
        }
        
        int changeLoadS = willChangeLoad[i];
        int changeLoadE = willChangeLoad[i+1];
        
        newloadInfo[changeLoadS][changeLoadE] = newloadInfo[changeLoadS][changeLoadE] * 2;
        newloadInfo[changeLoadE][changeLoadS] = newloadInfo[changeLoadE][changeLoadS] * 2;
        
        afterMinLoad = max(afterMinLoad, BFS());
        // printf("cs: %d, ce: %d\n", changeLoadS, changeLoadE);
        // printf("%d %d\n", beforeMinLoad, afterMinLoad);
    }
    
    ans = afterMinLoad - beforeMinLoad;

    printf("%d\n", ans);// 출력하는 부분
    return 0;
}