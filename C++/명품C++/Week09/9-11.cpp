#include <iostream>
using namespace std;

class Stack {
	int top = -1;;
	int *data = new int[10];
public:
	Stack() {};
	Stack& operator <<(int num);
	bool operator !();
	int operator >>(int& num);
};
bool Stack::operator !() {
	if (top==-1) return true;
	else return false;
}
Stack& Stack::operator<<(int num) {
	data[++top] = num;
	return *this;
}
int Stack::operator>>(int& num) {
	num = data[top--];
	return num;
}
int main() {
	Stack stack;
	stack << 3 << 5 << 10;
	while (true) {
		if (!stack) break;	//스택 empty
		int x;
		stack >> x;
		cout << x << ' ';
	}
	cout << endl;
}
