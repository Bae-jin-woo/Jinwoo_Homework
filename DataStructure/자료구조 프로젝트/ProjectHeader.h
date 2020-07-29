#pragma warning(disable:4996)
#define	TABLE_SIZE 997
#define	boolean	unsigned char
#define	true	1
#define	false	0

// Hash table
typedef struct {
	char key[100];
	char data[100];
	int	num_word;
} element;
typedef struct list *list_ptr;

// Hash chainning
typedef struct list {
	element	item;
	list_ptr link; 
	list_ptr left_word;
	list_ptr right_word;
}list;
list_ptr hash_table[TABLE_SIZE];
list_ptr last;

//typedef struct address *address_ptr;
typedef struct address {
	list_ptr hash_table_a[TABLE_SIZE];
	int re_n_word;
}address;
address sorting_list[10];
//address_ptr sorting_list[10];

int dcount, ccount, num_word, link_num, fcount;	//fcount 
// For caomparison count
int num_comparison;
// ���Ͽ��� �ܾ���� �о� �ؽ����̺�� Ʈ�� ����
int build_table(char *fname);

// �ؽ����̺� (key, data) �ڷ� ����
int hash_insert(element item);
// �ؽ����̺��� Ű���� key�� �ڷḦ �˻�, data�� ��ȯ
int * hash_search(char *key);
// �ؽ����̺��� key���� ���ʷ� ��� 
void hash_show();
//ã�� �ܾ��� �յ� 3�ܾ ����ϴ� �Լ�
void print_pre_front(list_ptr word);

// �ؽ� �Լ� (folding + division (TABLE_SIZE�� ���� ������))
int hash(char *key);
// folding (key�� �� character ���� ����)
int transform(char *key);
// ���������� �ƴ��� �˻��ϴ� �Լ�
boolean is_word_alpha(char w);

void in_sorting();