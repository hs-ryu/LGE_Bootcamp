#include <stdio.h>
#define MAXN ((int)1e3)
int M, N;//상자의 가로, 세로 칸 수
int map[MAXN+10][MAXN+10];//토마토 정보
int visited[MAXN+10][MAXN+10];
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

struct Queue pop(void) {
    struct Queue temp;
    temp.r = queue[rpoint].r;
    temp.c = queue[rpoint].c;
    rpoint++;
    return temp;
};

int empty(void) {
    return wpoint == rpoint;
}

void BFS(void) {
    while (empty() == 0) {
        struct Queue tempQ = pop();
        int cr = tempQ.r;
        int cc = tempQ.c;
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if ((0 <= nr && nr < N) && (0 <= nc && nc < M)) {
                if ((visited[nr][nc] == 0) && (map[nr][nc] != -1)) {
                    visited[nr][nc] = visited[cr][cc] + 1;
                    push(nr,nc);
                }
            }
        }
    }
}

int FindMaximumDay() {
    int maxDay = 0;
    int cnt = 0;
    int noneCnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == -1) {
                noneCnt++;
            }
            else if (visited[i][j] != 0) {
                cnt++;
                if (visited[i][j] > maxDay) {
                    maxDay = visited[i][j];
                }
            }
        }
    }

    if (noneCnt + cnt !=  M * N) {
        return 0;
    } else {
        return maxDay;
    }

}

void InputData(void){
	scanf("%d %d", &M, &N);
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			scanf("%d", &map[i][j]);
		}
	}
}

int main(void){
	InputData();//입력

	//여기서부터 작성

    int cnt = 0;
    // 맵에 있는 토마토들 위치 큐에 집어 넣기.
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (map[i][j] == 1) {
                push(i,j);
                visited[i][j] = 1;
                cnt++;
            }
        }
    }

    if (cnt == (M * N)) {
        printf(0);
    } else {
        BFS();
        int result = FindMaximumDay();
        printf("%d\n", result - 1);//출력
    }
	
	return 0;
}