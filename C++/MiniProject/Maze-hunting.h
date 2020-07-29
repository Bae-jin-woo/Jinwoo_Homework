#pragma once
#include "Player.h"

class P2015112128 : public Player
{
public:
	P2015112128();
	void gameStart(Point player, int height, int width);
	Action nextMove();
	void ableToMove(Point point, Point prevPoint);
	void notAbleToMove(Point point);
	int dirCount = 0;   //움직일방향
	Point stack[100000];   //스택
	int top = -1;   //스택 인덱스
	Point p;   //스택의 반환값을 저장할 좌표변수
	void push(Point p) { stack[++top] = p; }   //스택 삽입함수
	Point pop() { return stack[top--]; }   //스택 삭제함수
private:
	Point point;
};