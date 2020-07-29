#include <iostream>
using namespace std;

struct node* TreeInit();
struct node* TreeSearch(struct node* head, int xkey);
struct node* TreeInsert(struct node* head, int xkey);
void TreeDel(node* head, int xkey);
void TreeShow(node* head);

struct node {	//��� ����ü
	int key;
	struct node* left;
	struct node* right;
};

int main() {
	cout << "Commands:" << endl;
	cout <<    "+ key: Insert (or update) element" << endl;
	cout <<    "? key: Retrieve element" << endl;
	cout << "   - key: Remove element" << endl;
	cout << "       Q: Quit the test program" << endl;
	char command = ' ';

	struct node* t = (struct node*) malloc(sizeof * t);	//init tree
	t->right = NULL;
	t->left = NULL;
	t->key = 0;

	while (command != 'Q') {
		
		cout << "Command >> ";
		cin >> command;
		if (command == '+') {	//Insert
			int key;
			cout << "Key �Է�: >>";
			cin >> key;
			TreeInsert(t, key);
			TreeShow(t);
			cout << endl;
			continue;
		}
		else if (command == '?'){	//Search
			int search_key;
			cout << "ã�� Key �Է�: >>";
			cin >> search_key;

			struct node *a = TreeSearch(t, search_key);
			if (a) {
				cout << "Retrieved : key = " << a->key << endl;
				if (a->left) {
					cout << "left child is " << a->left->key << endl;
				}
				else cout << "None" << endl;
				if (a->right) {
					cout << "right child is = " << a->right->key << endl;
				}
				else cout << "None" << endl;
			}
		}
		else if (command == '-') {	//Delete
			int key;
			cout << "������ Key �Է�: >>";
			cin >> key;
			TreeDel(t, key);
			TreeShow(t);
			cout << endl;
			continue;
		}
		else {	//Exception
			cout << endl << "Command Error!" << endl;
		}

	}
	cout << endl << endl << "Program End..." << endl;

}


struct node* TreeSearch(struct node* head, int xkey) {
	//�Է�: head-���� Ž�� Ʈ�� ��� ������ xkey-Ž�� Ű
	//���: ��Ʈ ������
	struct node* t;
	t = head->right;	//����Ʈ�� ������ �ڽĳ�带 Ž���ϰ� ����
	while (t != NULL) {	//Ž���ϴ� ����� key���� �������� ã���� �ϴ� ������ �۴ٸ� ����, ũ�ٸ� �������� Ž���Ѵ�.
		if (xkey == t->key) return t;
		else if (xkey < t->key) t = t->left;
		else t = t->right;
	}
	return NULL;
}

struct node* TreeInsert(struct node* head, int xkey) {
	//�Է�: head-��� ��� ������, xkey-���� Ű
	//���: xkey�� ���Ե� Ʈ��
	struct node* p, * t;
	p = head; t = p->right;	//head �����ʺ��� ã��
	while (t != NULL) {	//������ ��ġ (�θ��� p) ã��
		p = t;
		if (xkey == t->key) {	//������ Ű ���� �̹� �����ϸ� �������� �ʰ� ����
			cout << "�ߺ��� key ���� ����" << endl;
			return p; 
		}
		else if (xkey < t->key) t = t->left;
		else if (xkey > t->key) t = t->right;
	}
	t = (struct node*)malloc(sizeof * t);	//������ ��� ����
	t->key = xkey; t->left = NULL, t->right = NULL;	//Ű ���� ��ũ ����
	if (xkey < p->key) p->left = t;	//�θ� ��� Ű���� �� �� ���� �Ǵ� �����ʿ� ����
	else p->right = t;
	return p;
}

void TreeDel(node* head, int xkey) {
	//�Է�: head-��� ��� ������, xkey-���� Ű
	//���: xkey�� ������ Ʈ��
	struct node* p, * c, * t, * x;
	p = head; x = head->right;
	while (x != NULL) {
		if (xkey == x->key) { break; }
		else if (xkey < x->key) {
			p = x;
			x = x->left;
		}
		else {
			p = x;
			x = x->right;
		}
	}
	if (x == NULL) { // ������ ��� �������� ������ �׳� ����
		cout << "There's no such value" << endl; return;
	}
	else t = x; // tmp ��忡 del ��ġ ����
	if (t->right == NULL) x = t->left;	//1. ������ �ڽ��� ���� ���
	else if (t->right->left == NULL) {	//2. ������ �ڽ��� ���� �ڽ��� ���� ���
		x = t->right; x->left = t->left; 
	}
	else {	//3. �� �� ������ ���(���� ��忡 �ڽ��� �ִ� ���)  
		c = x->right;
		while (c->left->left != NULL)
			c = c->left;	//������ �κг������� ���� ���� Ű ã��
		x = c->left; c->left = x->right;
		x->left = t->left; x->right = t->right;
	}
	free(t);
	if (xkey < p->key) p->left = x;
	else p->right = x;
}

void TreeShow(node* head) {	//Preorder ���
	if (head != NULL) {
		cout << head->key << " ";
		TreeShow(head->left);
		TreeShow(head->right);
	}
}