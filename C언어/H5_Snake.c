#include <stdio.h>
#define MAXN (100)
int N;
int K;
int map[MAXN+10][MAXN+10];
int R[MAXN+10];
int C[MAXN+10];
int L;
int X[MAXN+10];
char CMD[MAXN+10];

int wp;
int rp;

int dir = 0;
// 우, 하, 좌, 상
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

struct Queue {
    int r;
    int c;
};

struct Queue queue[MAXN * MAXN * MAXN];

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


int BFS(int sr, int sc) {
    map[sr][sc] = 1;
    
    
    // 대가리 위치 넣기
    push(sr,sc);
    
    int cr = sr;    // 대가리 위치 갱신 r
    int cc = sc;    // 대가리 위치 갱신 c
    int cmd = 0;
    int timer = 0;
    while (1) {
        struct Queue tail = front();
        int tr = tail.r;
        int tc = tail.c;
        // printf("cr: %d, cc: %d, tr: %d, tc: %d, dir: %d \n", cr, cc, tr, tc, dir);
        timer++;
        
        // 이동 체크
        int nr = cr + dr[dir];
        int nc = cc + dc[dir];
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < N; j++) {
        //         printf("%d ", map[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("----------------\n");
        // 종료 조건
        if (nr < 0 || nr >= N || nc < 0 || nc >= N || map[nr][nc] == 1) {
            return timer;
        }
        
        // 이동 가능하다면 이동. 근데 과일을 먹느냐 마느냐 차이
        if (map[nr][nc] == 2) {
            map[nr][nc] = 1;
        } else {
            map[nr][nc] = 1;
            map[tr][tc] = 0;
            pop();
        }
        push(nr,nc);
        cr = nr;
        cc = nc;
        
        
        // 시간을 보고, 대가리를 돌릴 시간이라면 돌린다.
        if (cmd < L) {
            int t = X[cmd];
            int c = CMD[cmd];
            if (timer == t) {
                if (c == 'L') {
                    dir-=1;
                    if (dir < 0) {
                        dir = 3;
                    }
                } else {
                    dir += 1;
                    if (dir > 3) {
                        dir = 0;
                    }
                }
                cmd++;
            }
        }
        
    }
}




void InputData(void){
    scanf("%d", &N);
    scanf("%d", &K);
    for (int i=0; i<K; i++){
        scanf("%d %d", &R[i], &C[i]);
        map[R[i]-1][C[i]-1] = 2;
    }
    scanf("%d", &L);
    for (int i=0; i<L; i++){
        scanf("%d %c", &X[i], &CMD[i]);
    }
}

int main(void){
    int ans = -1;

    InputData();//입력받는 부분

    //여기서부터 작성
    
    // 뱀 몸의 위치 정보 -> 큐와 map으로 관리
    // 이동한다 -> 큐에 머리 위치 추가, 0번(꼬리) pop.
    // map에 머리 위치 1, 꼬리 위치 0으로 갱신.
    // 이동하다가 자기 자신이나 벽에 부딪힌다? -> 게임 오버
    // 방향은 dir로 관리하다가 L 하면 -1, D이면 +1 해서 0 ~ 3번으로 관리.
    
    // 시작위치 0,0으로 하자 불편하다. -> 과일 위치 -1 -1
    ans = BFS(0,0);
    
    printf("%d\n", ans);//출력하는 부분
    return 0;
}