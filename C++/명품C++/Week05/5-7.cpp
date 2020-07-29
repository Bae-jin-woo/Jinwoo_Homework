#include <iostream>
#include "Circle.h"
using namespace std;
int main() {
	Circle circle[3];	//클래스 배열 생성
	int r = 0;
	int count = 0;	//카운트
	for (int i = 0; i < 3; i++) {
		cout << "원 " << i + 1 << "의 반지름 >>";
		cin >> r;
		circle[i].setRadius(r);	//반지름 입력
		if (circle[i].getArea() > 100) count++;	//넓이가 100보다 크면 카운트
	}
	cout << "반지름이 100보다 큰 원은 " << count << "개 입니다." << endl;
}
