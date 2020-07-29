#include <iostream>
#include <string>
using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0;	//스택에 n을 푸시한다. 스택이 full이면 false 리턴
	virtual bool pop(int &n) = 0;	//스택에서 팝한 정수를 n에 저장하고 스택이 empty이면 false 리턴
	virtual int size() = 0;	//현재 스택에 저장된 정수의 개수 리턴
};

class IntStack : public AbstractStack {
	int *stack = new int[10];
	int top = -1;
public:
	bool push(int n);
	bool pop(int &n);
	int size();
	~IntStack() { delete[] stack; }
};

bool IntStack::push(int n) {
	if (top == 9) return false;	// 스택이 full이면 false 리턴
	else {
		stack[++top] = n;
		cout << n << "을 스택에 push" << endl;
		return true;
	}
}
bool IntStack::pop(int &n) {
	if (top == -1) return false;	// 스택이 empty이면 false 리턴
	else {
		n = stack[top--];
		cout << n << "을 스택에서 pop" << endl;
		return true;
	}
}
int IntStack::size() {
	return top + 1;
}

int main() {
	int n;
	IntStack iStack;
	iStack.push(1);
	iStack.push(2);
	iStack.push(3);
	iStack.push(4);
	cout << "현재 스택의 크기 : " << iStack.size() << endl;
	iStack.pop(n);
	iStack.pop(n);
	iStack.pop(n);
	iStack.pop(n);
	cout << "현재 스택의 크기 : " << iStack.size() << endl;	
}
