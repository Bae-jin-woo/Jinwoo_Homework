#include <iostream>
#include <string>
using namespace std;

class AbstractGate {	//추상 클래스
protected:
	bool x, y;
public:
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0;
};

class ANDGate : public AbstractGate {
public:
	bool operation();
};

bool ANDGate::operation() {	//AND 연산
	if (x && y) return true;
	else return false;
}

class ORGate : public AbstractGate {
public:
	bool operation();
};

bool ORGate::operation() {	//OR 연산
	if (x || y)return true;
	else return false;
}

class XORGate : public AbstractGate {
public:
	bool operation();
};

bool XORGate::operation() {	//XOR 연산
	if (x != y) return true;
	else return false;
}

int main() {
	ANDGate andGate;
	ORGate orGate;
	XORGate xorGate;

	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);
	cout.setf(ios::boolalpha);
	cout << andGate.operation() << endl;
	cout << orGate.operation() << endl;
	cout << xorGate.operation() << endl;
}
