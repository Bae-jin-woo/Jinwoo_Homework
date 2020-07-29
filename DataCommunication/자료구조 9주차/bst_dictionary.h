// Binary search tree node
typedef struct tree_node *tree_pointer;
typedef struct tree_node {
	char w1[100];
	char w2[100];
	tree_pointer left;
	tree_pointer right;
} tree_node;
tree_pointer root = NULL;   // BST�� root�� ����Ű�� ������ (��������)
int wcount;

int build_dictionary(char *fname); // ���Ͽ��� �ܾ���� �о� ����Ž��Ʈ�� ����
void bst_insert(char *w1, char *w2); // Ʈ���� (w1, w2) �ڷ� ����
char * bst_search(char *w1); // Ʈ������ Ű���� w1�� �ڷḦ �˻�, w2�� ��ȯ
void bst_show_inorder(tree_pointer ptr); // Ʈ���� �ܾ���� inorder�� ��� 