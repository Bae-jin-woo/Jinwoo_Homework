//Tower.cpp 함수구현부
#include <iostream>
#include "Tower.h"

Tower::Tower(int h) {
	height = h;
}
Tower::Tower() :Tower(1) {}	//위임 생성자를 이용한 기본 생성자 선언

int Tower::getHeight() {
	return height;
}
