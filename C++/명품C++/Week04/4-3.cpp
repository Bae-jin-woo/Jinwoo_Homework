#include <iostream>
using namespace std;
void swap(double*ptr1, double*ptr2);
int main() {
	double a = 1.3, b = 1.7;
	double *ptr1 = &a, *ptr2 = &b;
	cout << fixed;
	cout.precision(1);
	cout << "바꾸기 전의 a, b의 값 : " << a << " " << b << endl;
	swap(ptr1, ptr2);
	cout << "바꾼 후의 a, b의 값 : " << a << " " << b << endl;
	return 0;
}
void swap(double*ptr1, double*ptr2) {	//포인터 변수를 사용한 값 바꾸기
	double temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
