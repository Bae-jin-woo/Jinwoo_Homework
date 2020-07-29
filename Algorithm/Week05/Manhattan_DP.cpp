//2015112128 ������
#include <iostream>
#include <vector>
using namespace std;

struct map {	//map ����ü
	int right;
	int down;
};

void Manhattan_Distance(map Map[5][5]);

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
	Manhattan_Distance(Map);
}

void Manhattan_Distance(map Map[5][5]) {
	int i, j;
	int result[5][5] = { 0 };
	int row_sum = 0, col_sum = 0;
	for (i = 1; i < 5; i++) {	//DP�� �����ϱ� �� ù��° ��� ù��° ���� weight��ŭ ���� ����
		row_sum += Map[i - 1][0].down;
		col_sum += Map[0][i - 1].right;
		result[i][0] = row_sum;
		result[0][i] = col_sum;
	}
	int right_weight = 0;
	int down_weight = 0;
	for (i = 1; i < 5; i++) {
		for (j = 1; j < 5; j++) {	//dynamic programming������ ���� ���� ã�Ƴ�����.
			right_weight = Map[i][j - 1].right;	//right�� down�� ��� ���� weight���� ���� ���Ͽ�
			down_weight = Map[i - 1][j].down;	//�� ū ���� result�� �����ϴ� ���
			result[i][j] = right_weight + result[i][j - 1] >= down_weight + result[i - 1][j] ?
						right_weight + result[i][j - 1] : down_weight + result[i - 1][j];
		}
	}
	for (i = 0; i < 5; i++) {	//��� ���
		for (j = 0; j < 5; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}