#include <stdio.h>
#include <stdlib.h>
#define MAXW (20)
int N;//도로의 개수
int W;//사건의 개수
int ans = 1001 * 20;
struct POS{
	int r, c;//세로, 가로
};
struct POS pos[MAXW+10];//사건 좌표

int movingCnt(int sr, int sc, int er, int ec) {
    return abs(sr - er) + abs(sc - ec);
}


void InputData(void) {
	scanf("%d", &N);
	scanf("%d", &W);
	for (int i=0; i<W; i++){
		scanf("%d %d", &pos[i].r, &pos[i].c);
	}
}

void DFS(int r1, int c1, int r2, int c2, int level, int total) {
    // 1. 가지치기
    if (total > ans) {
        return;
    }
    
    // 2. 종료조건
    if (level >= W) {
        ans = total;
        return;
    }
    
    
    int target_r = pos[level].r;
    int target_c = pos[level].c;
    // printf("경찰차1 : %d %d, 경찰차2 : %d %d, 현재 타겟: %d %d, 이동 총 위치: %d\n", r1, c1, r2, c2, level, total);
    // 3. 다음 뎁스
    // 1번 경찰차 이동
    DFS(target_r, target_c, r2, c2, level+1, total + movingCnt(r1, c1, target_r, target_c));
    // 2번 경찰차 이동
    DFS(r1, c1, target_r, target_c, level+1, total + movingCnt(r2, c2, target_r, target_c));
}





int main(void) {
	
	InputData();//입력받는 부분

	//여기서부터 작성
	
	
	DFS(1,1,N,N,0,0);
	// 경찰차 1을 이동시켜보기
	// 경찰차 2를 이동시켜보기

	printf("%d\n", ans);//출력하는 부분
	return 0;
}