#include <stdio.h>
#include <string.h>
#define MAXN (20)
int N, K;//자연수 개수, 만들값
int A[MAXN + 10];//자연수 값
char *msg[] = {"NO", "YES"};
int flag;
int hab[MAXN + 10];
void find(int sum, int idx) {
    if (flag == 1) {
        return;
    }
    if (idx > N) {
        return;
    }
    
    if (sum > hab[N] - hab[idx-1]) {
        return;
    }

    if (sum == K) {
        flag = 1;
        return;
    }

    for (int i = idx; i < N+1; i++) {
        find(sum - A[i], i+1);
    }
}


void InputData(void){
	scanf("%d %d", &N, &K);
	for (int i=1; i<=N; i++){
		scanf("%d", &A[i]);
	}
}

int main(void){
	int T, t, ans;
	scanf("%d", &T);
	for (t=1; t<=T; t++){
		InputData();//입력
        
		//여기서부터 작성
        flag = 0;
        memset(hab, 0, sizeof(hab));
        for (int i = 1; i < N+1; i++) {
            hab[i] = hab[i-1] + A[i];
            // printf("%d ", hab[i]);
        }

        find(K,1);
        if (flag == 1) {
            ans = 1;
        }
        else {
            ans = 0;
        }
		printf("%s\n", msg[ans]);//출력
	}
	return 0;
}