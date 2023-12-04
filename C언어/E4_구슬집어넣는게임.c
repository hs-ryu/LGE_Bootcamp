#include <stdio.h>
#define MAXN (15)
int R, C;//게임판 행(세로), 열(가로) 크기
char map[MAXN+5][MAXN+5];//게임판('#':벽, '.':빈공간, 'R':빨간구슬, 'B':파란구슬, 'H':목표구멍)
int wp;
int rp;
int ans;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int min(int a, int b) {
    if (a >= b) {
        return b;
    }
    return a;
}

struct Queue {
    int r;
    int c;
    int cnt;
};

struct Queue queue[2][500000];

void push(int rr,int rc, int br, int bc, int cnt) {
    queue[0][wp].r = rr;
    queue[0][wp].c = rc;
    queue[1][wp].r = br;
    queue[1][wp].c = bc;
    queue[0][wp].cnt = cnt;
    queue[1][wp].cnt = cnt;
    wp++;
}

void pop(void) {
    rp++;
}

struct Queue redFront(void) {
    return queue[0][rp];
}

struct Queue blueFront(void) {
    return queue[1][rp];
}

int isEmpty(void) {
    return wp == rp;
}

void BFS(int rr, int rc, int br, int bc) {
    push(rr, rc, br, bc, 0);
    
    while (!isEmpty()) {
        struct Queue redBall = redFront();
        struct Queue blueBall = blueFront();
        int cnt = redBall.cnt;
        pop();
        
        for (int i = 0; i < 4; i++) {
            int nrr = redBall.r + dr[i];
            int nrc = redBall.c + dc[i];
            int nbr = blueBall.r + dr[i];
            int nbc = blueBall.c + dc[i];
            
            // 파란색 공 위치 설정
            // 만약 벽을 마주친다면? 현재 위치 고수
            if ((0 <= nbr && nbr < R) && (0 <= nbc && nbc < C)) {
                if (map[nbr][nbc] == '#') {
                    nbr = blueBall.r;
                    nbc = blueBall.c;
                } else if (map[nbr][nbc] == 'H') {
                    continue;
                }
            }
            
            // 빨간 색 구슬이 갈 수 있는 범위
            if ((0 <= nrr && nrr < R) && (0 <= nrc && nrc < C)) {
                // printf("redr: %d, redc: %d, bluer:%d bluec: %d , cnt: %d\n", nrr, nrc, nbr, nbc, cnt);
                // // 파란색 공을 만나면 안됨.
                if ((nrr == nbr && nrc == nbc)) {
                    continue;
                }
                // // 제자리에도 있을 수 있음.
                if (map[nrr][nrc] == '#') {
                    nrr = redBall.r;
                    nrc = redBall.c;
                }
                // 
                if (map[nrr][nrc] == 'H') {
                    ans = min(ans, cnt+1);
                }
                
                if (cnt+1 <= 9) {
                    push(nrr, nrc, nbr, nbc, cnt+1);
                }
                
                
            }
        }
    }
}




void InputData(void){
	scanf("%d %d", &R, &C);
	for (int i=0; i<R; i++){
		scanf("%s", map[i]);
	}
}
int main(void){
	int T;
    
	scanf("%d", &T);
	for (int i=0; i<T; i++){
		InputData();//입력
        ans = 11;
        wp = 0;
        rp = 0;
		//여기서부터 작성
		
		// 1. 빨간구슬, 파란구슬 위치 찾기
		int rr = 0;
		int rc = 0;
		int br = 0;
		int bc = 0;
		for (int i = 0; i < R; i++) {
		    for (int j = 0; j < C; j++) {
		        if (map[i][j] == 'R') {
		            rr = i;
		            rc = j;
		        }
		        else if (map[i][j] == 'B') {
		            br = i;
		            bc = j;
		        }
		    }
		}
		
		BFS(rr,rc,br,bc);
		// 2. BFS. visited는 빨간색 구슬 기준. 근데 파란색 구슬도 큐로는 관리해줘야함.
        if (ans == 11) {
            ans = -1;
        }
		printf("%d\n", ans);//출력
	}
	return 0;
}