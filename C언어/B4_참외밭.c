#include <stdio.h>
 
int K;
int A[12+10];
int B[12+10];
void InputData(void){
    scanf("%d", &K);
    for (int i=0 ; i<6 ; i++){
        scanf("%d %d", &A[i], &B[i]);
    }
     
    for (int i=0; i<6; i++) {
        A[i+6] = A[i];
        B[i+6] = B[i];
    }
     
}
 
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
 
int main(void){
    int ans = -1;
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    // 세로방향, 가로 방향 확인
    // 세로방향 짧은거 2개 더하면 긴거 하나 나올거임 (3,4)
    // 가로 방향 짧은거 2개 더하면 긴거하나 나올거임 (1,2)
     
    // 잘 판단해서 빈 부분을 빼자
    // 동 : 1
    // 서 : 2
    // 남 : 3
    // 북 : 4
    // 사각형이 되려면, 서,남,동,북 의 방향이어야하는데
    int maxW = 0;   // 가로 최대 길이
    int maxH = 0;   // 세로 최대 길이
    for (int i = 0; i < 6; i++) {
        int direction = A[i];
        int length = B[i];
        // 세로 최대값 확인
        if (direction == 3 || direction == 4) {
            maxH = max(maxH, length);
        }
        if (direction == 1 || direction == 2) {
            maxW = max(maxW, length);
        }
    }
     
    int k = 1;
    int l1 = 0;
    int l2 = 0;
    while (k < 9) {
        int d1 = A[k-1];
        int d2 = A[k];
        int d3 = A[k+1];
        int d4 = A[k+2];
         
        if (d2 == d4 && d1 == d3) {
            l1 = B[k];
            l2 = B[k+1];
            break;
        }
         
        k++;
    }
     
    int myunjeok = (maxW * maxH) - (l1 * l2);
    ans = K * myunjeok;
     
    printf("%d\n", ans);// 출력하는 부분
    return 0;
}