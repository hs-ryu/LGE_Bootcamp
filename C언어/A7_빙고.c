#include <stdio.h>

int A[5+10][5+10];
int B[25+10];
int visited[5+10][5+10];

void InputData(void){
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            scanf("%d", &A[i][j]);
        }
    }
    for (int i=0; i<25; i++){
        scanf("%d", &B[i]);
    }
}

int main(void){
    int ans = -1;
    InputData();// 입력받는 부분

    // 여기서부터 작성
    int s;
    for (s = 0; s < 25; s++) {
        int bingoCnt = 0;
        // 찾아서 체크하기
        int now_say = B[s];
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                if (A[r][c] == now_say) {
                    visited[r][c] = 1;
                }
            }
        }

        // 빙고 확인
        // 상,하,좌,우,대각
        // 0,0에 체크를 한 상태라면 오른쪽 아래 방향 대각선 확인
        if (visited[0][0]) {
            int isDaegakFine = 1;
            for (int k = 0; k < 5; k++) {
                if (visited[k][k] != 1) {
                    isDaegakFine = 0;
                    break;
                }
            }
            if (isDaegakFine == 1) {
                bingoCnt++;
            }
        }
        // 0,4에 체크를 한 상태라면 왼쪽 아래 방향 대각선 확인
        if (visited[0][4]) {
            int isDaegakFine = 1;
            for (int k = 0; k < 5; k++) {
                if (visited[k][4-k] != 1) {
                    isDaegakFine = 0;
                    break;
                }
            }
            if (isDaegakFine == 1) {
                bingoCnt++;
            }
        }


        // 가로, 세로 확인. 그냥 
        for (int i = 0; i < 5; i ++) {
            if (visited[i][0] == 1 && visited[i][1] == 1 && visited[i][2] == 1 && visited[i][3] == 1 && visited[i][4] == 1) {
                bingoCnt++;
            }
            if (visited[0][i] == 1 && visited[1][i] == 1 && visited[2][i] == 1 && visited[3][i] == 1 && visited[4][i] == 1) {
                bingoCnt++;
            }
        }

        if (bingoCnt >= 3) {
            ans = s + 1;
            break;
        }

    }

    printf("%d\n", ans);// 출력하는 부분
    return 0;
}