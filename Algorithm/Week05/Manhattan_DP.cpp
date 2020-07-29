//2015112128 배진우
#include <iostream>
#include <vector>
using namespace std;

struct map {	//map 구조체
	int right;
	int down;
};

void Manhattan_Distance(map Map[5][5]);

int main() {
	int i = 0, j = 0;
	bool finish = false;
	map Map[5][5] = {	//Map 세팅
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
	for (i = 1; i < 5; i++) {	//DP를 수행하기 전 첫번째 행과 첫번째 열은 weight만큼 더해 나감
		row_sum += Map[i - 1][0].down;
		col_sum += Map[0][i - 1].right;
		result[i][0] = row_sum;
		result[0][i] = col_sum;
	}
	int right_weight = 0;
	int down_weight = 0;
	for (i = 1; i < 5; i++) {
		for (j = 1; j < 5; j++) {	//dynamic programming과정을 통해 값을 찾아나간다.
			right_weight = Map[i][j - 1].right;	//right와 down의 노드 값과 weight값의 합을 비교하여
			down_weight = Map[i - 1][j].down;	//더 큰 값을 result에 저장하는 방식
			result[i][j] = right_weight + result[i][j - 1] >= down_weight + result[i - 1][j] ?
						right_weight + result[i][j - 1] : down_weight + result[i - 1][j];
		}
	}
	for (i = 0; i < 5; i++) {	//결과 출력
		for (j = 0; j < 5; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}