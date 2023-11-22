#include <stdio.h>
#include <string.h>

int N;
int visited[10010];

char S[10000+10][20+10];
void InputData(void){
    scanf("%d", &N);
    for (int i=1; i<=N; i++){
        scanf("%s", S[i]);
    }
}

int main(void){
    InputData();// 입력받는 부분

    // 여기서부터 작성
    int un = 0;
    for (int i = 1; i <= N; i ++) {
        if (visited[i]) {
            continue;
        }
        int isPrinted = 0;
        for (int j = i+1; j <= N; j++) {
            if (strcmp(S[i], S[j])) {
                continue;
            }
            if (isPrinted == 0) {
                isPrinted = 1;
                printf("%s %d ", S[i], i);
            }
            printf("%d ", j);
            visited[j] = 1;
        }
        if (isPrinted) {
            un = 1;
            printf("\n");
        }
    }
    
    if (un == 0) {
        printf("unique\n");
    }
    
    
    return 0;
}