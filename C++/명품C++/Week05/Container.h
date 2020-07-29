//Container.h
#ifndef CONTAINER_H	//중복선언 방지를 위한 전처리
#define CONTAINER_H 
class Container {
	int size;
public:
	Container() { size = 10; }
	void fill();	//최대량(10)으로 채우기
	void consume();	//1만큼 소모하기
	int getSize();	//현재 크기 리턴
};
#endif
