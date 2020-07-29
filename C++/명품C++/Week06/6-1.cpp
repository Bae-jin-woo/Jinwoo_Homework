#include <iostream>
using namespace std;
class Circle {
	int radius;	//반지름
public:
	Circle(){}
	Circle(int r) { this->radius = r; }
	int getRadius() { return radius; }
};
void Circle_Swap(Circle &c1,Circle &c2) {	//참조의 의한 호출
	Circle temp;
	temp = c1;
	c1 = c2;
	c2 = temp;
}
int main() {
	Circle c1(1), c2(2);
	cout << "---Swap 전---" << endl;		//바꾸기 전
	cout << "c1의 반지름 : " << c1.getRadius() << endl;
	cout << "c2의 반지름 : " << c2.getRadius() << endl;
	Circle_Swap(c1, c2);
	cout << "---Swap 후---" << endl;		//바꾼 후
	cout << "c1의 반지름 : " << c1.getRadius() << endl;
	cout << "c2의 반지름 : " << c2.getRadius() << endl;
}
