
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "arraystack.h"
void main() {
	char c, e;
	printf("********Command*******\n");
	printf("+<c>: Push c, -:Pop,\nS:Show, Q: Quit\n");
	printf("**********************\n\n");
	while (1)
	{
		printf("\nCommnand>");
		c = getch();	//������ �Է�
		putch(c);
		c = toupper(c);
		switch (c)
		{
		case'+':	//���� �Է�
			e = getch();	//���e�� �Է¹޾� ���ÿ� ����
			putch(e);
			push(e);
			break;
		case'-':
			e = pop();	//�� ���� ��Ҹ� ����
			printf("\n%c \n", e);
			break;
		case'S':
			stack_show();	//���� ���
			break;
		case'Q':
			printf("\n");	//����
			exit(1);
		default:
			break;
		}
	}
}
void push(Element e) {	//���� �� ���� ��� e �߰�
	if (top>=MAX_SIZE-1) {	//������ �� á�ٸ�
		stack_full();
	}
	stack[++top] = e;	//�׷��� �ʴٸ� ������ �� ���� ��� e ����
}
Element pop() {	//���� �� ���� ��� ����
	if (top == -1) {	//������ ����ٸ�
		stack_empty();
		return 0;
	}
	return stack[top--];	//�׷��� �ʴٸ� �� ���� ��� ����
}
void stack_show() {	//���� ���
	for (int i = 0; i <= top; i++)
		printf("%c ", stack[i]);
}
void stack_empty() {	//������ ����ִٸ�
	printf("Stack is empty!!\n");
}
void stack_full() {	//������ �� á�ٸ�
	printf("Stack is Full!!\n");
}
