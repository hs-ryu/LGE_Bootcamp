#include <stdio.h>
#include <stdlib.h>
#define MAXN (50)
int N, M, K;//철도역수, 철도수, 추가로 연결시킬수있는 철도수
int S[MAXN + 10];
int E[MAXN + 10];
int visited[MAXN + 10];
int cnt[MAXN+10];
int connectInfo[MAXN + 10][MAXN + 10];

int wp;
int rp;

int comp (const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

void InputData(void) {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &S[i], &E[i]);
    }
}

int queue[50000];

void push(int idx) {
    queue[wp] = idx;
    wp++;
}
void pop(void) {
    rp++;
}
int front(void) {
    return queue[rp];
}
int isEmpty(void) {
    return wp == rp;
}

void makeInfo(int s, int e) {
    connectInfo[s][cnt[s]] = e;
    connectInfo[e][cnt[e]] = s;
    cnt[s]++;
    cnt[e]++;
}

int BFS(int s) {
    wp = 0;
    rp = 0;
    visited[s] = 1;
    push(s);
    int connectCnt = 1;
    
    while (!isEmpty()) {
        int nowCity = front();
        pop();
        for (int i = 0; i < cnt[nowCity]; i++) {
            int connectiedCity = connectInfo[nowCity][i];
            if (visited[connectiedCity] == 0) {
                visited[connectiedCity] = 1;
                push(connectiedCity);
                connectCnt++;
            }
        }
    }
    return connectCnt;
}

int main(void) {
	int ans = 0;
    InputData();//입력받는 부분

	// 여기서부터 작성
	
	// 1. 그룹 짓기
	// 1-1.info부터 그리기
	for (int i = 0; i < M; i++) {
	    makeInfo(S[i],E[i]);
	}
	
// 	for (int i = 1; i <= N; i++) {
// 	    printf("%d\n", i);
//         for (int j = 0; j < cnt[i]; j++) {
//             printf("%d ", connectInfo[i][j]);
//         }
//         printf("\n-------------------\n");
// 	}
    int connectCityInfo[MAXN+10];
	int idx = 0;
	int totalCity = 0;
	for (int i = 1; i <= N; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            if (visited[i] == 0) {
                // 2. 그룹 카운트 해서 배열에 저장.
                int k = BFS(i);
                connectCityInfo[idx] = k;
                totalCity += k;
                idx++;
            }
        }
	}
	// 2-1. 근데, N개의 도시에 대한 정보가 다 안들어올수도 있으니까, 총 개수는 계산해서 부족하면 1씩 추가해줘야함
	for (totalCity; totalCity < N; totalCity++) {
	    connectCityInfo[idx] = 1;
	    idx++;
	}
	
	
	
	// 3. 내림차순 정렬하기.
	qsort(connectCityInfo, idx, sizeof(int), comp);
// 	for (int i = 0; i < idx; i++) {
// 	    printf("%d ", connectCityInfo[i]);
// 	}
// 	printf("\n");
	// 4. K개 만큼 더하기.
	
    for (int i = 0; i < K+1; i++) {
        if (i < idx) {
            ans += connectCityInfo[i];
        }
    }
	
    printf("%d\n", ans);// 출력하는 부분
    return 0;
}
