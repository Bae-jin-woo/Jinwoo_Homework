#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include "arrayqueue.h"

void addq(Element e) {
	if (front % MAX_SIZE == (rear + 1) % MAX_SIZE) {	//front�� rear�� 1���̶��
		printf(" Queue is Full!!\n");	//ť�� �����ִ�
		return 0;
	}
	queue[(++rear) % MAX_SIZE] = e;	//rear�� �ε����� ���� ������Ű�� ���� �����Ѵ�
}
Element deleteq() {
	if (front % MAX_SIZE == rear % MAX_SIZE) {
		printf("\nQueue is Empty!!");
		return 0;
	}
	return queue[(++front) % MAX_SIZE];
}
void queue_show() {
	if (front % MAX_SIZE == rear % MAX_SIZE) {
		printf("\nQueue is Empty!!");
		return 0;
	}
	for (int i = front+1; i <= rear; i++)
		printf(" %c ", queue[i % MAX_SIZE]);
}
void main() {
	char c, e;
	printf("**********Command**************\n");
	printf("+<c>: Insert c, -<c>: Delete c\n?<c>: Search c, S:Show, Q:Quit\n");
	printf("*****************************\n\n");
	
	while (1) {
		printf("\nCommand>");
		c = _getch();
		_putch(c);
		c = toupper(c);
		switch (c){
			case'+':
				e = _getch();
				_putch(e);
				addq(e);
				break;
			case'-':
				e = deleteq();
				printf("\n%c", e);
				break;
			case'S':
				queue_show();
				break;
			case'Q':	printf("\n");
					exit(1);
			default: break;
		}
	}
}
//front�� rear�� ���� ������ ť�� ����ִ�.
//front�� rear���� �ϳ� ũ�ٸ� ť�� �����ִ�.
//���� �ÿ� rear�� ���� ���� ������Ű�� �ű⿡ �����͸� ����
//���� �ÿ��� front�� ���� ������Ű�� �ű⿡ �����͸� ����
//��ȭ���¿� ������¸� �����ϱ� ���� ��ĭ�� �׻� ����д�.