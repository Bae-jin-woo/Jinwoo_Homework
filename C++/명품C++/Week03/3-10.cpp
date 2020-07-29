#include <iostream>
using namespace std;

class Add {	//클래스 선언
	int a, b;
public:
	void setValue(int x, int y);
	int calculate();
};
class Sub {
	int a, b;
public:
	void setValue(int x, int y);
	int calculate();
};
class Mul {
	int a, b;
public:
	void setValue(int x, int y);
	int calculate();
};
class Div {
	int a, b;
public:
	void setValue(int x, int y);
	int calculate();
};
void Add::setValue(int x, int y) { a = x, b = y; }	//함수 구현
int Add::calculate() { return a + b; }
void Sub::setValue(int x, int y) { a = x, b = y; }
int Sub::calculate() { return a - b; }
void Mul::setValue(int x, int y) { a = x, b = y; }
int Mul::calculate() { return a * b; }
void Div::setValue(int x, int y) { a = x, b = y; }
int Div::calculate() { return a / b; }
int main() {
	Add a;	//객체 생성
	Sub s;
	Mul m;
	Div d;
	int x, y;
	char cal;
	while (true)
	{
		cout << "두 정수와 연산자를 입력하세요>>";
		cin >> x >> y >> cal;
		switch (cal)	
		{
		case '+':
			 a.setValue(x, y);
			cout<<a.calculate()<<endl;
			break;
		case '-':
			s.setValue(x, y);
			cout << s.calculate() << endl;
			break;
		case '*':
			m.setValue(x, y);
			cout << m.calculate() << endl;
			break;
		case '/':
			d.setValue(x, y);
			cout << d.calculate() << endl;
			break;
		default:
			cout << "입력 오류" << endl;
			break;
		}
	}
	return 0;
}
