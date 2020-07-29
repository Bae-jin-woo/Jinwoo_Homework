//2015112128 ������
#include <iostream>
using namespace std;

int BruteForceChange(int M, int c[], int d);
int BetterGreedyChange(int M, int c[], int d);

int main() {
	int M = 0;
	int* c;
	int d = 0;
	cout << "Coin�� ���� �Է�: ";
	cin >> d;
	c = new int[d];
	cout << "Coin �Է�: ";
	for (int i = 0; i < d; i++) {
		cin >> c[i];
	}
	cout << "����� �ٸ� ���" << endl;
	for (M = 1; M <= 100; M++) {	//�� �Լ��� ����� ���ؼ� ���
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
	for (int i = 0; i < 5; i++) {	//BetterGreedyChange �˰����� ������ ī��Ʈ �� �� ���� 
		k[i] = MM / cc[i];		//���� �ȿ��� M���� ������ �׼���ŭ ���ִ� ������ �����Ѵ�.	
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
	int smallest_number_of_coins = INT_MAX;	//���Ѵ�� ����
	int sum_of_k = 0;
	int value_of_coins = 0;
	int num_of_coins = 0;
	int array[5];
	for (int i = 0; i < dd; i++)
		cc[i] = c[i];

	//coin�� ������ŭ ����
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
						value_of_coins = 0;   //��� �����ϱ� ���� �ʱ�ȭ�Ѵ�.
						num_of_coins = 0;   //��� �����ϱ� ���� �ʱ�ȭ�Ѵ�.
						for (int i = 0; i < 5; i++)
							value_of_coins += cc[i] * array[i];
						//array[i]���� �ش� coins[i]�� ���� ���Ͽ� coin�� ���� money���� ���� �� ����Ѵ�.
						if (value_of_coins == MM)
						{
							for (int i = 0; i < 5; i++)
								num_of_coins += array[i];
							if (num_of_coins < smallest_number_of_coins)   //���Ǵ� coin�� ������ ���� ������ Ȯ���Ѵ�.
							{											//���� �۴ٸ� ����
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