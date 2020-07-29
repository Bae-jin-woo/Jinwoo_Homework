#include <iostream>
#include <string>
using namespace std;

class Printer {
	string model;	//모델명
	string manufacturer;	//제조사
	int printedCount;	//인쇄매수
	int availableCount;	//인쇄 종이 잔량
protected:
	virtual void print(int pages) = 0;	//pages만큼 프린트
	virtual void show() = 0;	//현재 프린트의 모델, 제조사, 인쇄 매수, 인쇄 종이 잔량을 출력
public:
	Printer(string m, string ma, int a) { this->model = m, this->manufacturer = ma, this->availableCount = a; }
	string getModel() { return model; }
	string getManufacturer() { return manufacturer; }
	int getPrintedCounted() { return printedCount; }
	void setPrintedCounted(int n) { printedCount = n; }
	int getAvailableCount() { return availableCount; }
	void setAvailableCount(int n) { availableCount -= n; }
};

class InkJetPrinter : public Printer {
	int availableInk;	//잉크 잔량
public:
	InkJetPrinter(string m, string ma, int a, int ai) : Printer(m, ma, a) { this->availableInk = ai; }
	int getAvailableInk() { return availableInk; }
	void setAvailableInk(int n) { availableInk -= n; }
	void print(int pages);
	void show();
};

void InkJetPrinter::print(int pages) {
	if (pages > getAvailableCount()) {	//인쇄종이 잔량보다 인쇄해야할 페이지가 많다면
		cout << "용지가 부족하여 프린트 할 수 없습니다" << endl;
	}
	else {
		setPrintedCounted(pages);
		setAvailableCount(pages);
		setAvailableInk(pages);
		cout << "프린트하였습니다." << endl;
	}
}

void InkJetPrinter::show() {
	cout << getModel() << " ," << getManufacturer() << " ,남은 종이 " << getAvailableCount() << " ,남은 잉크" << getAvailableInk() << endl;
}

class LaserPrinter : public Printer {
	int availableToner;	//토너 잔량
public:
	LaserPrinter(string m, string ma,  int a, int at) : Printer(m, ma, a) { this->availableToner = at; }
	int getAvailableToner() { return availableToner; }
	void setAvailableToner(int n) { availableToner -= n; }
	void print(int pages);
	void show();
};

void LaserPrinter::print(int pages) {
	if (pages > getAvailableCount()) {	//인쇄종이 잔량보다 인쇄해야할 페이지가 많다면
		cout << "용지가 부족하여 프린트 할 수 없습니다" << endl;
	}
	else {
		setPrintedCounted(pages);
		setAvailableCount(pages);
		setAvailableToner(pages);
		cout << "프린트하였습니다." << endl;
	}
}

void LaserPrinter::show() {
	cout << getModel() << " ," << getManufacturer() << " ,남은 종이 " << getAvailableCount() << " ,남은 토너" << getAvailableToner() << endl;
}

int main() {
	char type = 'y';
	int print, pages;
	InkJetPrinter *Ink = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter *La = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);

	cout << "현재 작동중인 2대의 프린터는 아래와 같다" << endl;
	cout << "잉크젯 : ";
	Ink->show();
	cout << "레이저 : ";
	La->show();

	cout << endl << endl;
	while (type != 'n') {
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> print >> pages;
		if (print == 1) {
			Ink->print(pages);
			Ink->show();
			La->show();
		}
		else if (print == 2) {
			La->print(pages);
			Ink->show();
			La->show();
		}
		else continue;
		cout << "계속 프린트 하시겠습니까(y/n)";
		cin >> type;
		cout << endl;
	}
}
