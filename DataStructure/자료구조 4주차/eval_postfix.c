#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "eval_postfix.h"

int main() {
	char exp[MAX_SIZE];	//postfix expression
	int result;
	while (1){
		printf("\nInput postfix expression: ");
		scanf("%s", exp);
		result = eval_postfix(exp);
		printf("Result = %d\n\n", result);
	}
	return 0;
}
void push(int e) {
	stack[++top] = e;
}
int pop() {
	if (top == -1) {	//스택이 비었다면
		return 0;
	}
	return stack[top--];	//그렇지 않다면 맨 위의 요소 삭제
}
int eval_postfix(char *exp) {
	for (int i = 0; i < sizeof(exp); i++) {
		if (is_number(exp[i])) {	//문자가 숫자라면
			int op = exp[i] - '0';	//int형으로 변수를 저장하기 위해 0을 뺴준다.
			push(op);	//숫자를 스택에 삽입
		}
		if (is_op(exp[i])) {	//문자가 연산자라면
			char op = exp[i];
			int op2 = pop() - '0';	//먼저 들어간게 나중에 나오니까 op2를 먼저 pop
			int op1 = pop() - '0';
			switch (op) {
			case'+':	return op1 + op2;	break;
			case'-':	return op1 - op2;	break;
			case'*':	return op1 * op2;	break;
			case'/':	return op1 / op2;	break;
			}
		}
		//숫자가나오면 스택에 push하고 연산자가나오면 stack[top]+stack[top-1]
	}
}
boolean is_number(char c) {	//c가 숫자인지 판별하는 함수
	if (('0' <= c) && (c <= '9'))
		return true;
	else
		return false;
}
boolean is_op(char c) {	//c가 연산자인지 판별하는 함수
	if ((c == '+') || (c == '-') || (c == '*') || (c == '/'))
		return true;
	else
		return false;
}