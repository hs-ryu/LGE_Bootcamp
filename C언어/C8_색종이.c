#include <stdio.h>
#include <string.h>
int N;//색종이 수
int X[100+10];
int Y[100+10];
int map[100+10][100+10];
int visited[100+10][100+10];

void InputData(void) {
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d %d", &X[i], &Y[i]);
    }
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

void drawing(int left, int top) {
    for (int i = top; i < top + 10; i++) {
        for (int j = left; j < left+10; j++) {
            map[i][j] = 1;
        }
    }
}

void makeHeight(int r, int c) {
    visited[r][c] = 1;
    for (int nr = r+1; map[nr][c]; nr++) {
        visited[nr][c] = visited[nr-1][c] + 1;
    }
}

int search(int r, int c) {
    int cnt = 0;
    int minH = visited[r][c];
    int maxArea = 0;
    int tempArea = 0;
    for (int nc = c; map[r][nc]; nc++) {
        cnt++;
        minH = min(minH,visited[r][nc]);
        tempArea = cnt * minH;
        maxArea = max(maxArea, tempArea);
    }
    return maxArea;
}


int main(void) {
    int ans = 100;
    InputData();//입력받는 부분
    
    //여기서부터 작성
    // 1. 그리기
    for (int i = 0; i < N; i++) {
        drawing(X[i], Y[i]);
    }
    
    // for (int i = 0; i < 30; i++) {
    //     for (int j = 0; j < 30; j++) {
    //         printf("%d ", map[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // 2. 각 열마다 높이 저장
    for (int c = 0; c < 100; c++) {
        for (int r = 0; r < 100; r++) {
            if (visited[r][c] == 0 && map[r][c] == 1) {
                makeHeight(r,c);
            }
        }
    }

    // for (int i = 0; i < 30; i++) {
    //     for (int j = 0; j < 30; j++) {
    //         printf("%d ", visited[i][j]);
    //     }
    //     printf("\n");
    // }
    
    for (int r = 0; r < 101; r++) {
        for (int c = 0; c < 101; c++) {
            if (map[r][c] == 1) {
                int k = search(r,c);
                if (k > ans) {
                    ans = k;
                }
            }
        }
    }
    
    
    printf("%d\n", ans);//출력하는 부분
    return 0;
}