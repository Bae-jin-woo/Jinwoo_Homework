//2015112128 배진우
#include <iostream>
using namespace std;

int BruteForceChange(int M, int c[], int d);
int BetterGreedyChange(int M, int c[], int d);

int main() {
	int M = 0;
	int* c;
	int d = 0;
	cout << "Coin의 갯수 입력: ";
	cin >> d;
	c = new int[d];
	cout << "Coin 입력: ";
	for (int i = 0; i < d; i++) {
		cin >> c[i];
	}
	cout << "결과가 다를 경우" << endl;
	for (M = 1; M <= 100; M++) {	//두 함수의 결과를 비교해서 출력
		if (BetterGreedyChange(M, c, d) != BruteForceChange(M, c, d)) {
			cout << M << " ";
		}
	}
}

int BetterGreedyChange(int M, int c[], int d) {
	int MM = M;
	int dd = d;
	int* cc = new int[dd];
	int* k = new int[dd];
	int sum_of_k = 0;
	for (int i = 0; i < dd; i++)
		cc[i] = c[i];
	for (int i = 0; i < 5; i++) {	//BetterGreedyChange 알고리즘은 동전을 카운트 할 때 마다 
		k[i] = MM / cc[i];		//루프 안에서 M에서 동전의 액수만큼 빼주는 연산을 수행한다.	
		MM = MM - cc[i] * k[i];
	}
	//cout << "M = " << MM << ", c = (";
	//for (int i = 0; i < dd; i++)
	//	cout << cc[i] << " ";
	//cout << "), d = " << dd << endl;
	//cout << "BetterGreedyChange output: ";
	for (int i = 0; i < dd; i++) {
		//cout << k[i] << " ";
		sum_of_k += k[i];
	}
	//cout << "result =  " << sum_of_k << endl;
	delete[] k;
	delete[] cc;
	return sum_of_k;
}

int BruteForceChange(int M, int c[], int d) {
	int MM = M;
	int dd = d;
	int* cc = new int[dd];	//initial
	int* k = new int[dd];
	int smallest_number_of_coins = INT_MAX;	//무한대로 설정
	int sum_of_k = 0;
	int value_of_coins = 0;
	int num_of_coins = 0;
	int array[5];
	for (int i = 0; i < dd; i++)
		cc[i] = c[i];

	//coin의 갯수만큼 루프
	for (array[0] = 0; array[0] <= (MM / cc[0]); array[0]++)
	{
		for (array[1] = 0; array[1] <= (MM / cc[1]); array[1]++)
		{
			for (array[2] = 0; array[2] <= (MM / cc[2]); array[2]++)
			{
				for (array[3] = 0; array[3] <= (MM / cc[3]); array[3]++)
				{
					for (array[4] = 0; array[4] < (MM / cc[4]); array[4]++)
					{
						value_of_coins = 0;   //계속 저장하기 위해 초기화한다.
						num_of_coins = 0;   //계속 저장하기 위해 초기화한다.
						for (int i = 0; i < 5; i++)
							value_of_coins += cc[i] * array[i];
						//array[i]값과 해당 coins[i]의 값을 곱하여 coin의 값을 money값과 비교할 때 사용한다.
						if (value_of_coins == MM)
						{
							for (int i = 0; i < 5; i++)
								num_of_coins += array[i];
							if (num_of_coins < smallest_number_of_coins)   //사용되는 coin의 갯수가 가장 작은지 확인한다.
							{											//가장 작다면 저장
								smallest_number_of_coins = num_of_coins;
								for (int i = 0; i < 5; i++)
									k[i] = array[i];
							}
						}
					}
				}
			}
		}
	}
	//cout << "M = " << MM << ", c = (";
	//for (int i = 0; i < dd; i++)
	//	cout << cc[i] << " ";
	//cout << "), d = " << dd << endl;
	//cout << "BruteForceChange output: ";
	for (int i = 0; i < dd; i++) {
		//cout << k[i] << " ";
		sum_of_k += k[i];
	}
	//cout << "result = " << sum_of_k << endl;
	//cout << endl;
	return sum_of_k;
	delete[] k;
	delete[] cc;

}