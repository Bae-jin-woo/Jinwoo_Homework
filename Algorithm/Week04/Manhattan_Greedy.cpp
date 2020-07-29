//2015112128 ������
#include <iostream>
#include <vector>
using namespace std;

struct map {
	int right;
	int down;
};

void Manhattan_Tourist_Greedy(map Map[5][5], int& i, int& j,bool& finish);

int main() {
	int i = 0, j = 0;
	bool finish = false;
	map Map[5][5] = {	//Map ����
	{{3, 1}, {2, 0}, {4, 2}, {0, 4}, {0, 3}},
	{{3, 4}, {2, 6}, {4, 5}, {1, 2}, {0, 1}},
	{{0, 4}, {7, 4}, {3, 5}, {4, 2}, {0, 1}},
	{{3, 5}, {3, 6}, {0, 8}, {2, 5}, {0, 3}},
	{{1, 0}, {3, 0}, {2, 0}, {2, 0}, {0, 0}}
	};
	cout << "Greedy �˰����� ����� Manhattan Tourist" << endl;
	while (!finish) {
		Manhattan_Tourist_Greedy(Map, i, j, finish);
	}
	i = 0, j = 0, finish = false;
}

void Manhattan_Tourist_Greedy(map Map[5][5], int& i, int& j, bool& finish) {
	printf("Map[%d][%d]\n", i, j);
	if (Map[i][j].right == Map[i][j].down) {	//���� �����ϸ� ����. weight�� ���� ��Ȳ�� ���� �����ۿ� �����Ƿ� ���� ����
		finish = true;	
		printf("Finish!!\n");
	}
	else if (Map[i][j].right > Map[i][j].down) {	//���������� �̵�
		j += 1;
	}
	else {	//�Ʒ����� �̵�
		i += 1;
	}
}

void Manhattan_Tourist_Brute_Force(map Map[5][5], int& i, int& j, bool& finish) {

}
