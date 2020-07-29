#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include "Linked_list.h"
void list_insert(list_pointer head, Element e) {	//���� e�� ���� ��带 ����� head ����Ʈ�� �տ� ����
	list_pointer p = head;	
	list_pointer new = (list_pointer)malloc(sizeof(list_node));
	new->data = e;
	new->link = p->link;
	p->link = new;
}
void list_delete(list_pointer head, Element e) {	//���� e�� head ����Ʈ���� ã�Ƽ� ��带 ����
	list_pointer p = head;
	list_pointer remove;
	while (p) {	//e�� ����ִ� ����� �� ��带 ã�´� 
		if (p->link->data == e)	break;
		p = p->link;	//��� e�� �ִ��� Ȯ���ϰ� p�� �ּҸ� ��ȯ
	}
	remove = p->link;	//p�� remove�� ����
	p->link = remove->link;	//p�� remove�� ���� ��带 ����
	free(remove);	//remove ����
}
list_pointer list_search(list_pointer head, Element e) {	//���� e�� head����Ʈ���� ã�Ƽ� ��带 ����
	list_pointer p = head;
	while (p) {	//p�� �ּҰ� 0�� �ƴϸ�
		if (p->data == e)	return p;
		p = p->link;	//��� e�� �ִ��� Ȯ���ϰ� p�� �ּҸ� ��ȯ
	}
	return NULL;	//e�� ������ NULL�� ��ȯ 
}
bool list_empty(list_pointer head) {	//head ����Ʈ�� ��������� true
	list_pointer p = head;
	if (p->link == NULL) return true;	//ù���� ����� �ּҰ��� NULL�̸� ��
	else return false;	//�ƴϸ� ����
}
void list_show(list_pointer head) {	//head ����Ʈ�� ������ ���
	list_pointer p = head;
	while (p != NULL) {
		printf("%c ", p->data);
		p = p->link;		//���� ����� �ּ�
	}
}
int main() {
	char c, e;
	list_pointer head, p;
	printf("**********Command**************\n");
	printf("+<c>: Insert c, -<c>: Delete c\n?<c>: Search c, S:Show, Q:Quit\n");
	printf("*****************************\n\n");

	//dummy head ���
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