#include <iostream>
#include <string>
using namespace std;

class Printer {
public:
	string model;	//모델명
	string manufacturer;	//제조사
	int printedCount;	//인쇄 매수
	int availableCount;	//인쇄 종이 잔량
	Printer(string model, string manufacturer, int availableCount) {
		this->model = model; this->manufacturer = manufacturer; this->availableCount = availableCount;
	}
	bool print(int pages) {	//pages매의 용지를 사용
		printedCount = pages;
		if (availableCount < printedCount) {
			cout << "용지가 부족하여 프린트 할 수 없습니다." << endl;
			return false;
		}
		else {
			availableCount -= printedCount;
			return true;
		}
	}
};
class InkJetPrinter : virtual public Printer {
public:
	int availableInk;	//잉크 잔량
	InkJetPrinter(string model,string manufacturer, int availableCount, int availableInk) : Printer(model, manufacturer, availableCount) {
		this->availableInk = availableInk;
	}
	void show() { cout << "잉크젯 : " << model << ", " << manufacturer << " ,남은 종이" << availableCount << "남은 잉크" << availableInk << endl; }
	void printInkJet(int pages) {
		if (print(pages)) {
			if (availableInk > pages) {
				availableInk -= pages;
				cout << "프린트하였습니다." << endl;
			}
			else {
				cout << "잉크가 부족하여 프린트 할 수 없습니다." << endl;
			}
		}
	}
};
class LaserPrinter :public Printer {
	int availableToner;
public:
	LaserPrinter(string model, string manufacturer, int availableCount, int availableToner) : Printer(model, manufacturer, availableCount) {
		this->availableToner = availableToner;
	}
	void show() { cout << "잉크젯 : " << model << " ," << manufacturer << " ,남은 종이 " << availableCount << ", 남은 토너 " << availableToner << endl; }
	void printLaser(int pages) {
		if (print(pages)) {
			if (availableToner > pages) {
				availableToner -= pages;
				cout << "프린트하였습니다.\n";
			}
			else {
				cout << "토너가 부족하여 프린트할 수 없습니다\n";
			}
		}
	}
};



int main() {
	int print, pages;
	char con;
	InkJetPrinter *I = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter *L = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);
	
	cout << "현재 작동중인 2대의 프린터는 아래와 같다." << endl;
	I->show();
	L->show();
	cout << endl;
	while (1) {
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> print >> pages;
		if (print == 1) {
			I->printInkJet(pages);
			I->show();
			L->show();
		}
		else if (print == 2) {
			L->printLaser(pages);
			I->show();
			L->show();
		}
		else {
			cout << "잘못된 선택입니다." << endl;
			break;
		}
		cout << "계속 프린트 하시겠습니다??(y/n)";
		cin >> con;
		if (con == 'y') continue;
		else if (con == 'n') break;
	}
}
