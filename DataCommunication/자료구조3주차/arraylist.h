#define MAXSIZE 3
#define boolean unsigned char
#define TRUE 1
#define FALSE 0

typedef char Element;
Element List[MAXSIZE] = { NULL };
int size = 0;

void list_insert(Element e);
void list_delete(Element e);
boolean list_empty();
boolean list_full();
void list_show();

void list_insert(Element e) {
	if (size == MAXSIZE){ //�迭�� �� �����
		printf("\nList is full!\n");	
	}
	List[size] = e;	//size��° �迭�� ����
	size++;	//ī��Ʈ ����
}
void list_delete(Element e) {
	for (int i = 0; i < MAXSIZE; i++) {	//�迭�ȿ�
		if (List[i] == e)	//i��°�� e��� ���ڰ� �ִٸ�
		{
			for (i; i < MAXSIZE; i++) {	//i���� �迭���� �迭�� ��ĭ�� ������ �����
				List[i] = List[i + 1];	
				List[size] == NULL;	//�� ��ĭ�� ����
			}
			size--;	//ī��Ʈ ����
		}
	}
	
}
boolean list_empty() {
	if (size == 0) return TRUE;	//����Ʈ�� ��������� TRUE
	else return FALSE;
	}
boolean list_full() {
	if (size == MAXSIZE)	return TRUE;	//����Ʈ�� ���� �������� TRUE
	else return FALSE;	
}
void list_show() {
	if (list_empty())
	{
		printf("\nList is empty!");
	}
	int i;
	for (i = 0; i < MAXSIZE; i++)
		printf("\n%c ", List[i]);
}