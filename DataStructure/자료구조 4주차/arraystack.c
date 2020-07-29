
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
		c = getch();	//연산자 입력
		putch(c);
		c = toupper(c);
		switch (c)
		{
		case'+':	//스택 입력
			e = getch();	//요소e를 입력받아 스택에 삽입
			putch(e);
			push(e);
			break;
		case'-':
			e = pop();	//맨 위에 요소를 삭제
			printf("\n%c \n", e);
			break;
		case'S':
			stack_show();	//스택 출력
			break;
		case'Q':
			printf("\n");	//종료
			exit(1);
		default:
			break;
		}
	}
}
void push(Element e) {	//스택 맨 위에 요소 e 추가
	if (top>=MAX_SIZE-1) {	//스택이 다 찼다면
		stack_full();
	}
	stack[++top] = e;	//그렇지 않다면 스택의 맨 위에 요소 e 삽입
}
Element pop() {	//스택 맨 위에 요소 제거
	if (top == -1) {	//스택이 비었다면
		stack_empty();
		return 0;
	}
	return stack[top--];	//그렇지 않다면 맨 위의 요소 삭제
}
void stack_show() {	//스택 출력
	for (int i = 0; i <= top; i++)
		printf("%c ", stack[i]);
}
void stack_empty() {	//스택이 비어있다면
	printf("Stack is empty!!\n");
}
void stack_full() {	//스택이 다 찼다면
	printf("Stack is Full!!\n");
}
