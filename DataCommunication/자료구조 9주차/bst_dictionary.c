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
int build_dictionary(char *fname) { // 파일에서 단어들을 읽어 이진탐색트리 구성
	FILE *fp = fopen(fname, "r"); // 입력받은 파일명으로 파일을 읽음
	char key[20][20]; char data[20][20];
	int n = 0;
	while (fscanf(fp, "%s %s", key[n], data[n]) == 2) n++;
	for (int i = 0; i < n; i++) {
		bst_insert(key[i], data[i]);
	}
	return n;
}
void bst_insert(char *w1, char *w2) { // 트리에 (w1, w2) 자료 삽입
	if (root == NULL) { // 처음에 루트가 비어있을 경우
		root = (tree_pointer)malloc(sizeof(tree_node));
		strcpy(root->w1, w1);
		strcpy(root->w2, w2);
		root->left = root->right = NULL;
	}
	else {
		tree_pointer c, p;
		p = NULL; // 부모 노드
		c = root; // 자식 노드
		while (c != NULL) {
			if (!(strcmp(c->w1, w1))) return; // 이미 입력 받은 키 값이 존재하면 unique해야 하므로 함수 종료
			else {
				p = c;
				if (strcmp(w1, c->w1) > 0) c = c->right;
				else c = c->left;
			}
		}
		tree_pointer tmp = (tree_pointer)malloc(sizeof(tree_node)); // 삽입할 노드 생성
		strcpy(tmp->w1, w1);
		strcpy(tmp->w2, w2);
		tmp->left = tmp->right = NULL;
		if (strcmp(w1, p->w1) > 0) p->right = tmp;
		else p->left = tmp;
	}
}
char * bst_search(char *w1) { // 트리에서 키값이 w1인 자료를 검색, w2를 반환
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
void bst_show_inorder(tree_pointer ptr) { // 트리의 자료들을 inorder로 출력 
	if (ptr == NULL) return;
	bst_show_inorder(ptr->left);
	printf("%s %s\n", &ptr->w1, &ptr->w2);
	bst_show_inorder(ptr->right);
}