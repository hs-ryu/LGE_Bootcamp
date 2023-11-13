#include <stdio.h>
#define MAXN (100)

#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif


int N, M;//재료종류수, 가진돈
int X[MAXN + 10];//1인분당 필요한 양
int Y[MAXN + 10];//주방에 있는 양
int Sm[MAXN + 10];//작은 포장 재료 양
int Pm[MAXN + 10];//작은 포장 가격
int Sv[MAXN + 10];//큰포장 재료 양
int Pv[MAXN + 10];//큰포장 가격

// int maxV = 0;

// void DFS(int total) {
//     if (total > M) {
//         return;
//     }

//     int possible_make = 50000000;
//     for (int i = 0; i < N; i++) {
//         possible_make = min(possible_make, Y[i] / X[i]);
//     }

//     if (maxV < possible_make) {
//         maxV = possible_make;
//     }

//     for (int i = 0; i < N; i++) {
//         Y[i] += Sm[i];
//         DFS(total + Pm[i]);
//         Y[i] -= Sm[i];
        
//         Y[i] += Sv[i];
//         DFS(total + Pv[i]);
//         Y[i] -= Sv[i];
//     }
// }


void InputData(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d %d %d", &X[i], &Y[i], &Sm[i], &Pm[i], &Sv[i], &Pv[i]);
	}
}
int main(void) {
	int ans = 0;
	InputData();//입력 받는 부분

	//여기서부터 작성
    
    // 방법 1. 현재 금액으로 구매할 수 있는 경우의 수 구하기. 큰 포장, 작은 포장까지 모두 확인. -> 시간초과
    // DFS(0);

    // 방법 2. 이분탐색..?
    // 필요한 양을 살 수 있는 최소 비용? 작은애들 먼저? 
    // 반복문 -> 작은 애들로만 채웠을때 -> 작은 애들을 하나씩 줄이면서 큰 애들을 넣어주기?
    // 모든 재료들이 middle개 만들 수 있는 상태가 되어야한다.
    // Y + Yplus // X[i] == 50000
    // 8 + x // 10 == 50000
    // x = middel * X[i] - Y[i]
    
    // 작은 팩과 큰 팩을 사는 것 중 어느 것을 사는게 더 이득인가?
    int l = 0;
    int r = 100000;

    while (l <= r) {
        int middle = (r + l) / 2;
        int need_money = 0;

        for (int i = 0; i < N; i++) {
            int need = middle * X[i] - Y[i];
            int min_money = 10000000;
            // 작은 팩으로 하나씩 늘려가면서, 큰 팩으로 몇개 사야하는지 확인.

            int small = 0;
            while (1) {
                int temp_money = small * Pm[i];
                int more_need = need - Sm[i] * small;
                if (more_need < 0) {
                    min_money = min(min_money, temp_money);
                    break;
                }

                int big = more_need / Sv[i];
                if (more_need % Sv[i] != 0) {
                    big++;
                }
                temp_money += big * Pv[i];
                min_money = min(min_money, temp_money);
                small++;
            }
            need_money += min_money;
            


            // for (int small = 0; small < need/Sm[i]+1; small++) {
            //     int temp_money = small * Pm[i];
            //     int more_need = need - Sm[i] * small;
            //     int big = more_need / Sv[i];

            //     if (more_need % Sv[i]) {
            //         big++;
            //     }

            //     temp_money += big * Pv[i];

            //     min_money = min(min_money, temp_money);
            // }

            // need_money += min_money;
        
        }

    if (need_money > M) {
        r = middle - 1;
    }
    else if (need_money <= M) {
        l = middle + 1;
        ans = middle;
    }
    }

	printf("%d\n", ans);//출력 하는 부분
	return 0;
}