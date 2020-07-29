#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include "arrayqueue.h"

void addq(Element e) {
	if (front % MAX_SIZE == (rear + 1) % MAX_SIZE) {	//front와 rear가 1차이라면
		printf(" Queue is Full!!\n");	//큐가 꽉차있다
		return 0;
	}
	queue[(++rear) % MAX_SIZE] = e;	//rear의 인덱스를 먼저 증가시키고 값을 삽입한다
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
//front와 rear의 값이 같으면 큐가 비어있다.
//front가 rear보다 하나 크다면 큐가 꽉차있다.
//삽입 시에 rear의 값을 먼저 증가시키고 거기에 데이터를 삽입
//삭제 시에도 front를 먼저 증가시키고 거기에 데이터를 삭제
//포화상태와 공백상태를 구분하기 위해 한칸은 항상 비워둔다.