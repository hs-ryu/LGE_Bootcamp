#include <stdio.h>
char map[5][10];
int target[12][2];
int targetLength;

void InputData(void){
	for (int h=0; h<5; h++){
		scanf("%s", map[h]);
	}
}
void OutputData(void){
	for (int h=0; h<5; h++){
		printf("%s\n", map[h]);
	}
}

int check(void) {
    // 0,4에서 왼쪽 대각선 아래 확인
    int total1 = 0;
    for (int i = 0; i < 4; i++) {
        if (map[i][4-i] == 'x') {
            continue;
        }
        total1 += (int)map[i][4-i] - 64;
    }
    
    // 0,4에서 오른쪽 대각선 아래 확인
    int total2 = 0;
    for (int i = 0; i < 4; i++) {
        if (map[i][4+i] == 'x') {
            continue;
        }
        total2 += (int)map[i][4+i] - 64;
    }
    
    // 1,1에서 오른쪽 확인
    int total3 = 0;
    for (int j = 1; j <= 7; j += 2) {
        if (map[1][j] == 'x') {
            continue;
        }
        total3 += (int)map[1][j] - 64;
    }
    
    // 1,1에서 오른쪽아래 확인
    int total4 = 0;
    for (int i = 1; i < 5; i++) {
        if (map[i][i] == 'x') {
            continue;
        }
        total4 += (int)map[i][i] - 64;
    }
    
    // 3,1에서 오른쪽 확인
    int total5 = 0;
    for (int j = 1; j <= 7; j += 2) {
        if (map[3][j] == 'x') {
            continue;
        }
        total5 += (int)map[3][j] - 64;
    }
    
    // 4,4에서 오른쪽 위 확인
    int total6 = 0;
    for (int i = 4; i >= 1; i--) {
        if (map[i][4+4-i] == 'x') {
            continue;
        }
        total6 += (int)map[i][4+4-i] - 64;
    }
    // printf("total1 : %d, total2 : %d, total3 : %d, total4 : %d, total5 : %d, total6 : %d\n", total1, total2, total3, total4, total5, total6);
    if (total1 == 26 && total2 == 26 && total3 == 26 && total4 == 26 && total5 == 26 && total6 == 26) {
        return 2;
    }
    
    if (total1 > 26 || total2 > 26 || total3 > 26 || total4 > 26 || total5 > 26 || total6 > 26) {
        return 0;
    }
    return 1;
}

int used[13];
int isFind = 0;
void DFS(int level) {
    
    if (isFind) {
        return;
    }
    
    if (check() == 0) {
        
        return;
    }
    
    if (level == targetLength) {
        
        if (check() == 2) {
            isFind = 1;
            OutputData();
        }
        return;
    }
    
    int target_r = target[level][0];
    int target_c = target[level][1];
    
    for (int i = 1; i < 13; i++) {
        if (used[i]) {
            continue;
        }
        used[i] = 1;
        map[target_r][target_c] = (char)(i + 64);
        DFS(level+1);
        map[target_r][target_c] = 'x';
        used[i] = 0;
    }
}


int main(void){
	InputData();//입력받는 부분

	//여기서부터 작성
	// 1. 채워야 하는 부분의 좌표 생각하기
	
	
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (map[i][j] == 'x') {
                target[targetLength][0] = i;
                target[targetLength][1] = j;
                targetLength++;
            } else if (map[i][j] != '.') {
                used[(int)map[i][j] - 64] = 1;
            }
        }
    }
    
    // for (int i = 0; i < 13; i++) {
    //     printf("%d ", used[i]);
    // }
	DFS(0);
	

// 	OutputData();//출력하는 부분
	return 0;
}