#include <stdio.h>

int P;
char N1[10000+10];
char N2[10000+10];
int L[10000+10];
int farmInfo[58][58];
int visited[58][58];
int startCow[25];

char farm;
int sol;
void InputData(void){
    scanf("%d", &P);
    for (int i=0; i<P; i++){
        scanf(" %c %c %d", &N1[i], &N2[i], &L[i]);
        int intN1 = (int)N1[i] - 65;
        int intN2 = (int)N2[i] - 65;
        
        if (farmInfo[intN1][intN2] > L[i] || farmInfo[intN2][intN1] > L[i]) {
            farmInfo[intN1][intN2] = L[i];
            farmInfo[intN2][intN1] = L[i];
        }
    }
}


struct Queue {
    int idx;
    int load;
};

struct Queue queue[500000];
int wp;
int rp;

void push(int idx, int load) {
    queue[wp].idx = idx;
    queue[wp].load = load;
    wp++;
}

void pop(void) {
    rp++;
}

struct Queue front(void) {
    return queue[rp];
}

int isEmpty(void) {
    return wp == rp;
}

void BFS() {
    // Z에서 부터 시작!
    // timeCheck를 갱신시켜 나간다.
    // 다 방문해서 0 ~ 24까지 중 가장 작은 애를 출력!
    push(25,0);
    
    
    while (!isEmpty()) {
        struct Queue now = front();
        pop();
        int nowLocation = now.idx;
        int nowLoad = now.load;
        // printf("nowLocation: %d, nowLoad: %d\n", nowLocation, nowLoad);
        for (int i = 0; i < 58; i++) {
            // 만약 경로가 있다면? 해당 경로로 움직이고 visited 체크
            if (farmInfo[nowLocation][i]) {
                
                if (visited[nowLocation][i] > nowLoad + farmInfo[nowLocation][i]) {
                    push(i, nowLoad + farmInfo[nowLocation][i]);
                    visited[nowLocation][i] = nowLoad + farmInfo[nowLocation][i];
                }
                // 대문자 애들을 만나면? 가중치 판단해서 갱신
                if (0 <= i && i <= 24) {
                    if (startCow[i] > nowLoad + farmInfo[nowLocation][i]) {
                        startCow[i] = nowLoad + farmInfo[nowLocation][i];
                        // printf("cow: %d, load: %d\n", i, nowLoad + farmInfo[nowLocation][i]);
                    }
                }
            }
        }
    }
}

int main(void){
    for (int i = 0; i < 58; i++) {
        for (int j = 0; j < 58; j++) {
            farmInfo[i][j] = 1001;
        }
    }
    for (int i = 0; i <= 25; i++) {
        startCow[i] = 10000001;
    }
    for (int i = 0; i <= 58; i++) {
        for (int j = 0; j <= 58; j++) {
            visited[i][j] = 10000001;
        }
        
    }
    

    InputData();// 입력받는 부분
    for (int i = 0; i < 58; i++) {
        for (int j = 0; j < 58; j++) {
            if (farmInfo[i][j] == 1001) {
                farmInfo[i][j] = 0;
            }
            
        }
    }
    
    // for (int i = 0; i < 58; i++) {
    //     for (int j = 0; j < 58; j++) {
    //         printf("%d ", farmInfo[i][j]);
    //     }
    //     printf("\n");
    // }
    
    BFS();
    
    // 여기서부터 작성
    // printf("%d\n", (int)'a' - 65);  ->  32
    // printf("%d", (int)'A'- 65);  -> 0
    // printf("%d\n", (int)'Z' - 65); -> 25
    // printf("%d\n", (int)'z' - 65); -> 57
    // printf("%c\n", 1 + 65); -> B
    
    // 배열 길이 57
    int minV = 10000003;
    int minIdx;
    for (int i = 0; i <= 24; i++) {
        if (minV > startCow[i]) {
            minV = startCow[i];
            minIdx = i;
        }
    }
    // for (int i = 0; i <= 24; i++) {
    //     printf("%d ", startCow[i] );
    // }
    // printf("-----------------\n");
    
    sol = minV;
    farm = (char)(minIdx + 65);
    
    
    printf("%c %d", farm, sol);// 출력하는 부분
    return 0;
}