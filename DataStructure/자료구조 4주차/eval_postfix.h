#define MAX_SIZE 100
#define boolean unsigned char
#define true 1
#define false 0

//Global stack;
int stack[MAX_SIZE];
int top = -1;

void push(int e);
int pop();
int eval_postfix(char *exp);	//exp(����ǥ�� �����)�� ó���Ͽ� ����� ��ȯ
boolean is_number(char c);	//c�� �������� �Ǻ��ϴ� �Լ�
boolean is_op(char c);	//c�� ���������� �Ǻ��ϴ� �Լ�