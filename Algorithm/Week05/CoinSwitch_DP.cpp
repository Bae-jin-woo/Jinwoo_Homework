//2015112128 ������
#include <iostream>
#include <algorithm>
using namespace std;

class CoinChange {
private:
	int n = 0;
	int* R = new int[12];	//�ε����� ���� 1�� �� ����
	int c[3] = { 1,4,7 };
public:
	void SetArray(int num);
	void Solution();
	void Show();
};

int main() {
	CoinChange c;
	for (int i = 1; i <= 11; i++) {
		c.SetArray(i);
		c.Solution();
		c.Show();
	}
}

void CoinChange::SetArray(int num) {
	n = num;
	for (int i = 0; i < 12; i++) {
		R[i] = INT_MAX;
	}
}

void CoinChange::Solution() {
	R[0] = 0;
	R[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j >= 0; j--) {
			if (i >= c[j]) {
				R[i] = min(R[i], R[i - c[j]] + 1);
			}
		}
	}
}

void CoinChange::Show() {
	cout << n<<" "<< R[n] << endl;
}