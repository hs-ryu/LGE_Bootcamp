#include <stdio.h>
#include <string.h>
#define MAX_SIZE (30)

int L, R, C;
char map[MAX_SIZE+10][MAX_SIZE+10][MAX_SIZE+10];
int visited[MAX_SIZE+10][MAX_SIZE+10][MAX_SIZE+10];
int wp;
int rp;
int sh, sr, sc;

// 상, 하, 좌, 우, 위, 아래
int dr[6] = {-1, 1, 0, 0, 0, 0};
int dc[6] = {0, 0, -1, 1, 0, 0};
int dh[6] = {0, 0, 0, 0, -1, 1};

struct Queue {
    int r;
    int c;
    int h;
};

struct Queue queue[31 * 31 * 31];

void push(int h, int r, int c) {
    queue[wp].r = r;
    queue[wp].c = c;
    queue[wp].h = h;
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

int InputData(void){
    scanf("%d %d %d", &L, &R, &C);
    if ((L == 0) && (R == 0) && (C == 0)) return 0;
    for (int l=0; l<L;l++){
        for (int r=0; r<R; r++){
            scanf("%s", map[l][r]);
        }
    }
    return 1;
}


int BFS(int sh, int sr, int sc) {
    visited[sh][sr][sc] = 1;
    push(sh,sr,sc);
    
    while (!isEmpty()) {
        struct Queue temp = front();
        pop();
        
        int ch = temp.h;
        int cr = temp.r;
        int cc = temp.c;
        for (int i = 0; i < 6; i++) {
            int nh = ch + dh[i];
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if ((0 <= nh && nh < L) && (0 <= nr && nr < R) && (0 <= nc && nc < C) && (map[nh][nr][nc] != '#')) {
                if (visited[nh][nr][nc] == 0) {
                    visited[nh][nr][nc] = visited[ch][cr][cc] + 1;
                    push(nh,nr,nc);
                }
                if (map[nh][nr][nc] == 'E') {
                    return visited[ch][cr][cc];
                }
            }
        }
    }
    return -1;
}



int main(void){
    int ans = 0;
    while(InputData()){
        wp = 0;
        rp = 0;
        //여기서부터 작성
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    visited[i][j][k] = 0;
                }
            }
        }
        for (int h = 0; h < L; h++) {
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++){
                    if (map[h][r][c] == 'S') {
                        sh = h;
                        sr = r;
                        sc = c;
                    }
                }
            }
        }
        
        ans = BFS(sh,sr,sc);

        if (ans == -1) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", ans);
    }
    return 0;
}