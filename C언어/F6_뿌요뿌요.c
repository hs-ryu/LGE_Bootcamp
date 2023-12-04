#include <stdio.h>
#include <string.h>
#define MAXH (12)
#define MAXW (6)
char map[MAXH+2][MAXW+2];
int visited[MAXH+2][MAXW+2];
int removeTargetList[MAXH+2][MAXW+2];

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

void InputData(void){
    for (int i=0; i<MAXH; i++){
        scanf("%s", &map[i][0]);
    }
}

struct Queue {
    int r;
    int c;
};

struct Queue queue[50000];

int wp;
int rp;

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
    return rp == wp;
}

int BFS(int r, int c, char color) {
    int cnt = 0;
    push(r,c);
    visited[r][c] = 1;
    removeTargetList[r][c] = 1;
    cnt = 1;
    while (!isEmpty()) {
        struct Queue temp = front();
        pop();
        int cr = temp.r;
        int cc = temp.c;
        
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if ((0 <= nr && nr < 12) && (0 <= nr && nc < 6) && map[nr][nc] == color) {
                if (visited[nr][nc] == 0) {
                    visited[nr][nc] = 1;
                    removeTargetList[nr][nc] = 1;
                    push(nr,nc);
                    cnt++;
                }
            }
        }
    }
    if (cnt >= 4) {
        return cnt;
    } else {
        return 0;
    }
}

void bomb(void) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (removeTargetList[i][j]) {
                map[i][j] = '.';
            }
        }
    }
}

void relocation(void) {
    // for (int i = 0; i < MAXH; i++) {
    //     for (int j = 0; j < MAXW; j++) {
    //         printf("%c ", map[i][j]);
    //     }
    //     printf("\n");
    // }

    for (int c = 0; c < MAXW; c++) {
        int pushCnt = 0;
        for (int r = MAXH-1; r >= 0; r--) {
            if (map[r][c] == '.') {
                pushCnt++;
            } else {
                // printf("%d %d\n", r, pushCnt);
                map[r+pushCnt][c] = map[r][c];
                if (pushCnt != 0) {
                    map[r][c] = '.';
                }
            }
        }
    }
    // printf("-----------------\n");
    // for (int i = 0; i < MAXH; i++) {
    //     for (int j = 0; j < MAXW; j++) {
    //         printf("%c ", map[i][j]);
    //     }
    //     printf("\n");
    // }
}


int main(void){
    int T, t, ans = -1;
    scanf("%d", &T);
    for (t=1; t<=T; t++){
        InputData();//입력받는 부분
        
        ans = 0;

        //여기서부터 작성
        while (1) {
            memset(visited, 0, sizeof(visited));
            wp = 0;
            rp = 0;
            // 1. BFS로 한꺼번에 터뜨리기
            int bombCnt = 0;
            int isBomb = 0;
            for (int i = 0; i < MAXH; i++) {
                for (int j = 0; j < MAXW; j++) {
                    if (visited[i][j] == 0 && map[i][j] != '.') {
                        bombCnt = BFS(i,j,map[i][j]);
                        // printf("bomb : %d\n",bombCnt);
                        if (bombCnt >= 4) {
                            // 1-1. 4개 이상 터질 수 있으면 visited 체크된 친구들 모두 .으로 만들기
                            bomb();
                            isBomb = 1;
                        }
                        memset(removeTargetList, 0, sizeof(removeTargetList));
                    }
                }
            }
            memset(visited, 0, sizeof(visited));
            
            // 2. 터진게 있다면 아래로 내리기
            if (isBomb == 1) {
                relocation();
                ans++;
            }
            
            
            // 3. 터지는게 없으면 반복 그만
            if (isBomb == 0) {
                break;
            }
        }

        printf("%d\n", ans);//출력하는 부분
    }
    return 0;
}