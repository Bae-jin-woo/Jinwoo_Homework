#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; }
};
class NamedCircle : public Circle {
	string name;
public:
	void setName(string name) { this->name = name; }
	string getName() { return name; }
};
int main() {
	NamedCircle pizza[5];
	int r;
	string name;
	int max_area = 0;
	int count;
	cout << "5개의 정수 반지름과 원의 이름을 입력하세요." << endl;
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ">>";
		cin >> r >> name;
		pizza[i].setRadius(r);
		pizza[i].setName(name);
		if (pizza[i].getArea() > max_area) {
			max_area = pizza[i].getArea();
			count = i;
		}
	}
	cout << "가장 면적이 큰 피자는 " << pizza[count].getName() << "입니다." << endl;
}
