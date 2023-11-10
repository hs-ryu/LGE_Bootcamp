#include <stdio.h>
#include <string.h>
#define MAXN (50)
#define INF (MAXN*MAXN)
int H, W;//세로, 가로
char map[MAXN + 10][MAXN + 10];
int newmap[MAXN + 10][MAXN + 10];
int wpoint;
int rpoint;
int changeVisited[MAXN+10][MAXN+10];
int visited[MAXN+10][MAXN+10];
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};
int count[4][4] = {{0,0,0,0},{0,0,2501,2501},{0,2501,0,2501},{0,2501,2501,0}};

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

int isEmpty(void) {
    return wpoint == rpoint;
}

struct Queue front(void) {
    return queue[rpoint];
}

void InputData(void) {
	scanf("%d %d", &H, &W);
	for (int i = 1; i <= H; i++) {
		scanf("%s", &map[i][1]);
	}
}

void change(int r, int c, int id) {
    push(r,c);
    changeVisited[r][c] = 1;
    newmap[r][c] = id;
    
    while (!isEmpty()) {
        struct Queue temp = front();
        pop();
        
        for (int i = 0; i < 4; i++) {
            int nr = temp.r + dr[i];
            int nc = temp.c + dc[i];
            
            if ((1 <= nr && nr <= H) && (1 <= nc && nc <= W)) {
                if (map[nr][nc] == 'X' && changeVisited[nr][nc] == 0) {
                    push(nr,nc);
                    newmap[nr][nc] = id;
                    changeVisited[nr][nc] = 1;
                }
            }
        }
    }
}

void BFS(int r, int c, int id) {
    push(r,c);
    while (!isEmpty()) {
        struct Queue temp = front();
        pop();
        int cr = temp.r;
        int cc = temp.c;
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if ((1 <= nr && nr <= H) && (1 <= nc && nc <= W)) {
                if (visited[nr][nc] == 0 && newmap[nr][nc] != id) {
                    if (newmap[nr][nc] == 0) {
                        push(nr,nc);
                        visited[nr][nc] = visited[cr][cc] + 1;
                    }
                    else if (newmap[nr][nc] != id) {
                        if (count[id][newmap[nr][nc]] > visited[cr][cc]) {
                            count[id][newmap[nr][nc]] = visited[cr][cc];
                        }
                    }
                }
                
            }
        }
    }
}


int main(void) {
	int ans = 7500;
	InputData();//입력

	//여기서부터 작성
	
	// X 표시 된 곳들을 3개의 영역으로 나누기.
	int id = 1;
	for (int i = 1; i <= H; i++) {
	    for (int j = 1; j <= W; j++) {
	        if (map[i][j] == 'X') {
	            if (changeVisited[i][j] == 0) {
	                change(i,j,id);
	                id++;
	            }
	        }
	    }
	}
	
	wpoint = 0;
	rpoint = 0;
	
	// 3개 표시된 영역에서, 각각 다른 점으로 가기 위한 최단 경로 계산하기.
	for (int i = 1; i <= H; i++) {
	    for (int j = 1; j <= W; j++) {
	        if (newmap[i][j] != 0) {
	            BFS(i,j,newmap[i][j]);
	            memset(visited, 0, sizeof(visited));
	        }
	    }
	}
    for (int i = 1; i < 4; i++) {
        int total = 0;
        for (int j = 1; j < 4; j++) {
            if (i==j) {
                continue;
            }
            total += count[i][j];
        }
        if (total < ans) {
            ans = total;
        } 
        
    }
	printf("%d\n", ans);//출력
	return 0;
}
