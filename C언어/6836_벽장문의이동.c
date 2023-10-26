#include <stdio.h>
#include <stdlib.h>
#define MAXN (20)

int N;
int sl, sr;
int M;
int seq[MAXN+10];
int minS = 20 * 10 + 1;
void DFS(int sum, int l, int r, int idx) {
    if (sum > minS) {
        return;
    }
    if (idx == M) {
        if (sum < minS) {
            minS = sum;
        }
        return;
    }
    
    // case1: 타겟 오른쪽에 열린 문이 둘 다 있는 경우 (왼쪽 문보다 작은 경우)
    // case2: 타겟 왼쪽 오른쪽에 열린 문이 양쪽으로 있는 경우 (왼쪽 문 < x < 오른쪽 문인 경우)
    // case3: 타겟 왼족에 열린 문이 둘 다 있는 경우 (오른쪽 문보다 큰 경우)

    // case1. 왼쪽 문 이용
    if (seq[idx] <= l) {
        DFS(sum+abs(seq[idx]-l), seq[idx], r, idx+1);
    }
    // case3. 오른쪽 문 이용
    else if (seq[idx] >= r) {
        DFS(sum + abs(seq[idx] - r), l, seq[idx], idx+1);
    }
    // case2. 왼쪽 문, 오른쪽 문 이용.
    else {
        DFS(sum+abs(seq[idx]-l), seq[idx], r, idx+1);
        DFS(sum + abs(seq[idx] - r), l, seq[idx], idx+1);
    }
        
}

void InputData(void){
    scanf("%d", &N);
    scanf("%d %d", &sl, &sr);
    scanf("%d", &M);
    for (int i=0; i<M; i++){
        scanf("%d", &seq[i]);
    }
}

int main(void){
    int ans = -1;

    InputData();//입력받는 부분

    //여기서부터 작성
    DFS(0,sl,sr,0);

    printf("%d\n", minS);//출력하는 부분
    return 0;
}