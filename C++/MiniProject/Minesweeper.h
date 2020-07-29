#ifndef M2015112128_H
#define M2015112128_H
#include "Common.h"
#include "Player.h"
class M2015112128 : public Player
{
	int nextX, nextY;
public:
	M2015112128();
	Point input();
	void checkMineInfo(Point p);
	void checkBoardInfo(Point p, int value);
	bool visited[BOARD_SIZE][BOARD_SIZE] = { false };	//방문처리를 위한 배열
};
#endif