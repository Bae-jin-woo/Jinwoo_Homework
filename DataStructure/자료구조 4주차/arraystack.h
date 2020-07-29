#define MAX_SIZE 10
#define boolean unsigned char
#define true 1
#define false 0
typedef char Element;
//Global stack 
Element stack[MAX_SIZE];
int top = -1;	//스택이 비어있는 경우
void push(Element e);
Element pop();
void stack_show();	//스택 출력 함수
void stack_empty();	//스택이 비었을때
void stack_full();	//스택이 다 찼을때