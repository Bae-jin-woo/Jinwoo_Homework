//CoffeeVendingMachine.cpp
#include <iostream>
#include "CoffeeVendingMachine.h"
using namespace std;
void CoffeeVendingMachine::fill() {	//3개의 통을 모두 10으로 채움
	for (int i = 0; i <= 2; i++) { tong[i].fill(); }
}
void CoffeeVendingMachine::selectEspresso() {	//물 -1, 커피 -1
	if (tong[0].getSize() >= 1 && tong[1].getSize() >= 1) {
		tong[0].consume();
		tong[1].consume();
		cout << "에스프레소 드세요" << endl;
	}
	else cout << "원료가 부족합니다." << endl;
}
void CoffeeVendingMachine::selectAmericano() {	//물-2, 커피 -1 
	if (tong[0].getSize() >= 1 && tong[1].getSize() >= 2) {
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		cout << "아메리카노 드세요" << endl;
	}
	else cout << "원료가 부족합니다." << endl;
}
void CoffeeVendingMachine::selectSugarCoffee() {	//커피-1, 물-2. 설탕 -1
	if (tong[0].getSize() >= 1 && tong[1].getSize() >= 2 && tong[2].getSize() >= 1) {
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		tong[2].consume();
		cout << "에스프레소 드세요" << endl;
	}
	else cout << "원료가 부족합니다." << endl;;
}
void CoffeeVendingMachine::show() {	//각 재료 출력
	cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << endl;
}
void CoffeeVendingMachine::run() {
	int a;
	cout << "******커피 자판기를 작동합니다.******" << endl;
	while (1) {
		cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기)>>";
		cin >> a;
		switch (a)
		{
		case 1:	CoffeeVendingMachine::selectEspresso();	break;
		case 2:	CoffeeVendingMachine::selectAmericano(); break;
		case 3:	CoffeeVendingMachine::selectSugarCoffee(); break;
		case 4:	CoffeeVendingMachine::show(); break;
		case 5:	CoffeeVendingMachine::fill(); break;
		default:
			break;
		}
	}
}

