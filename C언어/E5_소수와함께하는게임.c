#include <stdio.h>
#include <math.h>
int S, E;//출발 정류장 번호, 도착 정류장 번호
void InputData(void){
    scanf("%d %d", &S, &E);
}

// 갈 수 있는 소수 정류장을 넣어줄 큐
int queue[30001];
int wp;
int rp;

void push(int n) {
    queue[wp] = n;
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


int visited[10001];

// 소수 판별
int isPrime(int n) {
    for (int num = 2; num < sqrt(n) + 1; num++) {
        double doubleDivide = (double)n / (double)num;
        int intDivide = n / num;
        // 소수가 아님.
        if (doubleDivide == (double)intDivide) {
            return 0;
        }
    }
    return 1;
}

int BFS() {
    visited[S] = 1;
    push(S);
    
    while (!isEmpty()) {
        int num = front();
        pop();
    
        int i = 0;
        int tenCnt = 0;
        // 자릿수 쪼개기
        
        while (i < 4) {
            int thou, hund,ten, one;
            int tempNum = num;
            
            one = tempNum % 10;
            tempNum /= 10;
            ten = tempNum % 10;
            tempNum /= 10;
            hund = tempNum % 10;
            tempNum /= 10;
            thou = tempNum % 10;
            
            
            int newNum = 0;
            // 일의 자리 연산
            int k = 0;
            // printf("check: %d\n", num);
            while (k < 9) {
                if (i == 0) {
                    one += 1;
                    if (one == 10) {
                        one -= 10;
                    }
                } else if (i == 1) {
                    ten += 1;
                    if (ten == 10) {
                        ten -= 10;
                    }
                } else if (i == 2) {
                    hund += 1;
                    if (hund == 10) {
                        hund -= 10;
                    }
                } else {
                    thou += 1;
                    if (thou == 10) {
                        thou -= 9;
                        k++;
                    }
                }
                k++;
                newNum = thou * 1000 + hund * 100 + ten * 10 + one;
                
                // printf("newNum : %d\n", newNum);
                
                if (isPrime(newNum)) {
                    
                    
                    if (visited[newNum] == 0) {
                        if (newNum == E) {
                            return visited[num];
                        }
                        visited[newNum] = visited[num] + 1;
                        push(newNum);
                        
                    }
                }
                
            }
            // printf("------------------\n");
            
            
            i++;
        }
        
        
        
        
    }
    
    
    
    
}



int main(void){
    int ans = -1;
    InputData();// 입력받는 부분

    // 여기서부터 작성
    
    
    
    // 소수 판별 
    // isPrime()
    // 반복문 -> 
    ans = BFS();

    printf("%d\n", ans);// 출력하는 부분
    return 0;
}