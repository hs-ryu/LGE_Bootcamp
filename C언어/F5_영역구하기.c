#include <stdio.h>
#include <stdlib.h>

#define MAX (100)
int R, C, K;//세로크기, 가로크기, 직사각형 개수
int sx[MAX+10];
int sy[MAX+10];
int ex[MAX+10];
int ey[MAX+10];
int map[MAX+10][MAX+10];
int visited[MAX+10][MAX+10];

int sol[MAX * MAX];//각 영역 넓이 저장용

struct Queue {
    int r;
    int c;
};

struct Queue queue[MAX * MAX + 10];

int wp;
int rp;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

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

int comp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
    
}

void InputData(){
    scanf("%d %d %d", &R, &C, &K);
    for (int i=0; i<K; i++){
        scanf("%d %d %d %d", &sx[i], &sy[i], &ex[i], &ey[i]);
    }
}
void OutputData(int ans){
    printf("%d\n", ans);
    for (int i=0; i<ans; i++){
        printf("%d ", sol[i]);
    }
    printf("\n");
}

int BFS(int r, int c) {
    push(r,c);
    visited[r][c] = 1;
    int cnt = 1;
    while (!isEmpty()) {
        struct Queue temp = front();
        pop();
        int cr = temp.r;
        int cc = temp.c;
        
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if ((0 <= nr && nr < R) && (0 <= nc && nc < C) && map[nr][nc] == 0) {
                if (visited[nr][nc] == 0) {
                    push(nr, nc);
                    visited[nr][nc] = 1;
                    cnt++;
                }
            }
            
        }
    }
    return cnt;
}


int main(void){
    int ans = -1;
    InputData();//입력받는 부분

    //여기서부터 작성
    for (int i = 0; i < K; i++) {
        int sc = sx[i];
        int sr = sy[i];
        int ec = ex[i];
        int er = ey[i];
        
        for (int r = sr; r < er; r++) {
            for (int c = sc; c < ec; c++) {
                map[r][c] = 1;
            }
        }
    }
    // BFS로 영역 나누기
    int idx = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == 0 && visited[i][j] == 0) {
                int re = BFS(i,j);
                sol[idx] = re;
                idx++;
            }
        }
    }
    
    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         printf("%d ", map[i][j]);
    //     }
    //     printf("\n");
    // }
    
    qsort(sol, idx, sizeof(int), comp);
    
    

    OutputData(idx);//출력하는 부분
    return 0;
}