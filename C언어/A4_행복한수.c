#include <stdio.h>
#include <string.h>

int N;
int visited[1001];
void InputData(void){
    scanf("%d", &N);
}

int main(void){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    
    for (int i = N; i > 0; i--) {
        int num = i;
        int sum = 0;
        memset(visited, 0, sizeof(int));
        int loop = 0;
        while (1) {
            while (num != 0) {
                sum += (num % 10) * (num % 10);
                num = num / 10;
            }
            if (visited[sum]) {
                loop = 1;
                break;
            }
            visited[sum] = 1;
            num = sum;
            sum = 0;
        }
        if (loop == 1) {
            if (visited[1]) {
                ans = i;
                break;
            }
        }
    }

    printf("%d\n", ans);// 출력하는 부분
    return 0;
}