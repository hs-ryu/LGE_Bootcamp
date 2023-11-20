#include <stdio.h>
 
int N;
int A[1000+10];
void InputData(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
}
 
 
 
 
int main(void){
    int ans = 987654321;
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    int maxNum = 0;
    for (int i = 0; i < N; i++) {
        int num = A[i];
         
        int temp = num;
        int sum = 0;
        while (1) {
            if (temp / 10 == 0) {
                sum += temp % 10;
                if (sum / 10 == 0) {
                    break;
                }
                else {
                    temp = sum;
                    sum = 0;
                }
            }
            sum += temp % 10;
            temp = temp / 10;
        }
         
        if (sum == maxNum && ans > num) {
            ans = num;
        } 
         
        if (sum > maxNum) {
            maxNum = sum;
            ans = num;
        } 
    }
 
    printf("%d\n", ans);// 출력하는 부분
    return 0;
}