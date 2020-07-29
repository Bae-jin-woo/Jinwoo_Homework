#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define boolean unsigned char
#define true 1
#define false 0

typedef char Element;	//Element는 char형이다
//Global queue
typedef struct  queue *queue_pointer;	//queue_pointer라는 구조체 포인터를 만든다
typedef struct queue {
	Element item;	//item은 큐의 내용
	queue_pointer link;	//link는 큐의 포인터
}queue;
queue_pointer front, rear;	//front rear는 큐 포인터

void addq(Element e);
Element deleteq();
void queue_show();
boolean is_queue_empty();

void addq(Element e) {
	queue_pointer temp = (queue_pointer)malloc(sizeof(queue));
	temp->item = e;
	temp->link = NULL;
	if (front == NULL)	front = rear = temp;
	else {
		rear->link = temp;
		rear = temp;
	}
}
Element deleteq() {
	queue_pointer temp;
	Element item;
	if (front == NULL) return item;	//queue is empty
	item = front->item;
	temp = front;
	front = temp->link;	//front를 다음 큐를 보내고
	free(temp);	//맨앞에 큐 반환
	return item;
}
void queue_show() {
	queue_pointer temp;
	temp = front;
	while (temp) {
		printf(" %c ", temp->item);
		temp = temp->link;
	}
}
boolean is_queue_empty() {
	if (front == NULL)	
		return true;
	else
		return false;
}
int main() {
	char c, e;
	front = rear = NULL;
	printf("**********Command**************\n");
	printf("+<c>: AddQ, -: Delete Q\n S:Show, Q:Quit\n");
	printf("*****************************\n\n");

	while (1) {
		printf("\nCommand>");
		c = getch();
		putch(c);
		c = toupper(c);
		switch (c){
		case'+':
			e = getch();
			putch(e);
			addq(e);
			break;
		case'-':
			if (is_queue_empty()) {
				printf("\nQueue is empty !!!\n");
			}
			else {
				e = deleteq();
				printf("\n %c", e);
			}
			break;
		case'S':
			queue_show(); 
			break;
		case'Q':
			printf("\n"); exit(1);
		default:
			break;
		}
	}
}