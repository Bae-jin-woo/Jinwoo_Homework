#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius;}
};

class NamedCircle : public Circle {
	string name;
public:
	NamedCircle(int n, string s) {
		this->name = s;
		setRadius(n);
	}
	void show() {
		cout << "반지름이 " << this->getRadius() << "인 " << this->name << endl;
	}
};

int main() {
	NamedCircle waffle(3, "waffle");
	waffle.show();
}
