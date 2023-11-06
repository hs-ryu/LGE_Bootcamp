#include <stdio.h>
#include <string.h>
#define MAXN (100)
int H, W;
int map[MAXN+10][MAXN+10];
int visited[MAXN+10][MAXN+10];
int hour, sol;
int wpoint;
int rpoint;

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

struct Queue {
    int r;
    int c;
};

struct Queue queue[MAXN * MAXN];

void push(int r,int c) {
    queue[wpoint].r = r;
    queue[wpoint].c = c;
    wpoint++;
}

void pop(void) {
    rpoint++;
}

int isEmpty() {
    return wpoint == rpoint;
}

struct Queue front(void){
    return queue[rpoint];
}

int BFS() {
    memset(visited, 0, sizeof(visited));
    // memset(queue, 0, sizeof(struct Queue));
    wpoint = 0;
    rpoint = 0;
    visited[0][0] = 1;
    push(0,0);
    
    int exitCnt = 0;
    
    while (!isEmpty()) {
        struct Queue temp = front();
        pop();
        int cr = temp.r;
        int cc = temp.c;
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if ((0 <= nr && nr < H) && (0 <= nc && nc < W)) {
                if (visited[nr][nc] == 0) {
                    visited[nr][nc] = 1;
                    if (map[nr][nc] == 0) {
                        push(nr,nc);
                    }
                    else if (map[nr][nc] == 1) {
                        // 녹을 애들
                        map[nr][nc] = 2;
                        exitCnt++;
                    }
                }
            }
        }
    }
    return exitCnt;
} 

void InputData(void){
    scanf("%d %d", &H, &W);
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            scanf("%d", &map[i][j]);
        }
    }
}

int main(void){
    InputData();// 입력받는 부분

    // 여기서부터 작성
    
    // [0,0]에서 BFS 돌리기. -> 치즈의 테두리 부분들만 찾는다.
    // 없애기 (1 -> 0 변경)
    // 다시 반복 (t 시간동안)
    // 굳
    int totalCheezeCnt = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (map[i][j] == 1) {
                totalCheezeCnt++;
            }
        }
    }
    while (1) {
        int minusCnt = BFS();
        hour++;

        if (totalCheezeCnt - minusCnt == 0) {
            sol = minusCnt;
            break;
        }
        totalCheezeCnt -= minusCnt;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (map[i][j] == 2) {
                    map[i][j] = 0;
                }
            }
        }

    }
    
    printf("%d\n%d\n", hour, sol);// 출력하는 부분
    return 0;
}