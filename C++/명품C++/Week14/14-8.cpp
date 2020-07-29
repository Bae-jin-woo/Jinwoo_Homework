#include <iostream>
#include <string>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius = 1, string name = "") {
		this->radius = radius; this->name = name;
	}
	string getName() { return name; }
	int getRadius() { return radius; }
	void setName(string n) { this->name = n; }
	void setRadius(int r) { this->radius = r; }
	friend istream& operator >> (istream& ins, Circle& c);
	friend ostream& operator <<(ostream& stream, Circle& c);
};

ostream& operator <<(ostream& stream, Circle& c) {
	stream << "(반지름" << c.getRadius() << "인 " << c.getName() << ")";
	return stream;
}

istream& operator >> (istream& ins, Circle& c) {
	int r;
	string n;
	cout << "반지름 >>";
	cin >> r;
	c.setRadius(r);
	cout << endl << "이름>>";
	cin >> n;
	c.setName(n);
	cout << endl;
	return ins;
}

int main() {
	Circle d, w;
	cin >> d >> w;
	cout << d << w << endl;
}
