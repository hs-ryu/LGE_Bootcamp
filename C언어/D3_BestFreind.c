#include <stdio.h>

#define MAX_N (300000)
#define MAX_LENGTH (20)

int N, K;
char name[MAX_N + 10][MAX_LENGTH + 10];
int Info[21][MAX_N];
int nameLengthCnt[21];
int wpList[21];
int rpList[21];
long long sol = 0;

void Input_Data(void) {
    int i;
    scanf("%d %d", &N, &K);
    for (i = 0; i < N; i++) {
        scanf("%s", name[i]);
        int nameLength = 0;
        for (int j = 0; name[i][j]; j++) {
            nameLength++;
        }
        // 등수 저장. 저장할때 확인하고. 범위 안맞으면 앞에부터 빼버리기.
        if (wpList[nameLength] == rpList[nameLength]) {
            Info[nameLength][wpList[nameLength]] = i+1;
            wpList[nameLength]++;
        } else {
            while (wpList[nameLength] != rpList[nameLength]) {
                int front = Info[nameLength][rpList[nameLength]];
                
                if (i+1 - front > K) {
                    rpList[nameLength]++;
                    
                } else {
                    Info[nameLength][wpList[nameLength]] = i+1;
                    wpList[nameLength]++;
                    break;
                }
            }
            
            if (wpList[nameLength] == rpList[nameLength]) {
                Info[nameLength][wpList[nameLength]] = i+1;
                wpList[nameLength]++;
            }
            sol += wpList[nameLength] - rpList[nameLength] - 1;
            
        }
    }
}


int main(void) {
    

    // 입력 받는 부분
    Input_Data();

    // 여기서부터 작성
    // for (int length = 2; length < 21; length++) {
    //     int tempList[MAX_N];
    //     // printf("\n length : %d\n", length);
    //     for (int i = 0; i < nameLengthCnt[length]; i++) {
    //         tempList[i] = Info[length][i];
    //         // printf("%d\n", tempList[i]);
    //     }
        
    //     for (int i = 0; i < nameLengthCnt[length]-1; i++) {
    //         int prev = tempList[i];
    //         for (int j = i+1; j < nameLengthCnt[length]; j++) {
    //             int next = tempList[j];
    //             // printf("%d %d\n", prev, next);
    //             if (next - prev > K) {
    //                 break;
    //             }
    //             sol++;
    //         }
    //     }
        
    // }    

    // 출력하는 부분
    printf("%lld\n", sol);

    return 0;
}