#include <stdio.h>
#define MAXN ((int)1e4)
int N;
int X;
int Y;
int maps[102][102];
int visited[102][102];
int wpoint;
int rpoint;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct Queue {
    int r;
    int c;
};

struct Queue queue[MAXN * MAXN];

void push(int r, int c) {
    queue[wpoint].r = r;
    queue[wpoint].c = c;
    wpoint++;
}

void pop(void) {
    rpoint++;
}

struct Queue front(void) {
    return queue[rpoint];
}

int isEmpty(void) {
    return wpoint == rpoint;
}

// 핵심은 배열 밖의 테두리 하나 씌우는거.
int BFS(int r, int c) {
    int cnt = 0;
    push(r,c);
    visited[r][c] = 1;

    while (!isEmpty()) {
        struct Queue temp = front();
        pop();
        int cr = temp.r;
        int cc = temp.c;
        
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if ((0 <= nr && nr <= 101) && (0 <= nc && nc <= 101) && maps[nr][nc] == 0) {
                if (visited[nr][nc] == 0) {
                    push(nr,nc);
                    visited[nr][nc] = 1;
                    for (int j = 0; j < 4; j++) {
                        int nnr = nr + dr[j];
                        int nnc = nc + dc[j];
                        if ((0 <= nnr && nnr <= 101) && (0 <= nnc && nnc <= 101) && maps[nnr][nnc] == 1) {
                            cnt++;
                        }
                    }
                }
            }
        }
    }


    return cnt;
}


void InputData(void){
	scanf("%d", &N);
	for (int i=0; i<N; i++){
		scanf("%d %d", &X, &Y);
        maps[Y][X] = 1;
	}
}

int main(void){
	int ans = 0;
	InputData();// 입력받는 부분

	// 여기서부터 작성
    ans = BFS(0,0);
	printf("%d\n", ans);// 출력하는 부분
	return 0;
}