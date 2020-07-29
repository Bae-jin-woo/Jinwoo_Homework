#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define boolean unsigned char
#define true 1
#define false 0

typedef char Element;	//Element�� char���̴�
//Global queue
typedef struct  queue *queue_pointer;	//queue_pointer��� ����ü �����͸� �����
typedef struct queue {
	Element item;	//item�� ť�� ����
	queue_pointer link;	//link�� ť�� ������
}queue;
queue_pointer front, rear;	//front rear�� ť ������

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
	front = temp->link;	//front�� ���� ť�� ������
	free(temp);	//�Ǿտ� ť ��ȯ
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