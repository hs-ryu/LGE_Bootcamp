#include <stdio.h>
#define MAXN (100)
int C, R;//가로, 세로 크기
int sc, sr, ec, er;//출발 가로세로, 도착 가로세로 좌표
char map[MAXN+10][MAXN+10];//지도정보
int visited[MAXN+10][MAXN+10];// 방문 체크

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct Queue {
    int r;
    int c;
};

struct Queue queue[MAXN * MAXN + 10];
int wpoint, rpoint;

void push(int r, int c) {
    queue[wpoint].r = r;
    queue[wpoint].c = c;
    wpoint++;
}

void pop(void) {
    rpoint++;
}

int empty(void) {
    return wpoint == rpoint;
}

struct Queue front(void) {
    return queue[rpoint];
};

void InputData(void){
	scanf("%d %d", &C, &R);
	scanf("%d %d %d %d", &sc, &sr, &ec, &er);
	for (int i=0; i<R; i++){
		scanf("%s", &map[i][0]);
	}
}

void BFS(int r, int c) {
    push(r,c);
    visited[r][c] = 1;
    
    while (empty() == 0) {
        struct Queue tempQ = front();
        pop();
        int cr = tempQ.r;
        int cc = tempQ.c;
        // printf("%d %d\n", r, c);
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if ((0 <= nr && nr < R) && (0 <= nc && nc < C)) {
                // printf("%d %d 다음 \n", nr, nc);
                // printf("%d 방문 \n", visited[nr][nc]);
                // printf("%c 맵\n", map[nr][nc]);
                if (map[nr][nc] == '0') {
                    
                    if (visited[nr][nc] == 0) {
                        push(nr,nc);
                        visited[nr][nc] = visited[cr][cc] + 1;
                    }
                    if (nr == er-1 && nc == ec-1) {
                        
                        return;
                    }
                }
            }
        }
    }
}

int main(void){
	int ans = -1;
	InputData();//입력

	//여기서부터 작성
    BFS(sr-1, sc-1);

	printf("%d\n", visited[er-1][ec-1] - 1);//출력
	return 0;
}