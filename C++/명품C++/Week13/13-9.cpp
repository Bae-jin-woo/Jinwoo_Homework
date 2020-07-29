#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int n = 1;
	double aver = 0;

	while (1) {
		cout << "정수를 입력하세요(0을 입력하면 종료)>>";
		cin >> n;
		if (n == 0) break;	//0을 입력받으면 종료
		v.push_back(n);
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
			aver += (double)v[i];
		}
		aver /= v.size();
		cout << endl << "평균 = " << aver << endl;
		aver = 0;
	}
}
