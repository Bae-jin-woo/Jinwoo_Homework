#include <iostream>
#include <string>
using namespace std;
class Person {
	string name;
public:
	Person() { name = ""; }	//클래스 배열을 만들때 필요한 기본 생성자
	Person(string name) { this->name = name; }	//문자열을 매개변수로 받는 생성자
	string getName() { return name;}	//이름을 반환
	void setName(string name) { this->name = name; }	//이름을 수정하는 함수
};

class Family {
	Person *p;	//Person 배열 포인터
	int size;	//Person 배열의 크기. 가족 구성원 수
	string name;	//가족의 이름
public:
	Family(string name, int size);	//size 개수만큼 Person 배열 동적 생성
	void show();	//모든 가족 구성원 출력
	~Family() { delete[] p; }	//동적메모리 반환
	void setName(int size, string name) {
		p[size].setName(name);
	}
};
Family::Family(string name, int size) {	//가족의 명수와 이름을 매개변수로 받는 생성자
	this->name = name;	//이름받고
	this->size = size;	//크기받고
	p = new Person[size];	//가족의 크기만큼 Person클래스 배열 동적할당
}
void Family::show(){
	cout << name << "가족은 다음과 같이" << size << "명 입니다." << endl;
	for (int i = 0; i < size; ++i) {
		cout << p[i].getName() << "\t";
	}
	cout << endl;
}
int main() {
	Family *simpson = new Family("Simpson", 3);	//3명으로 구성된 Simpson 가족
	simpson->setName(0, "Mr.Simpson");
	simpson->setName(1, "Mrs.Simpson");
	simpson->setName(2, "Bart.Simpson");
	simpson->show();
	delete simpson;
}

