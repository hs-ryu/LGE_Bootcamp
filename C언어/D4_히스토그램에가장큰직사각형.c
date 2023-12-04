#include <stdio.h>
int N;//히스토그램수
int H[100000+10];//히스토그램 높이
long long stack[100000+10][2];
int sp;

void push(long long idx, long long height) {
    stack[sp][0] = idx;
    stack[sp][1] = height;
    sp++;
}

void pop(void) {
    sp--;
}

long long topIdx(void) {
    return stack[sp-1][0];
}

long long topHeight(void) {
    return stack[sp-1][1];
}

int isEmpty(void) {
    return sp == 0;
}

long long max(long long a, long long b) {
    if (a>b) {
        return a;
    }
    return b;
}



int InputData(void) {
    scanf("%d", &N);
    if (N == 0) return 0;
    
    for (int i=0; i<N; i++){
        scanf("%d", &H[i]);
    }
    return 1;
}

int main(void) {
    long long ans = 0;
    while(InputData()){//입력받는 부분
        sp = 0;
        ans = 0;
        push(0, H[0]);
        //여기서부터 작성
        for (int i = 1; i < N; i++) {
            int nIdx = i;
            int nH = H[i];
            
            while (!isEmpty()) {
                long long tIdx = topIdx();
                long long tH = topHeight();
                pop();
                // 오른쪽으로 확장 가능한가.
                // printf("%d %d %d %d\n", tIdx, tH, nIdx, nH);
                if (tH < nH) {
                    push(tIdx, tH);
                    push(nIdx, nH);
                    break;
                }
                // 왼쪽으로 확장 가능한가
                else if (tH > nH) {
                    ans = max(ans, tH * (i- tIdx));
                    // printf("%d\n", ans);
                    nIdx = tIdx;
                    if (isEmpty()) {
                        push(nIdx, nH);
                    }
                }
                else {
                    push(tIdx, tH);
                    break;
                }
            }
        }
        
        while (!isEmpty()) {
            long long tIdx = topIdx();
            long long tH = topHeight();
            pop();
            ans = max(ans, tH * (N-tIdx));
        }
        
        
        
        // 왼쪽으로 더이상 확장 불가능하다 -> 빼버린다 pop
        
        
        
        printf("%lld\n", ans);//출력하는 부분
    }
    return 0;
}