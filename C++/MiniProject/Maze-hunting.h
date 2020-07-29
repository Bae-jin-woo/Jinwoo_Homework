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
	int dirCount = 0;   //�����Ϲ���
	Point stack[100000];   //����
	int top = -1;   //���� �ε���
	Point p;   //������ ��ȯ���� ������ ��ǥ����
	void push(Point p) { stack[++top] = p; }   //���� �����Լ�
	Point pop() { return stack[top--]; }   //���� �����Լ�
private:
	Point point;
};