#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)1e5)
int N;//개수
int F[MAXN + 10];

int list[MAXN + MAXN + 10];
int wp = 0;
int rp = 0;

void InputData(void){
	scanf("%d", &N);
	for (int i=0; i<N; i++){
		scanf("%d", &F[i]);
	}
}

int comp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void push(int n) {
    list[wp] = n;
    wp++;
}

void pop(void) {
    rp++;
}

int front(void) {
    return list[rp];
}

int isEmpty(void) {
    return wp == rp;
}

int main(void){
	long long ans = 0;
	InputData();// 입력받는 부분

	// 여기서부터 작성
	qsort(F, N, sizeof(int), comp);
	
	for (int i = 0; i < N; i++) {
	    int now_file = F[i];
	    while (!isEmpty()) {
	        
	       // printf("%d \n", now_file);
	       // for (int j = rp; j < wp; j++) {
	       //     printf("%d ", list[j]);
	       // }
	       // printf("--------\n");
	        
	        int compare_file = front();
	        if (compare_file >= 0.9 * (double)now_file) {
	            push(now_file);
	            ans += (wp - rp - 1);
	            break;
	        }
	        else {
	            pop();
	        }
	    }
	    if (isEmpty()) {
	        push(now_file);
	    }
	}
	
// 	printf("%f\n", (float)(11 * 0.9));

	printf("%lld\n", ans);// 출력하는 부분
	return 0;
}