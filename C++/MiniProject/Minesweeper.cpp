#include "Common.h"
#include "Point.h"
#include "M2015112128.h"
M2015112128::M2015112128()
{
}
Point M2015112128::input()
{
	//�������� ��ǥ�� ������ Ž���Ѵ�. ��, �̹� Ž���� ��ǥ�� Ž������ �ʴ´�.	
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
{	//���ڸ� ã���� ��� ���ڰ� �ִ� ��ǥ�� ��ȯ�ǹǷ� �ش� ��ǥ�� �湮ó���Ͽ� �ߺ�Ž���� �����Ѵ�.
	visited[p.getX()][p.getY()] = true;
}	
void M2015112128::checkBoardInfo(Point p, int value)
{	//���ڸ� ã�� ������ ��� ���� ��ǥ�� value�� ��ȯ�ȴ�.
	//����Ʈ�� ������ ���Ӻ��尡 200*200�� ������ ������ 100���̹Ƿ�
	//�������� ũ�⿡ ���ؼ� ������ ������ ���� �����Ƿ� ����Ž���� ������ ��������� value�� 0�� Ȯ����
	//���� ����. �׷��� ������ ���� value�� 0�ΰ��� �湮��ǥ�� 8�� ��� �湮ó���� �Ѵ�.  

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