//Tower.h 함수선언부
#ifndef TOWER_H
#define TOWER_H
class Tower {	//타워 클래스 선언
	int height;
public:
	Tower();	//기본 생성자
	Tower(int h);	//변수가 하나인 생성자
	int getHeight();	//높이를 반환하는 함수
};
#endif
