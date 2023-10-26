#include <stdio.h>
int N;//던진횟수
int M;//출력모양

void InputData(void){
	scanf("%d %d", &N, &M);
}

int sel[6];
int nums[6] = {1,2,3,4,5,6};
int check[7];
// M = 1 -> 중복 조합
void solve1(int level) {
    if (level == N) {
        for (int i=0; i < N; i++) {
            printf("%d ", sel[i]);
        }
        printf("\n");
        return;
    }
    
    for (int i=0; i<6; i++) {
        sel[level] = nums[i];
        solve1(level+1);
        sel[level] = 0;
    }
}

// M = 2 -> 중복 순열
void solve2(int level, int idx) {
    if (level==N) {
        for (int i=0; i < N; i++) {
            printf("%d ", sel[i]);
        }
        printf("\n");
        return;
    }

    for (int i=idx; i<6; i++) {
        sel[level] = nums[i];
        solve2(level+1, i);
        sel[level] = 0;
    }
}

// M = 3 -> 순열
void solve3(int level) {
    if (level==N) {
        for (int i=0; i < N; i++) {
            printf("%d ", sel[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < 6; i++) {
        int num = nums[i];
        if (check[num] == 1) {
            continue;
        }

        sel[level] = num;
        check[num] = 1;
        solve3(level+1);
        sel[level] = 0;
        check[num] = 0;
    }
}


int main(void){
	InputData();//입력

	//여기서부터 작성
    switch (M)
    {
    case 1:
        solve1(0);
        break;
    case 2:
        solve2(0,0);
        break;
    case 3:
        solve3(0);
        break;
    default:
        break;
    }

	return 0;
}