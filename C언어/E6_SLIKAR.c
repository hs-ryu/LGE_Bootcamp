#include <stdio.h>
#include <string.h>
#define MAXN (50)
int R, C;//지도 세로, 가로 크기
char map[MAXN+10][MAXN+10];
char newMap[MAXN+10][MAXN+10];
int visited[MAXN+10][MAXN+10];

int wp;
int rp;
int waterwp;
int waterrp;
int ans;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void InputData(void){
    scanf("%d %d", &R, &C);
    for (int i=0; i<R; i++){
        scanf("%s", map[i]);
    }
}

struct Queue {
    int r;
    int c;
    int time;
};
struct Queue queue[50000];
struct Queue water[50000];

void push(int r, int c, int time) {
    queue[wp].r = r;
    queue[wp].c = c;
    queue[wp].time = time;
    wp++;
}

void pop(void) {
    rp++;
}

int isEmpty(void) {
    return wp == rp;
}

struct Queue front(void) {
    return queue[rp];
}

void waterpush(int r, int c, int time) {
    water[waterwp].r = r;
    water[waterwp].c = c;
    water[waterwp].time = time;
    waterwp++;
}

void waterpop(void) {
    waterrp++;
}

int waterEmpty(void) {
    return waterrp == waterwp;
}

struct Queue waterFront(void) {
    return water[waterrp];
}



// 범람
void flow(int r, int c, int time) {
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if ((0 <= nr && nr < R) && (0 <= nc && nc < C)) {
            if (newMap[nr][nc] != 'X' && newMap[nr][nc] != 'D' && newMap[nr][nc] != '*') {
                newMap[nr][nc] = '*';
                waterpush(nr,nc, time+1);
            }
        }
    }
}


void BFS(int sr, int sc) {
    visited[sr][sc] = 1;
    push(sr,sc,0);
    int timer = 0;
    // printf("%d %d\n", sr, sc);
    // 홍수 범람먼저.
    while (1) {
        // for (int i = 0; i < R; i++) {
        //     for (int j = 0; j < C; j++) {
        //         printf("%c ", newMap[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n--------------------\n");
        // for (int i = 0; i < R; i++) {
        //     for (int j = 0; j < C; j++) {
        //         printf("%d ", visited[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n--------------------\n");
        
        while (!waterEmpty()) {
            struct Queue tempWater = waterFront();
            if (tempWater.time != timer) {
                break;
            }
            if (tempWater.time < timer) {
                waterpop();
                continue;
            }
            waterpop();
            flow(tempWater.r, tempWater.c, tempWater.time);
        }
        
        // 이동하기
        while (!isEmpty()) {
            struct Queue tempQ = front();
            if (tempQ.time != timer) {
                break;
            }
            if (tempQ.time < timer) {
                pop();
                continue;
            }
            pop();
            int cr = tempQ.r;
            int cc = tempQ.c;
            // printf("cr : %d, cc : %d \n", cr, cc);
            for (int i = 0; i < 4; i++) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];
                
                if ((0 <= nr && nr < R) && (0 <= nc && nc < C)) {
                    if (newMap[nr][nc] == 'X' || newMap[nr][nc] == '*' || visited[nr][nc] != 0) {
                        continue;
                    }
                    if (newMap[nr][nc] == 'D') {
                        ans = tempQ.time+1;
                        return;
                    }
                    // printf("nr : %d, nc : %d, time: %d, pTime: %d \n", nr, nc, timer, tempQ.time);
                    visited[nr][nc] = 1;
                    push(nr,nc,tempQ.time+1);
                }
            }
        }
        
        if (isEmpty()) {
            ans = -1;
            return;
        }
        
        timer++;
    }
}


int main(void){
    int T;
    scanf("%d", &T);
    for (int t=1; t<=T; t++){
        InputData();//입력 받는 부분
        // 여기서부터 작성
        // 초기화
        ans = -1;
        memset(visited, 0, sizeof(visited));
        wp = 0;
        rp = 0;
        waterwp = 0;
        waterrp = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                newMap[i][j] = map[i][j];
            }
        }
        
        // 시작점, 도착점 찾기
        int sr, sc, er, ec;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (newMap[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (newMap[i][j] == 'D') {
                    er = i;
                    ec = j;
                }
                else if (newMap[i][j] == '*') {
                    waterpush(i,j,0);
                }
            }
        }
        // BFS 홍수 확산이 먼저다!
        BFS(sr,sc);
        
        
        if (ans == -1) printf("KAKTUS\n");//출력 하는 부분
        else printf("%d\n", ans);
    }
    return 0;
}