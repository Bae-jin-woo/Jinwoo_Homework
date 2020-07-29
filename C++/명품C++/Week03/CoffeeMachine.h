//함수 선언부 헤더파일
#ifndef COFFEEMACHINE_H
#define COFFEEMACHINE_H
class CoffeeMachine {
	int coffee, water, sugar;
public:
	CoffeeMachine(int c, int w, int s);
	void drinkEspresso();
	void drinkAmericano();
	void drinkSugarCoffee();
	void show();
	void fill();
};
#endif
