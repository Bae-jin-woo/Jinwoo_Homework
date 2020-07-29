#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "bst.h"
void main()
{
	char c, grade;
	int id;

	printf("************* Command ************\n");
	printf("I: Insert data, S: Search data    \n");
	printf("P: Print inorder, Q: Quit A: ISBST    \n");
	printf("**********************************\n");

	while (1) {
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);
		switch (c) {
		case 'I':
			printf("\n id and grade: ");
			scanf("%d %c", &id, &grade);
			bst_insert(id, grade);
			break;
		case 'S':
			printf("\n id: ");
			scanf("%d", &id);
			grade = bst_search(id);
			if (grade) printf(" Grade of %d: %c \n", id, grade);
			else printf(" No such id ! \n");
			break;
		case 'P':
			printf("\n");
			bst_show_inorder(root);
			break;
		/*case 'A':
			printf("\n");
			if (IsBST) {
				printf("BST�Դϴ�\n");
			}
			else {
				printf("BST�� �ƴմϴ�.\n");
			}
			break;*/
		case 'Q':
			printf("\n");
			exit(1);
		default: break;
		}
	}
}
//Ʈ���� (key,data)�ڷ� ����
void bst_insert(int key, char data) {
	tree_pointer c = root;
	tree_pointer p = NULL;
	while (c) {
		if (key == c->key) return;
		p = c;
		if (key < c->key) c = c->left;
		else c = c->right;
	}
	tree_pointer temp = (tree_pointer)malloc(sizeof(tree_node));
	temp->key = key;
	temp->data = data;
	temp->left = temp->right = NULL;
	if (p) {
	if (key < p->left) p->left = temp;
	else p->right = temp;
	}	
	else root = temp;
}
//Ʈ������ Ű���� key�� �ڷḦ �˻�, data�� ��ȯ
char bst_search(int key) {
	tree_pointer p;
	p = root;
	while (p) {
		if (key == p->key) return p->data;
		if (key < p->key)
			p = p->left;
		else
			p = p->right;
	}
	return NULL;
}
//Ʈ���� �ڷ���� inorder�� ���
void bst_show_inorder(tree_pointer ptr) {
	if (ptr) {
		bst_show_inorder(ptr->left);
		printf("%d %c\n", ptr->key, ptr->data);
		bst_show_inorder(ptr->right);
	}
}

int IsBST(tree_pointer t, int min, int max) {   // true 1, false 0�� ��ȯ
	while (t) {
		if (t->key > t->right || t->key < t->left) return 0;
		if (t->key > max || t->key < min) return 0;
		IsBST(t->left, min, max);
		IsBST(t->right, min, max);
		return 1;
	}

}