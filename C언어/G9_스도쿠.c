#include <stdio.h>
#define MAXN (9)
int sudoku[MAXN][MAXN];
int emptyArea[82][2];
int emptyAreaCnt;
int isFind = 0;
void InputData(void){
    emptyAreaCnt = 0;
    for (int r=0; r<MAXN; r++){
        for (int c=0; c<MAXN; c++){
            scanf("%d", &sudoku[r][c]);
            if (sudoku[r][c] == 0) {
                emptyArea[emptyAreaCnt][0] = r;
                emptyArea[emptyAreaCnt][1] = c;
                emptyAreaCnt++;
            }
        }
    }
}

void OutputData(void){
    for (int r=0; r<MAXN; r++){
        for (int c=0; c<MAXN; c++){
            printf("%d ", sudoku[r][c]);
        }
        printf("\n");
    }
}

// 가로 체크, 세로 체크, 3 x 3 체크
int isPossible(int r, int c, int num) {
    // 만약 4,1이 들어왔다?
    int visitedRow[10] = {0,};
    int visitedCol[10] = {0,};
    int visitedSquare[10] = {0,};
    
    // 가로 확인
    // 일단 0은 빼고 가자.
    visitedRow[num] = 1; 
    for (int i = 0; i < 9; i++) {
        if (sudoku[r][i] == 0) {
            continue;
        }
        if (visitedRow[sudoku[r][i]] == 1) {
            return 0;
        }
        visitedRow[sudoku[r][i]]++;
    }
    // for (int i = 0 ; i < 10; i++) {
    //     printf("%d ",visitedRow[i]);
    // }
    
    // 세로 확인
    // 일단 0은 빼고 가자.
    visitedCol[num] = 1; 
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][c] == 0) {
            continue;
        }
        if (visitedCol[sudoku[i][c]] == 1) {
            return 0;
        }
        visitedCol[sudoku[i][c]]++;
    }
    // printf("\n");
    // for (int i = 0 ; i < 10; i++) {
    //     printf("%d ",visitedCol[i]);
    // }
    
    // 3 x 3 사각형 확인
    // 3 x 3 사각형의 시작점 : 
    // (0, 0), (0, 3), (0, 6)
    // (3, 0), (3, 3), (3, 6)
    // (6, 0), (6, 3), (6, 6),
    
    visitedSquare[num] = 1;
    // 현재 좌표를 통해 3 x 3의 시작점 설정
    int sr = 3 * (r / 3);
    int sc = 3 * (c / 3);
    for (int i = sr; i < sr + 3; i++) {
        for (int j = sc; j < sc + 3; j++) {
            if (sudoku[i][j] == 0) {
                continue;
            }
            if (visitedSquare[sudoku[i][j]] == 1) {
                return 0;
            }
            visitedSquare[sudoku[i][j]]++;
        }
    }
    // printf("\n");
    // for (int i = 0 ; i < 10; i++) {
    //     printf("%d ",visitedSquare[i]);
    // }
    return 1;
}

void DFS(int level) {
    if (isFind) {
        return;
    }
    
    if (level == emptyAreaCnt) {
        isFind = 1;
        OutputData();
        return;
    }
    
    int target_r = emptyArea[level][0];
    int target_c = emptyArea[level][1];
    
    for (int num = 1; num < 10; num++) {
        if (isPossible(target_r, target_c, num)) {
            sudoku[target_r][target_c] = num;
            DFS(level+1);
            sudoku[target_r][target_c] = 0;
        }
    }
}




int main(void){
    InputData();//입력받는 부분

    //여기서부터 작성
    // for (int i = 0; i < emptyAreaCnt; i++) {
    //     printf("r: %d, c: %d \n", emptyArea[i][0], emptyArea[i][1]);
    // }
    
    // isPossible(1,4,4);
    DFS(0);

    // OutputData();//출력하는 부분
    return 0;
}







