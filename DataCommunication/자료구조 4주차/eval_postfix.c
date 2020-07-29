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
	if (top == -1) {	//������ ����ٸ�
		return 0;
	}
	return stack[top--];	//�׷��� �ʴٸ� �� ���� ��� ����
}
int eval_postfix(char *exp) {
	for (int i = 0; i < sizeof(exp); i++) {
		if (is_number(exp[i])) {	//���ڰ� ���ڶ��
			int op = exp[i] - '0';	//int������ ������ �����ϱ� ���� 0�� ���ش�.
			push(op);	//���ڸ� ���ÿ� ����
		}
		if (is_op(exp[i])) {	//���ڰ� �����ڶ��
			char op = exp[i];
			int op2 = pop() - '0';	//���� ���� ���߿� �����ϱ� op2�� ���� pop
			int op1 = pop() - '0';
			switch (op) {
			case'+':	return op1 + op2;	break;
			case'-':	return op1 - op2;	break;
			case'*':	return op1 * op2;	break;
			case'/':	return op1 / op2;	break;
			}
		}
		//���ڰ������� ���ÿ� push�ϰ� �����ڰ������� stack[top]+stack[top-1]
	}
}
boolean is_number(char c) {	//c�� �������� �Ǻ��ϴ� �Լ�
	if (('0' <= c) && (c <= '9'))
		return true;
	else
		return false;
}
boolean is_op(char c) {	//c�� ���������� �Ǻ��ϴ� �Լ�
	if ((c == '+') || (c == '-') || (c == '*') || (c == '/'))
		return true;
	else
		return false;
}