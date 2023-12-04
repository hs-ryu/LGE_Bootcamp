#include <stdio.h>
#include <string.h>
int N;
int grids[500+10][500+10];
int wp;
int rp;
int visited[500+10][500+10];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int target;

void InputData(void){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            scanf("%d", &grids[i][j]);
        }
    }
}

struct Queue {
    int r;
    int c;
};

struct Queue queue[500 * 500 + 10];

void push(int r, int c) {
    queue[wp].r = r;
    queue[wp].c = c;
    wp++;
}

void pop(void) {
    rp++;
}

struct Queue front(void) {
    return queue[rp];
}

int isEmpty(void) {
    return wp == rp;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int diff(int a, int b){
    int re = a - b;
    return re > 0 ? re : (re * -1);
    
}

int BFS(int sr, int sc, int D) {
    wp = 0;
    rp = 0;
    visited[sr][sc] = 1;
    push(sr,sc);
    int cnt = 1;
    
    while (!isEmpty()) {
        struct Queue temp = front();
        pop();
        int cr = temp.r;
        int cc = temp.c;
        
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if ((0 <= nr && nr < N) && (0 <= nc && nc < N)) {
                if (diff(grids[nr][nc], grids[cr][cc]) <= D) {
                    if (visited[nr][nc] == 0) {
                        visited[nr][nc] = 1;
                        push(nr,nc);
                        cnt++;
                    }
                }
                
            }
        }
    }
    return cnt;
}


int main(void){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    // 1. 높이 개수 카운트 BFS
    target = N * N / 2;
    if (N % 2) {
        target++;
    }
    
    int l = 0;
    int r = 1000001;
    
    while (l <= r) {
        memset(visited, 0, sizeof(visited));
        int D = (l + r) / 2;
        
        int max_possible = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                
                int temp_possible = BFS(i,j,D);
                max_possible = max(max_possible, temp_possible);
            }
        }
        // printf("D : %d ,max_possible : %d\n",D, max_possible);
        if (max_possible >= target) {
            r = D - 1;
            ans = D;
        } else {
            l = D + 1;
        }
    }
    
    

    printf("%d\n", ans);// 출력하는 부분
    return 0;
}