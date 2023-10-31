#include <stdio.h>
#define MAXN (100)
int N;//그림크기(정사각형)
char map[MAXN+10][MAXN+10];
int visited[MAXN+10][MAXN+10];
int sol1, sol2;
int wpoint;
int rpoint;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct Queue {
    int r;
    int c;
};

struct Queue queue[MAXN * MAXN + 10];

void push(int r, int c) {
    queue[wpoint].r = r;
    queue[wpoint].c = c;
    wpoint++;
}

void pop(void) {
    rpoint++;
}

int isEmpty(void) {
    return wpoint == rpoint;
}

struct Queue front(void) {
    return queue[rpoint];
}

void InputData(void){
    scanf("%d", &N);
    for (int h=1; h<=N; h++){
        scanf("%s", &map[h][1]);
    }
}

void BFS(int r, int c, char color) {
    visited[r][c] = 1;
    push(r,c);
    
    while(!isEmpty()) {
        struct Queue temp = front();
        pop();
        int cr = temp.r;
        int cc = temp.c;
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if ((1 <= nr && nr <= N) && (1 <= nc && nc <= N)) {
                if (visited[nr][nc] == 0 && map[nr][nc] == color) {
                    visited[nr][nc] = 1;
                    push(nr,nc);
                }
            }
        }
    }
}

int main(void){
    InputData();// 입력받는 부분

    // 여기서부터 작성
    // 색맹 없는 놈
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (visited[i][j] == 0) {
                BFS(i,j,map[i][j]);
                sol1++;
            }
        }
    }
    wpoint = 0;
    rpoint = 0;
    // 색맹 있는 놈
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] == 'G') {
                map[i][j] = 'R';
            }
            visited[i][j] = 0;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (visited[i][j] == 0) {
                BFS(i,j,map[i][j]);
                sol2++;
            }
        }
    }


    printf("%d %d\n", sol1, sol2);// 출력하는 부분
    return 0;
}