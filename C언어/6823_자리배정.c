#include <stdio.h>

int C, R, K;
int X, Y;
// 상, 우, 하, 좌
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

void InputData(void) {
	scanf("%d %d", &C, &R);
	scanf("%d", &K);
}

int main(void)
{
	// 입력받는 부분
	InputData();

    if (C * R < K) {
        printf("%d", 0);
    }
    else {
        int visited[1001][1001];

        int cr = R-1;
        int cc = 0;
        int dir = 0;
        int x = 1;
        visited[cr][cc] = 1;
        int nr = cr;
        int nc = cc;
        while (x != K) {
            nr = cr + dr[dir];
            nc = cc + dc[dir];
            
            if ((0 <= nr && nr < R) && (0 <= nc && nc < C) && visited[nr][nc] == 0) {
                x += 1;
                visited[nr][nc] = x;
                cr = nr;
                cc = nc;
            }
            else {
                dir ++;
                if (dir == 4) {
                    dir = 0;
                }
            }
        }
        // 출력하는 부분

        // (0,5) -> 6,6
        // (2,6) -> 7,4
        // (0,6) -> 7,6
        // (r,c) -> (nc+1, r-nr)
        printf("%d %d", nc+1, R-nr);

    }
	// 여기서부터 작성
    
	return 0;
}