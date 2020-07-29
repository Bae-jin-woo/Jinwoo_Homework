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
	if (size == MAXSIZE){ //배열이 다 찰경우
		printf("\nList is full!\n");	
	}
	List[size] = e;	//size번째 배열에 저장
	size++;	//카운트 증가
}
void list_delete(Element e) {
	for (int i = 0; i < MAXSIZE; i++) {	//배열안에
		if (List[i] == e)	//i번째에 e라는 문자가 있다면
		{
			for (i; i < MAXSIZE; i++) {	//i번쨰 배열부터 배열을 한칸씩 앞으로 땡기고
				List[i] = List[i + 1];	
				List[size] == NULL;	//맨 끝칸은 비운다
			}
			size--;	//카운트 감소
		}
	}
	
}
boolean list_empty() {
	if (size == 0) return TRUE;	//리스트가 비어있으면 TRUE
	else return FALSE;
	}
boolean list_full() {
	if (size == MAXSIZE)	return TRUE;	//리스트가 가득 차있으면 TRUE
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