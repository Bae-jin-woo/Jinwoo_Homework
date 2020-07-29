#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include "Linked_list.h"
void list_insert(list_pointer head, Element e) {	//문자 e를 담은 노드를 만들어 head 리스트의 앞에 삽입
	list_pointer p = head;	
	list_pointer new = (list_pointer)malloc(sizeof(list_node));
	new->data = e;
	new->link = p->link;
	p->link = new;
}
void list_delete(list_pointer head, Element e) {	//문자 e를 head 리스트에서 찾아서 노드를 삭제
	list_pointer p = head;
	list_pointer remove;
	while (p) {	//e가 들어있는 노드의 전 노드를 찾는다 
		if (p->link->data == e)	break;
		p = p->link;	//요소 e가 있는지 확인하고 p의 주소를 반환
	}
	remove = p->link;	//p와 remove를 연결
	p->link = remove->link;	//p와 remove의 다음 노드를 연결
	free(remove);	//remove 해제
}
list_pointer list_search(list_pointer head, Element e) {	//문자 e를 head리스트에서 찾아서 노드를 삭제
	list_pointer p = head;
	while (p) {	//p의 주소가 0이 아니면
		if (p->data == e)	return p;
		p = p->link;	//요소 e가 있는지 확인하고 p의 주소를 반환
	}
	return NULL;	//e가 없으면 NULL을 반환 
}
bool list_empty(list_pointer head) {	//head 리스트가 비어있으면 true
	list_pointer p = head;
	if (p->link == NULL) return true;	//첫번쨰 노드의 주소값이 NULL이면 참
	else return false;	//아니면 거짓
}
void list_show(list_pointer head) {	//head 리스트의 내용을 출력
	list_pointer p = head;
	while (p != NULL) {
		printf("%c ", p->data);
		p = p->link;		//다음 노드의 주소
	}
}
int main() {
	char c, e;
	list_pointer head, p;
	printf("**********Command**************\n");
	printf("+<c>: Insert c, -<c>: Delete c\n?<c>: Search c, S:Show, Q:Quit\n");
	printf("*****************************\n\n");

	//dummy head 노드
	head = (list_pointer)malloc(sizeof(list_node));
	head->data = NULL;
	head->link = NULL;
	while (1) {
		printf("\nCommand>");
		c = _getch();
		_putch(c);
		c = toupper(c);
		switch (c) {
		case'+':
			e = _getch();
			_putch(e);
			list_insert(head, e);
			break;
		case'-':
			e = _getch();
			_putch(e);
			list_delete(head, e);
			break;
		case'?':
			e = _getch();
			_putch(e);
			p = list_search(head, e);
			if (p) {
				printf("\n %c is in the list.\n", e);
				printf("Node address %p, data = %c, link = %p \n", p, p->data,p->link);
			}
			else printf("\n %c is not in the list \n", e);
			break;
		case'S':
			list_show(head);
			break;
		case'Q':	printf("\n");
			exit(1);
		default: break;
		}
	}
}