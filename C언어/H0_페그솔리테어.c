#include <stdio.h>
#include <string.h>
#define MAXH (5)
#define MAXW (9)
char map[MAXH+2][MAXW+2];
int newMap[MAXH+2][MAXW+2];
int pinCnt;
int solremain, solmove;
void InputData(void){
    for (int h=0; h<MAXH; h++){
        scanf("%s", &map[h][0]);
    }
}

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int pinLocation[9][2];
int exist[9];

// 핀 위치를 하나씩 잡아보기.

// 점프가 가능한가?
int isJumpingPossible(int sr, int sc, int dir) { // 점프할 핀의 위치, 점프 당할 핀의 위치
    int nr = sr + dr[dir] * 2;
    int nc = sc + dc[dir] * 2;
    if ((0 <= nr && nr < MAXH) && (0 <= nc && nc < MAXW) && newMap[nr][nc] == 0) {
        return 1;
    }
    return 0;
}

void DFS(int level, int existCnt, int movingCnt) {
    
    // 가지치기?
    if (solremain > existCnt) {
        solremain = existCnt;
        solmove = movingCnt;
    } else if (solremain == existCnt) {
        if (solmove > movingCnt) {
            solmove = movingCnt;
        }
    }
    
    // 종료 조건
    if (level == pinCnt) {
        return;
    }

    // 다음 경우의 수
    for (int i = 1; i <= pinCnt; i++) {
        if (!exist[i]) {
            continue;
        }
        int r = pinLocation[i][0];
        int c = pinLocation[i][1];
        
        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if ((0 <= nr && nr < MAXH) && (0 <= nc && nc < MAXW) && newMap[nr][nc] != 0 && newMap[nr][nc] != -1) {
                int target = newMap[nr][nc];
                if (isJumpingPossible(r,c,dir)) {
                    exist[target] = 0;
                    pinLocation[i][0] = r + dr[dir] * 2; // 갈 수 있는지는 isJumpingPossible에서 확인 가능
                    pinLocation[i][1] = c + dc[dir] * 2;
                    newMap[r][c] = 0;
                    newMap[r + dr[dir] * 2][c + dc[dir] * 2] = i;
                    newMap[nr][nc] = 0;
                    // printf("start: %d, target: %d, level: %d, existCnt: %d, movingCnt: %d\n",i, target, level, existCnt, movingCnt);
                    // printf("startR: %d, startC: %d, targetR: %d, targetC: %d\n", r, c, r + dr[dir] * 2,  c + dc[dir] * 2);
                    // printf("----------\n");
                    DFS(level+1, existCnt - 1, movingCnt + 1);
                    exist[target] = 1;
                    newMap[r][c] = i;
                    newMap[r + dr[dir] * 2][c + dc[dir] * 2] = 0;
                    newMap[nr][nc] = target;
                    pinLocation[i][0] = r;  // 건너가야 하니까 한번 더 가주자. 어차피 가는거는 isJumpingPossible에서 확인 가능
                    pinLocation[i][1] = c;
                }
            }
        }
    }
}

int main(void){
    int T;
    scanf("%d", &T);
    for (int t=1; t<=T; t++){
        InputData();//입력받는 부분
        solremain = 10;
        solmove = 500000;
        //여기서부터 작성
        memset(pinLocation, 0, sizeof(pinLocation));
        memset(exist, 0, sizeof(int));
        // 편하게 보기 위해서 맵을 다시 그리기
        pinCnt = 0;
        for (int i = 0; i < MAXH; i++) {
            for (int j = 0; j < MAXW; j++) {
                if (map[i][j] == '#') {
                    newMap[i][j] = -1;
                } else if (map[i][j] == '.') {
                    newMap[i][j] = 0;
                } else {
                    pinCnt++;
                    newMap[i][j] = pinCnt;
                    exist[pinCnt] = 1;
                    // 핀의 현재 위치들을 기억.
                    pinLocation[pinCnt][0] = i;
                    pinLocation[pinCnt][1] = j;
                }
            }
        }
        
        // for (int i = 0; i < MAXH; i++) {
        //     for (int j = 0; j < MAXW; j++) {
        //         printf("%d ", newMap[i][j]);
        //     }
        //     printf("\n");
        // }
        
        // printf("%d \n",isJumpingPossible(1,2,3));
        // printf("%d \n",isJumpingPossible(1,2,2));
        DFS(0, pinCnt, 0);

        printf("%d %d\n", solremain, solmove);//출력하는 부분
    }
    return 0;
}