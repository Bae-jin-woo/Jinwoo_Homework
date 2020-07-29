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
// 파일에서 단어들을 읽어 해시테이블과 트리 구성
int build_table(char *fname);

// 해시테이블에 (key, data) 자료 삽입
int hash_insert(element item);
// 해시테이블에서 키값이 key인 자료를 검색, data를 반환
int * hash_search(char *key);
// 해시테이블의 key들을 차례로 출력 
void hash_show();
//찾은 단어의 앞뒤 3단어를 출력하는 함수
void print_pre_front(list_ptr word);

// 해시 함수 (folding + division (TABLE_SIZE로 나눈 나머지))
int hash(char *key);
// folding (key의 각 character 값을 더함)
int transform(char *key);
// 영문자인지 아닌지 검사하는 함수
boolean is_word_alpha(char w);

void in_sorting();