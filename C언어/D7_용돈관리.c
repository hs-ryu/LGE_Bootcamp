#include <stdio.h>

#define MAX_N (100000)

int N, M;
int need[MAX_N];

void Input_Data(void) {
	int i;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N;i++) {
		scanf("%d", &need[i]);
	}
}

int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
    
}

int main(void) {
	int sol = 1000000000;

	// 입력 받는 부분
	Input_Data();

	// 여기서부터 작성
	
	int l = 0;
	int r = 1000000000;
	
	while (l <= r){
	    int middle = (l + r) / 2;
	    int cnt = 0;
	    int over = 0;
	    int money = 0;
	    for (int i = 0; i < N; i ++) {
	        int need_money = need[i];
	        if (need_money > money) {
	            cnt++;
	            money = middle;
	            money -= need_money;
	        } else {
	            money -= need_money;
	        }
	        
	        if (cnt > M || need_money > middle) {
	            over = 1;
	            break;
	        }
	    }
	    // 오버했으면 늘려줘야지
	    if (over == 1) {
	        l = middle + 1;
	    } else {
	        r = middle - 1;
	        sol = middle;
	    }
	}
	
	// 출력하는 부분
	printf("%d\n", sol);

	return 0;
}