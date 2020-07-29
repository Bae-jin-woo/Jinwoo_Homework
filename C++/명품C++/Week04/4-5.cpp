#include <iostream>
using namespace std;

int main() {
	double *max = new double;	//변수 동적할당
	double *min = new double;
	double *dif = new double;
	cout << "최고기온과 최저기온을 입력하세요 : ";
	cin >> *max >> *min;
	*dif = *max - *min;
	cout << fixed;
	cout.precision(1);
	cout << "일교차는 " << *dif << "도 입니다. " << endl;
	delete max;	//메모리 해제
	delete min;
	delete dif;
}
