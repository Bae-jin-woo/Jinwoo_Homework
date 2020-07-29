#include "P2015112128.h"

P2015112128::P2015112128()
{
}

void P2015112128::gameStart(Point player, int height, int width)
{
	//std::cout << "시작 위치" << player << ' ' << height << ' ' << width << std::endl;
}

Action P2015112128::nextMove()
{
	//우 상 좌 하 순으로 이동
	if(top!=-1)
	p = pop();
	switch (dirCount % 4)
	{
	case 0:
		if (Point(point.getX(), point.getY() + 1) == p) {	//원래 y+1
			push(p);
			dirCount++;
			break;
		}
		push(p);
		return Action::MOVE_RIGHT;
	case 1:
		if (Point(point.getX() - 1 , point.getY()) == p) {	//원래 x-1
			push(p);
			dirCount++;
			break;
		}
		return Action::MOVE_UP;
	case 2:
		push(p);
		return Action::MOVE_LEFT;
	case 3:
		push(p);
		return Action::MOVE_DOWN;
	}
}

void P2015112128::ableToMove(Point point, Point prevPoint)
{
	push(prevPoint);
	dirCount = 0;   //이동을 하면 0으로 초기화
}

void P2015112128::notAbleToMove(Point point)
{
	dirCount++;   //이동을 못했으면 1을 더해서 방향 전환
}