// 입력 : 10 ^ 18


#include <stdio.h>
#define MAXNM ((int)1e5)
int N, M;//소마리수, 잔디구간 개수
unsigned long long A[MAXNM+10];//잔디 구간 시작
unsigned long long B[MAXNM+10];//잔디 구간 끝

unsigned long long AB[MAXNM+10][2];


void InputData(void){
	scanf("%d %d", &N, &M);
	for (int i=0; i<M; i++){
		scanf("%lld %lld", &AB[i][0], &AB[i][1]);
// 		scanf("%lld %lld", &A[i], &B[i]);
	}
}

// 시작점 기준 정렬
unsigned long long comp (const void *a, const void *b) {
    unsigned long long x = ((unsigned long long *)a)[0];
    unsigned long long y = ((unsigned long long *)b)[0];
    if (x > y) {
        return 1;
    } else if (x < y) {
        return -1;
    } else {
        return 0;
    }
}


unsigned long long max(unsigned long long a, unsigned long long b) {
    return a >= b ? a : b;
}

int main(void){
	unsigned long long ans = 0;
	InputData();//입력
    
    qsort(AB, M, sizeof(AB[0]), comp);
    
    // for (int i = 0; i < M; i++) {
    //     printf("%lld %lld \n", AB[i][0], AB[i][1]);
    // }
    // printf("---------\n");
	//여기서 부터 작성
    // D를 이분탐색 렛츠고
    unsigned long long l = 0;
    unsigned long long r = 0;
    r = AB[M-1][1] - AB[0][0];
    // printf("%lld %lld \n", l, r);
    // // 그냥 왼쪽으로 땡겨서 세우면??
    while (l <= r && (l+r) / 2 != 0) {
        unsigned long long middle = (l+r) / 2;
        unsigned long long cow_cnt = 0;
        
        unsigned long long s = AB[0][0];
        unsigned long long e = AB[0][1];
        unsigned long long past_cow_location = 0;
        cow_cnt += ((e - s) / middle + 1);
        // printf("------------------\n");
        
        past_cow_location = e - (e - s) % middle;
        
        int full = 0;
        if (cow_cnt >= N) {
            full = 1;
            ans = middle;
            l = middle + 1;
            continue;
        }
        
        // printf("middle : %lld, cow_cnt : %lld, past_cow_location: %lld\n", middle, cow_cnt, past_cow_location);
        // printf("s: %lld, e: %lld, full: %d, ans: %lld\n",s,e,full, ans);
        
        for (int i = 1; i < M; i++) {
            // 체크해야할 것.
            // 1. 이전 범위에서 M만큼 떨어졌다고 할때. 범위를 초과하지 않는가?
            s = AB[i][0];
            e = AB[i][1];
            
            if (s < past_cow_location + middle) {
                s = past_cow_location + middle;
            }
             // 시작점이 끝점보다 커지면, 못 쓰는 잔디임.
            if (s > e) {
                // printf("%lld %lld\n", s, e);
                continue;
            }
            cow_cnt += ((e - s) / middle + 1);
            // printf("middle : %d, cow_cnt : %d, past_cow_location: %d\n", middle, cow_cnt, past_cow_location);
            // printf("s: %d, e: %d, full: %d, ans: %d\n",s,e,full, ans);
            past_cow_location = e - (e - s) % middle;
            if (cow_cnt >= N) {
                full = 1;
                break;
            }
            
            // 2. 계산식 : 
            // (e - s // D) -> 세울 수 있는 소의 수
            // ((e - s) % D) -> 오른쪽에 남는 자리
            // 남는 자리는 계산 안해도 될거 같음. 그냥 바로 직전 소가 있었던 위치를 저장하는게?
        }
        
        // N마리 다 채웠으면, D를 더 길게 줘보기
        if (full) {
            ans = middle;
            l = middle + 1;
        } else {
            r = middle - 1;
        }
        
    }
	printf("%lld\n", ans);//출력
	return 0;
}