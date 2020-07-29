#include <iostream>
using namespace std;

class MyIntStack {
	int *p;	//스택 메모리로 사용할 포인터
	int size = 1;	//스택의 최대 크기
	int tos = -1;	//스택의 탑을 가리키는 인덱스, -1로 초기화
public:
	MyIntStack() { p = new int[size]; }	//디폴트로 호출될 경우 크기 1로 고정
	MyIntStack(int size) { this->size = size; p = new int[size]; }	//크기를 입력받을 경우 크기만큼의 배열 생성
	MyIntStack(const MyIntStack& s);
	~MyIntStack() { delete[] p; }	//소멸자, 동적 메모리 해제
	bool push(int n);
	bool pop(int &n);	
};
MyIntStack::MyIntStack(const MyIntStack& s) {	//깊은복사 생성자
	this->size = s.size;
	this->tos = s.tos;
	this->p = new int[s.size];
	for (int i = 0; i < s.size; i++) {
		this->p[i] = s.p[i];
	}
}
bool MyIntStack::push(int n) {	//정수 n 푸시, 꽉 차있으면 false, 아니면 true 리턴
	if (tos == (size-1)) {	//스택이 꽉 차있으면
		return false;
	}
	else {
		p[++tos] = n;	//스택에 꼭대기에 값 삽입
		return true;
	}
}
bool MyIntStack::pop(int &n) {	//팝하여 n에 저장. 스택이 비어 있으면, false, 아니면 true 리턴
	if (tos == -1) {
		return false;
	}
	else {
		n = p[tos--];	//스택의 꼭대기 값을 n에 저장
		return true;
	}
}
int main() {
	MyIntStack a(10);	//10크기의 스택 생성
	a.push(10);	//스택에 10 삽입
	a.push(20);	//스택에 20 삽입
	MyIntStack b = a;	//복사 생성
	b.push(30);	//스택에 30 삽입
	int n;
	a.pop(n);	//스택 a 팝
	cout << "스택 a에서 팝한 값" << n << endl;
	b.pop(n);	//스택 b 팝
	cout << "스택 b에서 팝한 값" << n << endl;
}
