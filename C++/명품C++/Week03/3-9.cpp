//클래스 선언부
#ifndef OVAL_H
#define OVAL_H
class Oval {
	int width, height;
public:
	Oval();
	Oval(int w, int h);
	~Oval();
	int getWidth();
	int getHeight();
	void Set(int w, int h);
	void show();
};
#endif	//클래스 구현부
#include <iostream>
using namespace std;

Oval::Oval() : Oval(1, 1) {};	//매개변수 없는 생성자
Oval::Oval(int w, int h) {
	width = w, height = h;	//매개변수 생성자
}
Oval::~Oval() {	//소멸자
	cout << "Oval 소멸 : width = " << width << ", height = " << height << endl;
}
int Oval::getWidth() { return width; }	//폭
int Oval::getHeight() { return height; }	//높이
void Oval::Set(int w, int h) { width = w, height = h; }
void Oval::show() {	//출력
	cout << "width = " << width << ", height = " << height << endl;
}
