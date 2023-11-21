#include <stdio.h>
#include <math.h>

int N;//빌딩의층수
void InputData(void){
    scanf("%d", &N);
}
int main(void){
    int ans = -1;
    InputData();//입력받는부분
    
    //여기서부터작성

    int split[9];
    int num = N;
    int idx = 0;
    while (1) {
        int now_location = num % 10;
        split[idx] = now_location;
        idx++;
        num = num / 10;
        if (num <= 0) {
            break;
        }
    }
    // 38
    // idx = 2;
    // i = 0, 1
    // j = 1
    // split[1] = 3;
    // temp += 3;
    // temp += 1;

    int total = 0;
    for (int i = 0; i < idx; i++) {
        int now_num = split[i];
        if (now_num > 4) {
            now_num --;
        }
        
        total += now_num * pow(9, i);
    }
    
    ans = total;

    printf("%d\n", ans);//출력하는부분
    return 0;
}