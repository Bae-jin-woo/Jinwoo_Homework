#define MAX_SIZE 100
#define boolean unsigned char
#define true 1
#define false 0

//Global stack;
int stack[MAX_SIZE];
int top = -1;

void push(int e);
int pop();
int eval_postfix(char *exp);	//exp(후위표기 연산식)를 처리하여 결과를 반환
boolean is_number(char c);	//c가 숫자인지 판별하는 함수
boolean is_op(char c);	//c가 연산자인지 판별하는 함수