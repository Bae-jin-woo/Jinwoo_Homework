#include <iostream>
using namespace std;
class MyIntStack {
	int p[10];	//최대 10개의 정수 저장
	int tos = -1;	//스택의 꼭대기를 가리키는 인덱스
public:
	MyIntStack() {};
	bool push(int n);	//정수 n 푸시, 꽉 차있으면 false, 아니면 true 리턴
	bool pop(int &n);	//팝하여 n에 저장. 스택이 비어 있으면, false, 아니면 true 리턴
};
bool MyIntStack::push(int n){	//정수 n 푸시, 꽉 차있으면 false, 아니면 true 리턴
	if (tos == 9) {	//스택이 꽉 차있으면
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
	MyIntStack a;
	for (int i = 0; i < 11; i++) {	//11개를 푸시하면, 마지막에는 stack full이 된다.
		if (a.push(i))	cout << i << ' ';	//푸시된 값 에코
		else cout << endl << i + 1 << " 번째 stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) {	//11개를 팝하면, 마지막에는 stack empty가 된다.
		if (a.pop(n)) cout << n << ' ';	//팝 한 값 출력
		else cout << endl << i + 1 << " 번째 stack empty";
	}
	cout << endl;
}
