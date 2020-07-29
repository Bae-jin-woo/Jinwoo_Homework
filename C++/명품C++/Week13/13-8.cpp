#include <iostream>
using namespace std;

class Comparable {	//추상 클래스
public:
	virtual bool operator > (Comparable& op2) = 0;
	virtual bool operator < (Comparable& op2) = 0;
	virtual bool operator == (Comparable& op2) = 0;
};

class Circle : public Comparable {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
	bool operator > (Comparable& op2);
	bool operator < (Comparable& op2);
	bool operator == (Comparable& op2);
};

bool Circle::operator>(Comparable& op2) {	//캐스팅으로 > 연산자 구현
	Circle *op;
	op = (Circle*)&op2;
	if (this->getRadius() > op->getRadius()) return true;
	else return false;
}
bool Circle::operator<(Comparable& op2) {	//캐스팅으로 < 연산자 구현
	Circle *op;
	op = (Circle*)&op2;
	if (this->getRadius() < op->getRadius()) return true;
	else return false;
}
bool Circle::operator==(Comparable& op2) {	//캐스팅으로 == 연산자 구현
	Circle *op;
	op = (Circle*)&op2;
	if (this->getRadius() == op->getRadius()) return true;
	else return false;
}

template<class T> T bigger(T a, T b) {
	if (a > b) return a;
	else return b;
}

int main() {
	int a = 20, b = 50, c;
	c = bigger(a, b);
	cout << "20과 50중 큰 값은 " << c << endl;
	Circle waffle(10), pizza(20), y;
	y = bigger(waffle, pizza);
	cout << "waffle과 pizza중 큰 것의 반지름은" << y.getRadius() << endl;
}
