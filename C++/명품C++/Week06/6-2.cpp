#include <iostream>
using namespace std;
double half(double &n) {	//참조에 의한 호출
	n /= 2;
	return n;
}
int main() {
	double n = 20;
	half(n);	//n의 반값을 구해 n을 바꾼다
	cout << n << endl;
}
