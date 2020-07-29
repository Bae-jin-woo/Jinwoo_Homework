#include <iostream>
using namespace std;

int add(int a[], int n, int b[] = NULL) {	//디폴트 매개변수를 가진 함수
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if(b != NULL)	//b가 디폴트 생성자가 아닐 경우
		sum += b[i];
	}
	return sum;
}
int main() {
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int c = add(a, 5);	//배열 a의 정수를 모두 더한 값 리턴
	int d = add(a, 5, b);	//배열 a와 b의 정수를 모두 더한 값 리턴
	cout << c << endl;
	cout << d << endl;
}
