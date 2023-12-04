#include <stdio.h>
#include <string.h>
int N;
int W[21 + 5];
int countingLength[21][9 + 5];

int select[21 + 5] = {0};
int ans;
void InputData(void){
    scanf("%d", &N);
    for (int i=0 ; i<N ; i++){
        scanf("%d", &W[i]);
    }
}

// 각 숫자를 자릿수로 쪼개는 함수
void countLength(int idx, int num) {
    int i = 0;
    while (1) {
        countingLength[idx][i] = num % 10;
        // printf("%d ", countingLength[idx][i]);
        num /= 10;
        i++;
        if (num == 0) {
            break;
        }
    }
    // printf("\n");
}

int max(int a, int b) {
    return a > b ? a : b;
}

int checkOver(void) {
    // 현재까지의 합을 쪼개기
    // int sumArr[9 + 5] = {0, };
    // int i = 0;
    // while (1) {
    //     sumArr[i] = sum % 10;
    //     sum /= 10;
    //     if (sum == 0) {
    //         break;
    //     }
    //     i++;
    // }
    int tempSum[9 + 5] = {0, };
    int cnt = 0;
    
    for (int i = 0; i < N; i++) {
        if (select[i] == 0) {
            continue;
        }
        for (int j = 0; countingLength[i][j] != -1; j++) {
            // printf("countingLength[i][j]: %d ", countingLength[i][j]);
            // printf("\n");
            tempSum[j] += countingLength[i][j];
            cnt = max(cnt, j);
            // if (tempSum[j] >= 4) {
            //     printf("tempSum[j]: %d", tempSum[j]);
            // }
        }
    }
    
    // for (int i = 0; i < 10; i++) {
    //     printf("%d ", tempSum[i]);
    // }
    
    
    for (int i = 0; i < cnt; i++) {
        if (tempSum[i] >= 10) {
            // printf("\n");
            return 1;
        }
    }
    // printf("\n");
    
    return 0;
}


void DFS(int level, int cnt) {  // 현재 소, 소를 선택한 개수
    // 자릿수 올림 판별
    // 선택한 소들의 쪼갠 자릿수를 더해서, 자릿수가 10보다 큰게 있다면 true, 아니면 false.
    if (checkOver()) {
        return;
    }
    if (level >= N) {
        if (cnt >= ans) {
            ans = cnt;
            // for (int i = 0; i < N; i++) {
            //     printf("%d ", select[i]);
            // }
            // printf("\n");
        }
        // for (int i = 0; i < N; i++) {
        //     printf("%d ", select[i]);
        //     for (int j = 0; countingLength[i][j]; j++) {
        //         printf("%d ", countingLength[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
        return;
    }
    
    select[level] = 1;      // 선택 해보기
    DFS(level+1, cnt+1);    // 선택하고 넣는거니까 cnt + 1
    select[level] = 0;      // 선택 안해보기
    DFS(level+1, cnt);      // 선택 안하고 넣는거니까 cnt 유지
}


int main(void){
    ans = 1;

    InputData();// 입력받는 부분
    
    // 1. 각 숫자의 자릿수 구하기. 굳
    memset(countingLength, -1, sizeof(countingLength));
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; countingLength[i][j]; j++) {
    //         printf("%d ", countingLength[i][j]);
    //     }
    //     printf("\n");
    // }
    for (int i = 0; i < N; i++) {
        countLength(i, W[i]);
    }
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; countingLength[i][j] != -1; j++) {
    //         printf("%d ", countingLength[i][j]);
    //     }
    //     printf("\n");
    // }
    
    // 여기서부터 작성
    DFS(0, 0);
    

    printf("%d\n", ans);//출력하는 부분
    return 0;
}