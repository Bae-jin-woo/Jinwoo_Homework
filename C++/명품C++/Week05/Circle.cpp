#include "Circle.h"
void Circle::setRadius(int radius) {	//반지름 설정
	this->radius = radius;	
}
double Circle::getArea() {//넓이 반환
	return radius * radius*3.14;	
}
