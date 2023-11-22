#include <stdio.h>

int N, D, K, C;
int A[3000000+10];

void InputData(void){
    scanf("%d %d %d %d", &N, &D, &K, &C);
    for (int i=0; i<N ; i++){
        scanf("%d", &A[i]);
    }
}

int main(void){

    InputData();// 입력받는 부분

    // 여기서부터 작성
    // 일단, 리스트에 K개 만큼 채워 넣자. 레일 첫번째 부터
    int selected_list[10000];
    int kinds = 0;
    int maximum_kinds = 0;
    for (int i = 0; i < K; i++) {
        if (selected_list[A[i]] == 0) {
            kinds++;
        }
        selected_list[A[i]]++;
    }

    if (selected_list[C] == 0) {
        maximum_kinds = kinds + 1;
    } else {
        maximum_kinds = kinds;
    }

    for (int i = 1; i < N; i++) {
        selected_list[A[i-1]]--;
        if (selected_list[A[i-1]] == 0) {
            kinds--;
        }

        if (i + K - 1 < N) {
            if (selected_list[A[i+K-1]] == 0) {
                kinds++;
            }
            selected_list[A[i+K-1]]++;
        } else {
            if (selected_list[A[i + K - 1 - N]] == 0) {
                kinds++;
            }
            selected_list[A[i + K - 1 - N]]++;
        }

        if (selected_list[C] == 0) {
            if (maximum_kinds < kinds + 1) {
                maximum_kinds = kinds + 1;
            }
        } else {
            if (maximum_kinds < kinds) {
                maximum_kinds = kinds;
            }
        }
    }

    printf("%d\n", maximum_kinds);// 출력하는 부분
    return 0;
}