#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class CoffeeMaterial {
	int coffee;
	int sugar;
	int cream;
	int water;
	int cup;
public:
	CoffeeMaterial(int coffee = 3, int sugar = 3, int cream = 3, int water = 3, int cup = 3) {
		this->coffee = coffee;
		this->sugar = sugar;
		this->cream = cream;
		this->water = water;
		this->cup = cup;
	}
	int getCoffee() { return coffee; }
	int getSugar() { return sugar; }
	int getCream() { return cream; }
	int getWater() { return water; }
	int getCup() { return cup; }
	void subCoffee(int n) { this->coffee -= n; }
	void subSugar(int n) { this->sugar -= n; }
	void subCream(int n) { this->cream -= n; }
	void subWater(int n) { this->water -= n; }
	void subCup(int n) { this->cup -= n; }
	void fill() { coffee = sugar = cream = water = cup = 3; }
	void show();
};

void CoffeeMaterial::show() {
	cout << setw(10) << left << "Coffee";
	
	for (int i = 0; i < this->getCoffee(); i++)
		cout << left << "*";
	cout << endl;
	cout << setw(10) << left << "Sugar";
	
	for (int i = 0; i < this->getSugar(); i++)
		cout << left << "*";
	cout << endl;
	cout << setw(10) << left << "Cream";
	
	for (int i = 0; i < this->getCream(); i++)
		cout << left << "*";
	cout << endl;
	cout << setw(10) << left << "Water";
	
	for (int i = 0; i < this->getWater(); i++)
		cout << left << "*";
	cout << endl;
	cout << setw(10) << left << "Cup";
	
	for (int i = 0; i < this->getCup(); i++)
		cout << left << "*";
	cout << endl;
}

class CoffeeMaker : public CoffeeMaterial {
public:
	void NormalCoffee();	//일반커피
	void SugarCoffee();	//설탕커피
	void BlackCoffee();	//블랙커피
};

void CoffeeMaker::NormalCoffee() {	//일반커피 커피1, 설탕1, 크림1, 물1, 컵1 소모
	this->subCoffee(1);
	this->subSugar(1);
	this->subCream(1);
	this->subWater(1);
	this->subCup(1);
}

void CoffeeMaker::SugarCoffee() {	//설탕커피 커피1, 설탕1, 물1, 컵1 소모
	this->subCoffee(1);
	this->subSugar(1);
	this->subWater(1);
	this->subCup(1);
}

void CoffeeMaker::BlackCoffee() {	//블랙커피 커피1, 물1, 컵1 소모
	this->subCoffee(1);
	this->subWater(1);
	this->subCup(1);
}

int main() {
	CoffeeMaker c;
	int type = 0;
	cout << "----- 명품 커피 자판기입니다.----" << endl;
	c.show();
	cout << endl << endl;
	while (true) {
		cout << "보통 커피:0, 설탕 커피:1, 블랙 커피:2, 채우기:3, 종료:4 >>";
		cin >> type;
		switch (type) {
		case 0:
			if (c.getCoffee() >= 1 && c.getSugar() >= 1 && c.getCream() >= 1 && c.getWater() >= 1 && c.getCup() >= 1) {
				c.NormalCoffee();
				cout << "맛있는 보통 커피 나왔습니다~~" << endl;
				c.show();
				break;
			}
			else {
				cout << "재료 부족" << endl;
				c.show();
				break;
			}
		case 1:
			if (c.getCoffee() >= 1 && c.getSugar() >= 1 && c.getWater() >= 1 && c.getCup() >= 1) {
				c.SugarCoffee();
				cout << "맛있는 설탕 커피 나왔습니다~~" << endl;
				c.show();
				break;
			}
			else {
				cout << "재료 부족" << endl;
				c.show();
				break;
			}
		case 2:
			if (c.getCoffee() >= 1 && c.getWater() >= 1 && c.getCup() >= 1) {
				c.BlackCoffee();
				cout << "맛있는 블랙 커피 나왔습니다~~" << endl;
				c.show();
				break;
			}
			else {
				cout << "재료 부족" << endl;
				c.show();
				break;
			}
		case 3:
			cout << "모든 통을 채웁니다." << endl;
			c.fill();
			c.show();
		case 4: exit(1);
		default:
			break;
		}
	}
}
