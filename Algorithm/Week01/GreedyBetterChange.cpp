//2015112128 배진우
#include <iostream>
using namespace std;

int BetterGreedyChange(int M, int c[], int d);

int main() {
	int M = 40;
	int c[5] = { 25,20,10,5,1 };
	int d = 5;
	int result = BetterGreedyChange(M, c, d);
}

int BetterGreedyChange(int M, int c[], int d) {
	int MM = M;
	int dd = d;
	int *cc = new int[dd];
	int* k = new int[dd];
	int sum_of_k = 0;
	for (int i = 0; i < dd; i++)
		cc[i] = c[i];
	for (int i = 0; i < 5; i++) {	//BetterGreedyChange 알고리즘은 동전을 카운트 할 때 마다 
		k[i] = MM / cc[i];		//루프 안에서 M에서 동전의 액수만큼 빼주는 연산을 수행한다.	
		MM = MM - cc[i] * k[i];
	}
	cout << "M = " << MM << ", c = (";
	for (int i = 0; i < dd; i++)
		cout << cc[i] << " ";
	cout << "), d = " << dd << endl;
	cout << "output: ";
	for (int i = 0; i < dd; i++) {
		cout << k[i] << " ";
		sum_of_k += k[i];
	}
	cout << "result =  " << sum_of_k << endl;
	delete[] k;
	delete[] cc;
	return sum_of_k;
}
//M = 40. c = 25 20 10 5 1, d = 5
//output 1 0 1 1 0