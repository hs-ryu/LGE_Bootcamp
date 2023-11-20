#include <stdio.h>

int N, P;
int visited[98];

void InputData(void){
    scanf("%d %d", &N, &P);
}

int main(void){
    int ans = 0;
    InputData();// 입력받는 부분

    int num = N;
    // 여기서부터 작성
    while (1) {
        num = (num * N) % P;
        if (visited[num] == 2) {
            break;
        }
        visited[num]++;
    }

    for (int i = 0; i < 98; i++) {
        if (visited[i] == 2) {
            ans++;
        }
    }

    printf("%d", ans);// 출력하는 부분
    return 0;
}