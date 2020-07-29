//함수구현부 cpp파일
#include <iostream>
using namespace std;
#include "CoffeeMachine.h"

CoffeeMachine::CoffeeMachine(int c, int w, int s) {	//생성자
	coffee = c;
	water = w;
	sugar = s;
}
void CoffeeMachine::drinkEspresso() {	//에스프레소
	coffee -= 1;
	water -= 1;
}
void CoffeeMachine::drinkAmericano() {	//아메리카노
	coffee -= 1;
	water -= 2;
}
void CoffeeMachine::drinkSugarCoffee() {	//설탕커피
	coffee -= 1;
	water -= 2;
	sugar -= 1;
}
void CoffeeMachine::show() {	//현재상태
	cout << "커피 마신 상태, " << "커피:" << coffee << " 물:" << water << " 설탕:" << sugar << endl;
}
void CoffeeMachine::fill() {	//채우기
	coffee = 10;
	water = 10;
	sugar = 10;
}
