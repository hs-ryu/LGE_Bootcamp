#include <stdio.h>
#define MAXN (6)
int win[MAXN+10], lose[MAXN+10], draw[MAXN+10];
int sol[4+10];
int info[6][3];
int games[15][2];
void InputData(void){
	for (int i=0; i<MAXN; i++){
		scanf("%d %d %d", &win[i], &draw[i], &lose[i]);
	}
}
void OutputData(void){
	for (int i=0; i<4; i++){
		printf("%d ", sol[i]);
	}
	printf("\n");
}

// 방법 1. DFS -> 경우의 수. 백트래킹 조건?
int result;

void DFS(int level) {
    if (result == 1) {
        return;
    }

    if (level == 15) {
        result = 1;
        return;
    }

    int teamA = games[level][0];
    int teamB = games[level][1];

    if (info[teamA][0] && info[teamB][2]) {
        info[teamA][0]--;
        info[teamB][2]--;
        DFS(level+1);
        info[teamA][0]++;
        info[teamB][2]++;
    }

    if (info[teamA][1] && info[teamB][1]) {
        info[teamA][1]--;
        info[teamB][1]--;
        DFS(level+1);
        info[teamA][1]++;
        info[teamB][1]++;
    }

    if (info[teamA][2] && info[teamB][0]) {
        info[teamA][2]--;
        info[teamB][0]--;
        DFS(level+1);
        info[teamA][2]++;
        info[teamB][0]++;
    }

}



int main(void){
    
	for (int x=0; x<4; x++){
		InputData();// 입력받는 부분
		result = 0;
		for (int i = 0; i < 6; i++) {
		    info[i][0] = win[i];
		    info[i][1] = draw[i];
		    info[i][2] = lose[i];
		}
        
        int isPossible = 1;
        for (int i = 0; i < 6; i++) {
            if (info[i][0] + info[i][1] + info[i][2] != 5) {
                isPossible = 0;
                break;
            }
        }
        
        if (!isPossible) {
            sol[x] = result;
        }
        else {
            int idx = 0;
            for (int i = 0; i < 5; i++) {
                for (int j = i+1; j < 6; j++) {
                    games[idx][0] = i;
                    games[idx][1] = j;
                    idx++;
                }
            }
            
            DFS(0);
            sol[x] = result;
        }
	}

	OutputData();// 출력하는 부분
	return 0;
}