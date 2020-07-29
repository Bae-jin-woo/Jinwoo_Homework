#include <iostream>
#include "Circle.h"
using namespace std;
int main() {
	int num, r;
	int count = 0;	//카운트
	cout << "원의 갯수 >>";
	cin >> num;
	Circle *circle = new Circle[num];	//클래스배열 동적할당
	for (int i = 0; i < num; i++) {
		cout << "원 " << i + 1 << "의 반지름 >>";
		cin >> r;
		circle[i].setRadius(r);	//반지름 입력
		if (circle[i].getArea() > 100) count++;	//넓이가 100보다 크면 카운트
	}
	cout << "반지름이 100보다 큰 원은 " << count << "개 입니다." << endl;
	delete[] circle;	//메모리 반환
}
