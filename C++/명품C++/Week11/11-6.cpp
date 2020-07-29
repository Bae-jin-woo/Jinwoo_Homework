#include <iostream>
#include <string>
using namespace std;

class BaseArray {
private:
	int capacity;	//배열의 크기
	int *mem;	//정수 배열을 만들기 위한 메모리의 포인터
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() { delete[]mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyStack : public BaseArray {
	int top = -1;
public:
	MyStack(int n) : BaseArray(n) {
		
	}
	void push(int n) {	//스택 삽입
		put(++top, n);
	}
	int pop() {	//스택 삭제
		if (top==-1) {
			return 0;
		}
		else return get(top--);
	}
	int length() {	//스택 길이
		return (top + 1);
	}
	int capacity() {	//스택 용량
		return getCapacity();
	}
};

int main() {
	MyStack mStack(100);
	int n;
	cout << "스택에 삽입할 5개의 정수를 입력하라>>";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n);
	}
	cout << "스택용량:" << mStack.capacity() << ", 스택크기:" << mStack.length() << endl;
	cout << "스택의 모든 원소를 팝하여 출력한다>>";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' ';
	}
	cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;

}
