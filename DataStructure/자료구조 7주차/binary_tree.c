#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "binary_tree.h"
#define MIN 1
#define MAX 100

void main()
{
	char c;
	int  n;
	tree_pointer t;

	t = build_simple_tree();

	printf("************* Command ************\n");
	printf("C: Count tree, A: Add tree data    \n");
	printf("H: Height of tree, S: Show preorder I: Show inorder \n");
	printf("F: Free tree, Q: Quit   W: IsBst       \n");
	printf("**********************************\n");

	while (1) {
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);
		switch (c) {
		case 'C':
			n = bt_count(t);
			printf("\n Total number of node = %d \n", n);
			break;
		case 'A':
			n = bt_add(t);
			printf("\n Sum of tree data = %d \n", n);
			break;
		case 'H':
			n = bt_height(t);
			printf("\n Height of tree = %d \n", n);
			break;
		case 'S':
			printf("\n");
			bt_show_preorder(t);
			printf("\n");
			break;
		case 'I':
			printf("\n");
			bt_show_inorder(t);
			printf("\n");
			break;
		case 'F':
			printf("\n");
			bt_free(t);
			printf("\n");
			break;
		case 'W':
			if (IsBST(t, MIN, MAX))
				printf("BST 입니다\n");
			else printf("BST가 아닙니다.\n");
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default: break;
		}
		
	}
}
tree_pointer build_simple_tree() {	
	tree_node *n1, *n2, *n3, *n4, *n5, *n6, *n7;
	//			 10
	//		20		  30
	//	 40    50   60  70
	n1 = (tree_node *)malloc(sizeof(tree_node));
	n2 = (tree_node *)malloc(sizeof(tree_node));
	n3 = (tree_node *)malloc(sizeof(tree_node));
	n4 = (tree_node *)malloc(sizeof(tree_node));
	n5 = (tree_node *)malloc(sizeof(tree_node));
	n6 = (tree_node *)malloc(sizeof(tree_node));
	n7 = (tree_node *)malloc(sizeof(tree_node));
	n1->left = n2; n1->right = n3;
	n2->left = n4; n2->right = n5;
	n3->left = n6; n3->right = n7;
	n4->left = NULL; n4->right = NULL;
	n5->left = NULL; n5->right = NULL;
	n6->left = NULL; n6->right = NULL;
	n7->left = NULL; n7->right = NULL;
	n1->data = 40; n2->data = 20; n3->data = 60;
	n4->data = 10; n5->data = 30; n6->data = 50;
	n7->data = 70;
	return n1;
}
int bt_count(tree_pointer ptr) {	// 트리의 노드수를 계산
	if (ptr == NULL) return 0;
	return (1 + bt_count(ptr->left) + bt_count(ptr->right));
}
int bt_add(tree_pointer ptr) {	// 트리의 데이터 합을 계산
	int sum = 0;
	if (ptr != NULL) {
		sum += ptr->data + bt_add(ptr->left) + bt_add(ptr->right);
	}
	return sum;
}
int bt_height(tree_pointer ptr) {	// 트리의 높이를 계산
	if (ptr == NULL) return 0;
	int left_height = bt_height(ptr->left);
	int right_height = bt_height(ptr->right);
	return (left_height >= right_height) ? (left_height + 1) : (right_height + 1);
}
void bt_show_preorder(tree_pointer ptr) {	// 트리의 내용을 preorder로 출력
	if (ptr) {
		printf("%d\t", ptr->data);
		bt_show_preorder(ptr->left);
		bt_show_preorder(ptr->right);
	}
}
void bt_show_inorder(tree_pointer ptr) {	// 트리의 내용을 inorder로 출력
	if (ptr) {
		bt_show_inorder(ptr->left);
		printf("%d\t", ptr->data);
		bt_show_inorder(ptr->right);
	}
}
void bt_free(tree_pointer ptr) { // 트리의 모든 노드를 시스템에 반환(free)
	if (ptr) {
		bt_free(ptr->left);
		bt_free(ptr->right);
		printf("Free node with item %d ...\n", ptr->data);
		free(ptr);
	}
}

//int IsBST(tree_pointer t, int min, int max) {   // true 1, false 0를 반환
//	if (t == NULL) return 1;
//	if (t->data > min && t->data < max && IsBST(t->left, min, max) && IsBST(t->right, min, max))
//		return 1;
//	else return 0;
//}

int IsBST(tree_pointer t, int min, int max) {
	if (t == NULL) return 1;

	if ((t->data < min) || (t->data > max))
		return 0;

	return IsBST(t->left, min, (t->data - 1)) && IsBST(t->right, (t->data + 1), max);
}