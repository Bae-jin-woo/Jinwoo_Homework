//2015112128 배진우
#define RED 1
#define BLACK 0
#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct node {	//노드 구조체
	int key;
	int color;
	struct node* right;
	struct node* left;
	struct node* p;
} NODE;

NODE* ROOT;	//루트와 NILL은 전역변수로 처리한다.
NODE* NILL;

void insert_node(int);
void insert_fixup(NODE*);
void TreeShow(NODE*);	
void left_rotate(NODE*);	
void right_rotate(NODE*);

int main() {

	NILL = (NODE*)malloc(sizeof(NODE));
	NILL->color = BLACK;
	ROOT = NILL;
	cout << "Commands:" << endl;
	cout << "+ : Insert (or update) element" << endl;
	cout << "Q : Quit the test program" << endl;
	char command = ' ';

	while (command != 'Q') {

		cout << "Command >> ";
		cin >> command;
		if (command == '+') {	//Insert
			int key;
			cout << "Key 입력: >>";
			cin >> key;
			insert_node(key);
			TreeShow(ROOT);
			cout << endl;
			continue;
		}
		else {	//Exception
			cout << endl << "Command Error!" << endl;
		}

	}
	cout << endl << endl << "Program End..." << endl;
}

// left-rotate를 수행하는 함수이다.
// y의 왼쪽 서브트리를 x의 오른쪽 서브트리로 옮기고
// y의 왼쪽 자식에 x를 연결한다. 
void left_rotate(NODE* x) {
	NODE* y;
	y = x->right;
	x->right = y->left;
	if (y->left != NILL) y->left->p = x;
	y->p = x->p;
	if (y->p == NILL) ROOT = y; //루트가 바뀌는 부분
	else if (x == x->p->left) x->p->left = y;
	else x->p->right = y;
	y->left = x;
	x->p = y;
}

// right-rotate를 수행하는 함수이다.
// x의 오른쪽 서브트리를 y의 왼쪽 서브트리로 옮기고
// x의 오른쪽 자식에 y를 연결한다.
void right_rotate(NODE* x) {
	NODE* y;
	y = x->left;
	x->left = y->right;
	if (y->right != NILL) y->right->p = x;
	y->p = x->p;
	if (y->p == NILL) ROOT = y; //루트가 바뀌는 부분
	else if (x == x->p->left) x->p->left = y;
	else x->p->right = y;
	y->right = x;
	x->p = y;
}

// 노드를 삽입하는 함수.
// 이진 탐색 트리와 동일한 규칙으로 삽입 위치를 찾아서 ROOT 트리에 삽입한 후
// 레드블랙 트리의 규칙을 만족하기 위해 fixup함수를 호출한다.
void insert_node(int key) {
	NODE* n = (NODE*)malloc(sizeof(NODE));
	NODE* temp = ROOT;
	NODE* p = NILL;

	n->left = NILL;
	n->right = NILL;
	n->color = RED;
	n->key = key;

	while (temp != NILL) {
		p = temp;
		if (key > temp->key) temp = temp->right;
		else temp = temp->left;
	}
	n->p = p;
	if (p == NILL) ROOT = n;
	else if (key > p->key) p->right = n;
	else p->left = n;
	insert_fixup(n);
}
//레드블랙 트리의 특성을 복구시켜주는 함수이다. 삽입 후 호출되며
//위배 될 수 있는 두 가지 규칙을 해결해준다.
void insert_fixup(NODE* x) {
	NODE* u = NULL;	//삼촌
	while (x->p->color == RED) {	//부모가 적색일 경우
		if (x->p == x->p->p->left) {	//x의 부모가 왼쪽자식일 경우
			u = x->p->p->right;	//삼촌은 오른쪽 자식이다.
			if (u->color == RED) {	//경우1 삼촌이 적색일 경우 p와 u를 흑색으로 칠해서 해결 후 새로운 x 지정	
				x->p->color = BLACK;
				u->color = BLACK;
				x->p->p->color = RED;
				x = x->p->p;
			}
			else {	//삼촌이 흑색일 경우
				if (x == x->p->right) {	//경우2 삼촌이 흑색이며 x가 오른쪽 자식일 경우 left rotate 하여 경우3으로 전환
					x = x->p;
					left_rotate(x);
				}
				x->p->color = BLACK;	//경우3 부모와 조부모의 색깔을 바꾸고 right rotate를 수행
				x->p->p->color = RED;
				right_rotate(x->p->p);
			}
		}
		else {	//x의 부모가 오른쪽 자식일 경우 
			u = x->p->p->left;	//삼촌은 왼쪽자식이다.
			if (u->color == RED) {	//경우1 삼촌이 적색일 경우 p와 u를 흑색으로 칠해서 해결 후 새로운 x 지정	
				x->p->color = BLACK;
				u->color = BLACK;
				x->p->p->color = RED;
				x = x->p->p;
			}
			else {	//삼촌이 흑색일 경우
				if (x == x->p->left) {	//경우3 삼촌이 흑색이며 x가 왼쪽 자식일 경우 right rotate 하여 경우2으로 전환
					x = x->p;
					right_rotate(x);
				}
				x->p->color = BLACK;	//경우2 부모와 조부모의 색깔을 바꾸고 left rotate를 수행
				x->p->p->color = RED;
				left_rotate(x->p->p);
			}
		}
	}
	ROOT->color = BLACK;
}

void TreeShow(NODE* x) {	//Preorder 출력
	if (ROOT == NULL) return;

	if (x != NILL) {
		TreeShow(x->left);
		cout << x->key;
		if (x->color == BLACK) {
			cout << "[B] ";
		}
		else {
			cout << "[R] ";
		}
		TreeShow(x->right);
	}
}