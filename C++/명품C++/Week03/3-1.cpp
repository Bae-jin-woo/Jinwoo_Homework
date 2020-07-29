//main.cpp 메인함수
#include <iostream>
using namespace std;
#include "Tower.h"

int main() {
	Tower myTower;	//기본생성자 객체생성
	Tower seoulTower(100);	//매개변수가 있는 객체생성ㅁ
	cout << "높이는 " << myTower.getHeight() << " 미터" << endl;
	cout << "높이는 " << seoulTower.getHeight() << " 미터" << endl;
	system("pause");
	return 0;
}
