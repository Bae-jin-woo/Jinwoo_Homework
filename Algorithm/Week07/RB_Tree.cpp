//2015112128 ������
#define RED 1
#define BLACK 0
#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct node {	//��� ����ü
	int key;
	int color;
	struct node* right;
	struct node* left;
	struct node* p;
} NODE;

NODE* ROOT;	//��Ʈ�� NILL�� ���������� ó���Ѵ�.
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
			cout << "Key �Է�: >>";
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

// left-rotate�� �����ϴ� �Լ��̴�.
// y�� ���� ����Ʈ���� x�� ������ ����Ʈ���� �ű��
// y�� ���� �ڽĿ� x�� �����Ѵ�. 
void left_rotate(NODE* x) {
	NODE* y;
	y = x->right;
	x->right = y->left;
	if (y->left != NILL) y->left->p = x;
	y->p = x->p;
	if (y->p == NILL) ROOT = y; //��Ʈ�� �ٲ�� �κ�
	else if (x == x->p->left) x->p->left = y;
	else x->p->right = y;
	y->left = x;
	x->p = y;
}

// right-rotate�� �����ϴ� �Լ��̴�.
// x�� ������ ����Ʈ���� y�� ���� ����Ʈ���� �ű��
// x�� ������ �ڽĿ� y�� �����Ѵ�.
void right_rotate(NODE* x) {
	NODE* y;
	y = x->left;
	x->left = y->right;
	if (y->right != NILL) y->right->p = x;
	y->p = x->p;
	if (y->p == NILL) ROOT = y; //��Ʈ�� �ٲ�� �κ�
	else if (x == x->p->left) x->p->left = y;
	else x->p->right = y;
	y->right = x;
	x->p = y;
}

// ��带 �����ϴ� �Լ�.
// ���� Ž�� Ʈ���� ������ ��Ģ���� ���� ��ġ�� ã�Ƽ� ROOT Ʈ���� ������ ��
// ����� Ʈ���� ��Ģ�� �����ϱ� ���� fixup�Լ��� ȣ���Ѵ�.
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
//����� Ʈ���� Ư���� ���������ִ� �Լ��̴�. ���� �� ȣ��Ǹ�
//���� �� �� �ִ� �� ���� ��Ģ�� �ذ����ش�.
void insert_fixup(NODE* x) {
	NODE* u = NULL;	//����
	while (x->p->color == RED) {	//�θ� ������ ���
		if (x->p == x->p->p->left) {	//x�� �θ� �����ڽ��� ���
			u = x->p->p->right;	//������ ������ �ڽ��̴�.
			if (u->color == RED) {	//���1 ������ ������ ��� p�� u�� ������� ĥ�ؼ� �ذ� �� ���ο� x ����	
				x->p->color = BLACK;
				u->color = BLACK;
				x->p->p->color = RED;
				x = x->p->p;
			}
			else {	//������ ����� ���
				if (x == x->p->right) {	//���2 ������ ����̸� x�� ������ �ڽ��� ��� left rotate �Ͽ� ���3���� ��ȯ
					x = x->p;
					left_rotate(x);
				}
				x->p->color = BLACK;	//���3 �θ�� ���θ��� ������ �ٲٰ� right rotate�� ����
				x->p->p->color = RED;
				right_rotate(x->p->p);
			}
		}
		else {	//x�� �θ� ������ �ڽ��� ��� 
			u = x->p->p->left;	//������ �����ڽ��̴�.
			if (u->color == RED) {	//���1 ������ ������ ��� p�� u�� ������� ĥ�ؼ� �ذ� �� ���ο� x ����	
				x->p->color = BLACK;
				u->color = BLACK;
				x->p->p->color = RED;
				x = x->p->p;
			}
			else {	//������ ����� ���
				if (x == x->p->left) {	//���3 ������ ����̸� x�� ���� �ڽ��� ��� right rotate �Ͽ� ���2���� ��ȯ
					x = x->p;
					right_rotate(x);
				}
				x->p->color = BLACK;	//���2 �θ�� ���θ��� ������ �ٲٰ� left rotate�� ����
				x->p->p->color = RED;
				left_rotate(x->p->p);
			}
		}
	}
	ROOT->color = BLACK;
}

void TreeShow(NODE* x) {	//Preorder ���
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