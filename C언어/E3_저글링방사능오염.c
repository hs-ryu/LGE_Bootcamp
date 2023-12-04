#include <stdio.h>
#define MAXN (100)
int W, H;//지도의 가로 세로 크기
char map[MAXN+10][MAXN+10];//지도 정보('1':저글링, '0':빈곳)
int visited[MAXN+10][MAXN+10];
int wp;
int rp;
int ansTime;
int ansCnt;

// 상하좌우
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};


struct Queue {
    int r;
    int c;
    int time;
};

struct Queue queue[MAXN * MAXN + 10];

void push(int r, int c, int time) {
    queue[wp].r = r;
    queue[wp].c = c;
    queue[wp].time = time;
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


int sw, sh;//시작위치 가로 세로 좌표
void InputData(void){
    scanf("%d %d", &W, &H);
    for (int i=1; i<=H; i++){
        scanf("%s", &map[i][1]);
    }
    scanf("%d %d", &sw, &sh);
}


void BFS(int r, int c) {
    push(r,c,3);
    visited[r][c] = 1;
    
    while (!isEmpty()) {
        struct Queue temp = front();
        pop();
        int cr = temp.r;
        int cc = temp.c;
        int time = temp.time;
        
        for (int i = 0 ; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if ((1<=nr && nr <= H) && (1 <= nc && nc <= W) && map[nr][nc] == '1') {
                if (visited[nr][nc] == 0) {
                    visited[nr][nc] = 1;
                    push(nr,nc, time+1);
                    if (time + 1 > ansTime) {
                        ansTime = time+1;
                    }
                }
            }
        }
    }
    
    
    
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (map[i][j] == '1' && visited[i][j] == 0) {
                ansCnt++;
            }
        }
    }
}



int main(void){
    InputData();//입력 받는 부분

    //여기서부터 작성
    // 처음 맞은애는 무조건 죽으니까 3으로 초기화
    ansTime = 3;
    BFS(sh, sw);
    
    
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <=N; j++) {
    //         if (map[i][j] == '1' && visited[i][j] == 0) {
                
    //         }
    //     }
    // }
    printf("%d\n", ansTime);
    printf("%d", ansCnt);
    
    

    return 0;
}