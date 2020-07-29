#include "Common.h"
#include "Point.h"
#include "M2015112128.h"
M2015112128::M2015112128()
{
}
Point M2015112128::input()
{
	//랜덤으로 좌표를 생성해 탐색한다. 단, 이미 탐색한 좌표는 탐색하지 않는다.	
	while (1) {
		Point p(rand() % BOARD_SIZE, rand() % BOARD_SIZE);
		if (visited[p.getX()][p.getY()] == true) continue;
		else {
			visited[p.getX()][p.getY()] = true;
			return p;
			break;
		}
	}
}

void M2015112128::checkMineInfo(Point p)
{	//지뢰를 찾았을 경우 지뢰가 있는 좌표가 반환되므로 해당 좌표를 방문처리하여 중복탐색을 방지한다.
	visited[p.getX()][p.getY()] = true;
}	
void M2015112128::checkBoardInfo(Point p, int value)
{	//지뢰를 찾지 못했을 경우 현재 좌표와 value가 반환된다.
	//디폴트로 설정된 게임보드가 200*200에 지뢰의 갯수가 100개이므로
	//게임판의 크기에 비해서 지뢰의 갯수가 아주 적으므로 임의탐색을 했을때 상대적으로 value가 0일 확률이
	//아주 높다. 그렇기 때문에 먼저 value가 0인경우는 방문좌표의 8방 모두 방문처리를 한다.  

	visited[p.getX()][p.getY()] = true;
	
	if (value == 0) {
		int x = p.getX() - 1;
		int y = p.getY() - 1;
		if ((((x < 0) || (x > BOARD_SIZE - 1)) || ((y < 0) || (y > BOARD_SIZE - 1))) == false)
		{
			visited[x][y] = true;
		}
		x = p.getX() - 1; y = p.getY();
		if ((((x < 0) || (x > BOARD_SIZE - 1)) || ((y < 0) || (y > BOARD_SIZE - 1))) == false)
		{
			visited[x][y] = true;
		}
		x = p.getX() - 1; y = p.getY() + 1;
		if ((((x < 0) || (x > BOARD_SIZE - 1)) || ((y < 0) || (y > BOARD_SIZE - 1))) == false)
		{
			visited[x][y] = true;
		}
		x = p.getX(); y = p.getY() - 1;
		if ((((x < 0) || (x > BOARD_SIZE - 1)) || ((y < 0) || (y > BOARD_SIZE - 1))) == false)
		{
			visited[x][y] = true;
		}
		x = p.getX(); y = p.getY() + 1;
		if ((((x < 0) || (x > BOARD_SIZE - 1)) || ((y < 0) || (y > BOARD_SIZE - 1))) == false)
		{
			visited[x][y] = true;
		}
		x = p.getX() + 1; y = p.getY() - 1;
		if ((((x < 0) || (x > BOARD_SIZE - 1)) || ((y < 0) || (y > BOARD_SIZE - 1))) == false)
		{
			visited[x][y] = true;
		}
		x = p.getX() + 1; y = p.getY();
		if ((((x < 0) || (x > BOARD_SIZE - 1)) || ((y < 0) || (y > BOARD_SIZE - 1))) == false)
		{
			visited[x][y] = true;
		}
		x = p.getX() + 1; y = p.getY() + 1;
		if ((((x < 0) || (x > BOARD_SIZE - 1)) || ((y < 0) || (y > BOARD_SIZE - 1))) == false)
		{
			visited[x][y] = true;
		}
	}
}