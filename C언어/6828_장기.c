#include <stdio.h>
#define MAX 101

int N, M;//장기판 행의 수, 열의 수
int R, C, S, K;//말 행과 열, 졸 행과 열

int visited[MAX][MAX];

// 1시, 2시, 4시, 5시, 7시, 8시, 10시, 11시
int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};

struct Queue {
    int r;
    int c;
};

struct Queue queue[MAX * MAX];
int wpoint, rpoint;

void push(int r, int c) {
    queue[wpoint].r = r;
    queue[wpoint].c = c;
    wpoint++;
}

void pop(void) {
    rpoint++;
}

int empty() {
    return wpoint == rpoint;
}

struct Queue front(void) {
    return queue[rpoint];
}

void InputData(void){
	scanf("%d %d", &N, &M);
	scanf("%d %d %d %d", &R, &C, &S, &K);
}

void BFS(int r, int c) {
    push(r,c);
    visited[r][c] = 1;

    while (empty() == 0) {
        struct Queue tempQ = front();
        pop();
        int cr = tempQ.r;
        int cc = tempQ.c;

        for (int i=0; i < 8; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if ((0 <= nr && nr < N) && (0 <= nc && nc < M)) {
                if (visited[nr][nc] == 0) {
                    visited[nr][nc] = visited[cr][cc] + 1;
                    push(nr,nc);
                }

                if ((nr == S - 1) && (nc == K - 1)) {
                    return;
                }
            
            }
        }
    }
}

int main(void){
	InputData();//입력

	//여기서부터 작성
    BFS(R-1, C-1);
	printf("%d\n", visited[S-1][K-1] - 1);//출력
	return 0;
}