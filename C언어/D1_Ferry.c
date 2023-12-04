#include <stdio.h>
#include <string.h>

#define MAXN ((int)1e4)
int M, T, N;
int AT[MAXN + 10];
char SIDE[MAXN + 10][10];
 
int arrived[MAXN + 10];

int queue[2][MAXN + 10];
int wp[2], rp[2];

void push(int side, int d) {
    queue[side][wp[side]++] = d;
}

void pop(int side) {
    rp[side]++;
}

int front(int side) {
    return queue[side][rp[side]];
}

int isEmpty(int side) {
    return wp[side] == rp[side];
}
 

void InputData(void) {
    scanf("%d %d %d", &M, &T, &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %s", &AT[i], SIDE[i]);
    }
}
void OutputData(void) {
    for (int i = 0; i < N; i++) {
        printf("%d\n", arrived[i]);
    }
}
int main(void) {
    InputData();//입력받는 부분
 
    wp[0] = rp[0] = 0;
    wp[1] = rp[1] = 0;
    for (int i = 0; i < N; i++) {
        if (strcmp(SIDE[i], "left") == 0) push(0, i);
        else push(1, i);
    }

    int ship_location = 0;
    int timer = 0;
    int total = 0;
    while (total < N) {
        if (!isEmpty(ship_location) && (timer >= AT[front(ship_location)])) {
            int cnt = 0;
            while (!isEmpty(ship_location) && (cnt < M)) {
                int i = front(ship_location);
                if (AT[i] > timer) break;
                pop(ship_location);
                arrived[i] = timer + T;
                cnt++;
                total++;
            }
            timer += T;
            ship_location = ship_location == 0 ? 1 : 0;
        }
        else {
            if (isEmpty(ship_location)) {
                ship_location = ship_location == 0 ? 1 : 0;
                if (timer < AT[front(ship_location)]) timer = AT[front(ship_location)];
                timer += T;
            }
            else {
                int idx = front(ship_location);
                int other_side = ship_location == 0 ? 1 : 0;
                if (!isEmpty(other_side) && (AT[idx] > AT[front(other_side)])) {
                    ship_location = ship_location == 0 ? 1 : 0;
                    idx = front(ship_location);
                    if (timer < AT[idx]) timer = AT[idx];
                    timer += T;
                }
                else {
                    timer = AT[idx];
                }
            }
        }
    }
 
    OutputData();//출력하는 부분
    return 0;
}
