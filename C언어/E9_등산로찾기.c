#include <stdio.h>
#define MAXN (102)
int N;//산크기
int eh, ew;//목적지 위치 세로, 가로
int map[MAXN][MAXN];
// 필요한 힘의 양
int visited[MAXN][MAXN];
int wp;
int rp;
int ans;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct Queue {
    int r;
    int c;
};

struct Queue queue[500000];

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

int min(int a, int b) {
    return a >= b ? b : a;
}

void BFS(int sr, int sc) {
    // 바깥지역에서 시작한다고 하면, 시작점에서 보면 "올라갈 경우" 임
    visited[sr][sc] = map[sr][sc] * map[sr][sc];
    push(sr,sc);
    
    while(!isEmpty()) {
        struct Queue tempQ = front();
        pop();
        int cr = tempQ.r;
        int cc = tempQ.c;
        // printf("cr: %d, cc: %d\n", cr ,cc);
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if ((1 <= nr && nr <= N) && (1 <= nc && nc <= N)) {
                int needPower;
                if (map[nr][nc] > map[cr][cc]) {
                    needPower = (map[nr][nc] - map[cr][cc]) * (map[nr][nc] - map[cr][cc]);
                } else if (map[nr][nc] < map[cr][cc]) {
                    needPower = map[cr][cc] - map[nr][nc];
                } else {
                    needPower = 0;
                }
                // printf("nr: %d, nc: %d, needPower: %d, visited[nr][nc]: %d\n", nr ,nc, needPower, visited[nr][nc]);
                if (visited[nr][nc] > visited[cr][cc] + needPower) {
                    visited[nr][nc] = visited[cr][cc] + needPower;
                    push(nr,nc);
                }
            }
        }
        // for (int i = 1; i <= N; i++) {
        //     for (int j = 1; j <= N; j++) {
        //         printf("%d ", visited[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("--------------------------------\n");
    }
    ans = min(ans, visited[eh][ew]);
    
}




void InputData(void){
    scanf("%d", &N);
    scanf("%d %d", &eh, &ew);
    for (int h=1; h<=N; h++){
        for (int w=1; w<=N; w++){
            scanf("%d", &map[h][w]);
        }
    }
}

void initial(void) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            visited[i][j] = 2501;
        }
    }
    
    wp = 0;
    rp = 0;
}

int main(void){
    
    InputData();//입력 받는 부분

    //여기서부터 작성
    
    // 반복문 돌면서 테두리 시작점에서 BFS 시작
    // visited, wp, rp 초기화
    
    ans = 5000000;
    initial();
    for (int c = 1; c <= N; c++) {
        BFS(1, c);
    }
    initial();
    for (int r = 1; r <= N; r++) {
        BFS(r, 1);
    }
    initial();
    for (int r = 1; r <= N; r++) {
        BFS(r, N);
    }
    initial();
    for (int c = 1; c <= N; c++) {
        BFS(N, c);
    }
    printf("%d\n", ans);//출력하는 부분
    return 0;
}