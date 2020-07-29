#include <iostream>
using namespace std;

struct node* TreeInit();
struct node* TreeSearch(struct node* head, int xkey);
struct node* TreeInsert(struct node* head, int xkey);
void TreeDel(node* head, int xkey);
void TreeShow(node* head);

struct node {	//노드 구조체
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
			cout << "Key 입력: >>";
			cin >> key;
			TreeInsert(t, key);
			TreeShow(t);
			cout << endl;
			continue;
		}
		else if (command == '?'){	//Search
			int search_key;
			cout << "찾을 Key 입력: >>";
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
			cout << "삭제할 Key 입력: >>";
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
	//입력: head-이진 탐색 트리 헤드 포인터 xkey-탐색 키
	//출력: 노트 포인터
	struct node* t;
	t = head->right;	//디폴트로 오른쪽 자식노드를 탐색하게 설정
	while (t != NULL) {	//탐색하는 노드의 key값을 기준으로 찾고자 하는 값보다 작다면 왼쪽, 크다면 오른쪽을 탐색한다.
		if (xkey == t->key) return t;
		else if (xkey < t->key) t = t->left;
		else t = t->right;
	}
	return NULL;
}

struct node* TreeInsert(struct node* head, int xkey) {
	//입력: head-헤드 노드 포인터, xkey-삽입 키
	//출력: xkey가 삽입된 트리
	struct node* p, * t;
	p = head; t = p->right;	//head 오른쪽부터 찾음
	while (t != NULL) {	//삽입할 위치 (부모노드 p) 찾기
		p = t;
		if (xkey == t->key) {	//동일한 키 값이 이미 존재하면 삽입하지 않고 복귀
			cout << "중복된 key 삽입 오류" << endl;
			return p; 
		}
		else if (xkey < t->key) t = t->left;
		else if (xkey > t->key) t = t->right;
	}
	t = (struct node*)malloc(sizeof * t);	//삽입할 노드 만듦
	t->key = xkey; t->left = NULL, t->right = NULL;	//키 값과 링크 지정
	if (xkey < p->key) p->left = t;	//부모 노드 키값과 비교 후 왼쪽 또는 오른쪽에 삽입
	else p->right = t;
	return p;
}

void TreeDel(node* head, int xkey) {
	//입력: head-헤드 노드 포인터, xkey-삭제 키
	//출력: xkey가 삭제된 트리
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
	if (x == NULL) { // 삭제할 노드 존재하지 않으면 그냥 리턴
		cout << "There's no such value" << endl; return;
	}
	else t = x; // tmp 노드에 del 위치 복사
	if (t->right == NULL) x = t->left;	//1. 오른쪽 자식이 없는 경우
	else if (t->right->left == NULL) {	//2. 오른쪽 자식의 왼쪽 자식이 없는 경우
		x = t->right; x->left = t->left; 
	}
	else {	//3. 그 외 나머지 경우(양쪽 노드에 자식이 있는 경우)  
		c = x->right;
		while (c->left->left != NULL)
			c = c->left;	//오른쪽 부분나무에서 가장 작은 키 찾기
		x = c->left; c->left = x->right;
		x->left = t->left; x->right = t->right;
	}
	free(t);
	if (xkey < p->key) p->left = x;
	else p->right = x;
}

void TreeShow(node* head) {	//Preorder 출력
	if (head != NULL) {
		cout << head->key << " ";
		TreeShow(head->left);
		TreeShow(head->right);
	}
}