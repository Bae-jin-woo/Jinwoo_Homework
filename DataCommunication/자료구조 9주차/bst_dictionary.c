#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "bst_dictionary.h"
void main()
{
	char c, fname[20];
	char w1[100], *w2;

	printf("************* Command ************\n");
	printf("R: Read data, S: Search data    \n");
	printf("P: Print inorder, Q: Quit         \n");
	printf("**********************************\n");
	while (1) {
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);
		switch (c) {
		case 'R':
			printf("\n Dictionary file name: ");
			scanf("%s", fname);
			wcount = build_dictionary(fname);
			printf(" Total number of words: %d \n", wcount);
			break;
		case 'S':
			printf("\n Word: ");
			scanf("%s", w1);
			w2 = bst_search(w1);
			if (w2) printf(" Meaning: %s \n", w2);
			else printf(" No such word ! \n");
			break;
		case 'P':
			printf("\n");
			bst_show_inorder(root);
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default: break;
		}
	}
}
int build_dictionary(char *fname) { // ���Ͽ��� �ܾ���� �о� ����Ž��Ʈ�� ����
	FILE *fp = fopen(fname, "r"); // �Է¹��� ���ϸ����� ������ ����
	char key[20][20]; char data[20][20];
	int n = 0;
	while (fscanf(fp, "%s %s", key[n], data[n]) == 2) n++;
	for (int i = 0; i < n; i++) {
		bst_insert(key[i], data[i]);
	}
	return n;
}
void bst_insert(char *w1, char *w2) { // Ʈ���� (w1, w2) �ڷ� ����
	if (root == NULL) { // ó���� ��Ʈ�� ������� ���
		root = (tree_pointer)malloc(sizeof(tree_node));
		strcpy(root->w1, w1);
		strcpy(root->w2, w2);
		root->left = root->right = NULL;
	}
	else {
		tree_pointer c, p;
		p = NULL; // �θ� ���
		c = root; // �ڽ� ���
		while (c != NULL) {
			if (!(strcmp(c->w1, w1))) return; // �̹� �Է� ���� Ű ���� �����ϸ� unique�ؾ� �ϹǷ� �Լ� ����
			else {
				p = c;
				if (strcmp(w1, c->w1) > 0) c = c->right;
				else c = c->left;
			}
		}
		tree_pointer tmp = (tree_pointer)malloc(sizeof(tree_node)); // ������ ��� ����
		strcpy(tmp->w1, w1);
		strcpy(tmp->w2, w2);
		tmp->left = tmp->right = NULL;
		if (strcmp(w1, p->w1) > 0) p->right = tmp;
		else p->left = tmp;
	}
}
char * bst_search(char *w1) { // Ʈ������ Ű���� w1�� �ڷḦ �˻�, w2�� ��ȯ
	tree_pointer p = root;
	while (p) {
		if (strcmp(w1, p->w1) == 0) { return p->w2; }
		else {
			if ((strcmp(w1, p->w1) < 0))
				p = p->left;
			else p = p->right;
		}
	}
	return NULL;
}
void bst_show_inorder(tree_pointer ptr) { // Ʈ���� �ڷ���� inorder�� ��� 
	if (ptr == NULL) return;
	bst_show_inorder(ptr->left);
	printf("%s %s\n", &ptr->w1, &ptr->w2);
	bst_show_inorder(ptr->right);
}