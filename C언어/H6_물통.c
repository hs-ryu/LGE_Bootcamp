#include <stdio.h>

int A, B, targetA, targetB;
int bucketA = 0;
int bucketB = 0;
int ans = 100000;
int visited[1001][1001];
void InputData(void) {
	scanf("%d %d %d %d", &A, &B, &targetA, &targetB);
}

int min(int a, int b) {
    return a > b ? b : a;
}

// 1. 물통 x에 물을 가득 채운다.
// 2. 물통 x에 물을 모두 버린다.
// 3. 물통 x의 물을 물통 y에 붓는다.

void Fill(int idx) {
    if (idx == 0) {
        bucketA = A;
    } else {
        bucketB = B;
    }
}

void Empty(int idx) {
    if (idx == 0) {
        bucketA = 0;
    } else {
        bucketB = 0;
    }
}

void Move(int idx) {
    // A의 물을 B에 붓는다.
    if (idx == 0) {
        if (bucketA <= B - bucketB) {
            bucketB += bucketA;
            bucketA = 0;
        } else {
            bucketA = bucketA - (B - bucketB);
            bucketB = B;
            
        }
    } 
    // B의 물을 A에 붓는다.
    else {
        if (bucketB <= A - bucketA) {
            bucketA += bucketB;
            bucketB = 0;
        } else {
            bucketB = bucketB - (A - bucketA);
            bucketA = A;
            
        }
    }
    
}

void DFS(int cnt) {
    if (visited[bucketA][bucketB]) {
        return;
    }
    
    if (cnt > ans) {
        return;
    }
    // printf("bucketA : %d, bucketB: %d\n", bucketA, bucketB);
    if (bucketA == targetA && bucketB == targetB) {
        ans = min(ans, cnt);
    }
    
    int existA = bucketA;
    int existB =  bucketB;
    visited[bucketA][bucketB] = 1;
    
    Fill(0);
    DFS(cnt+1);
    bucketA = existA;
    
    Empty(0);
    DFS(cnt+1);
    bucketA = existA;
    
    Move(0);
    DFS(cnt+1);
    bucketA = existA;
    bucketB = existB;
    
    Fill(1);
    DFS(cnt+1);
    bucketB = existB;
    
    Empty(1);
    DFS(cnt+1);
    bucketB = existB;
    
    Move(1);
    DFS(cnt+1);
    bucketA = existA;
    bucketB = existB;
    visited[bucketA][bucketB] = 0;
}



int main(void) {
	
	InputData();//입력받는 부분
	
	// 여기서부터 작성
	DFS(0);
	
    if (ans == 100000) {
        ans = -1;
    }
    
    
    
	printf("%d\n", ans);// 출력하는 부분
	return 0;
}