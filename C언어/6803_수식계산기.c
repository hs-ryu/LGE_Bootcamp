#include <stdio.h>
#define MAX (20)
int N;
int M[MAX + 10];
char op[MAX + 10];
int stack[MAX];
int spoint;

void InputData(void){
	scanf("%d", &N);
	scanf("%d", &M[0]);
	for(int i=1; i<N; i++){
		scanf(" %c %d", &op[i], &M[i]);
	}
}

void push(int x) {
    stack[spoint] = x;
    spoint++;
}

int pop(void) {
    spoint--;
    return stack[spoint];
}

int empty(void) {
    return spoint == 0;
}

int main(void){
	InputData();//입력
    push(M[0]);
    
    for (int i=1; i < N; i++) {
        if (op[i] == '+') {
            push(M[i]);
        }
        else if (op[i] == '-') {
            push(M[i] * (-1));
        } 
        else if (op[i] == '*') {
            push(M[i] * pop());
        }
        else {
            push(pop() / M[i]);
        }
    }
    
    int result = 0;
    while (!empty()) {
        int top = pop();
        result = result + top;
    }

    printf("%d", result);
	return 0;
}