#include <stdio.h>
 
int N;
int A[100+10];
int B[100+10];
 
int wp;
int rp;
 
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
 
int map[110][110];
int visited[110][110];
 
void InputData(void){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d %d", &A[i], &B[i]);
    }
}
 
struct Queue {
    int r;
    int c;
};
 
struct Queue queue[90000];
 
void push(int r, int c) {
    queue[wp].r = r;
    queue[wp].c = c;    
    wp++;
}
 
void pop() {
    rp++;
}
 
struct Queue front(void) {
    return queue[rp];
}
 
int isEmpty() {
    return wp == rp;
}
 
void drawing(int left, int top) {
    for (int i = top; i < top + 10; i++) {
        for (int j = left; j < left+10; j++) {
            map[i][j]++;
        }
    }
}
 
 
int BFS(int r, int c) {
    visited[r][c] = 1;
    push(r,c);
    int cnt = 0;
    while (!isEmpty()) {
        struct Queue tempQ = front();
        pop();
        int cr = tempQ.r;
        int cc = tempQ.c;
         
        for (int i = 0; i < 4 ; i ++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
 
            if ((0 <= nr && nr <= 101) && (0 <= nc && nc <= 101)) {
                if (visited[nr][nc] == 0 && map[nr][nc] == 0) {
                    visited[nr][nc] = 1;
                    push(nr,nc);
                }
                if (map[nr][nc] != 0) {
                    // printf("nr: %d, nc: %d \n", nr, nc);
                    cnt++;
                }
            }
        }
    }
    return cnt;
}
 
int main(void){
    int ans = 0;
 
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
     
    // 1번. 지도에 그리기
    for (int i = 0; i < N; i++) {
        drawing(A[i], B[i]);
    }
 
    // for (int i = 0; i < 101; i++) {
    //     for (int j = 0; j < 101; j++) { 
    //         printf("%d ", map[i][j]);
    //     }
    //     printf("\n");
    // }
 
    // 2번. 둘레 구하기
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (visited[i][j] == 0 && map[i][j] == 0) {
                int k = BFS(i,j);
                ans += k;
            }
        }
    } 
 
 
    printf("%d\n", ans);// 출력하는 부분
    return 0;
}