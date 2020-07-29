typedef struct tree_node* tree_pointer;
typedef struct tree_node {
	int key;
	int data;
	tree_pointer left;
	tree_pointer right;
}tree_node;
tree_pointer root = NULL;   //BST�� root�� ����Ű�� ������(��������)


void bst_insert(int key, char data);   //Ʈ���� (key,data)�ڷ� ����
char bst_search(int key);   //Ʈ������ Ű���� key�� �ڷḦ �˻�, data�� ��ȯ
void bst_show_inorder(tree_pointer ptr);   //Ʈ���� �ڷ���� inorder�� ���
