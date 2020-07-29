#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;	//원의 반지름
	string name;	//원의 이름
public:
	void setCircle(string name, int radius) { this->name = name, this->radius = radius; }	//이름과 반지름 설정
	double getArea() { return radius * radius*3.14; }
	string getName() { return name;}
};


class CircleManager {
	Circle *p;	//Circle 배열에 대한 포인터
	int size;	//배열의 크기
public:
	CircleManager(int size);	//size 크기의 배열을 동적 생성, 사용자로부터 입력 완료
	~CircleManager();
	void searchByName();	//사용자로부터 원의 이름을 입력받아 면적 출력
	void searchByArea();	//사용자로부터 면적을 입력받아 면적보다 큰 원의 이름 출력
};

CircleManager::CircleManager(int size) {	//size 크기의 배열을 동적 생성, 사용자로부터 입력 완료
	this->size = size;
	this->p = new Circle[size];	//배열 동적 생성
	string name;
	int radius;
	for (int i = 0; i < size; i++) {
		cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
		cin >> name >> radius;
		p[i].setCircle(name, radius);	//원의 이름과 반지름 입력
	}
}
CircleManager::~CircleManager() {
	delete[] p;	//메모리 반환
};
void CircleManager::searchByName() {	//사용자로부터 원의 이름을 입력받아 면적 출력
	string str;
	cout << "검색하고자 하는 원의 이름>>";
	cin >> str;
	for (int i = 0; i < this->size; i++) {
		if (p[i].getName() == str) {
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << endl;
		}
	}
}
void CircleManager::searchByArea() {	//사용자로부터 면적을 입력받아 면적보다 큰 원의 이름 출력
	int s;
	cout << "최소 면적을 정수로 입력하세요 >> ";
	cin >> s;
	cout << s << "보다 큰 원을 검색합니다." << endl;
	for (int i = 0; i < this->size; i++) {
		if (p[i].getArea() > s) {
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ",";
		}
	}
	cout << endl;
}
int main() {
	int n;
	string str;
	cout << "원의 개수 >> ";
	cin >> n;
	CircleManager circle(n);	//n개의 배열을 동적생성
	circle.searchByName();
	circle.searchByArea();
}
