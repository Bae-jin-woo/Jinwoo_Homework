#include <iostream>
using namespace std;

void line_up(double *a, double *b, double *c);
void exchange(double *a, double *b);
int main() {
	double max, mid, min;
	cout << "숫자 세 개를 입력하세요 : ";
	cin >> max >> mid >> min;
	line_up(&max, &mid, &min);  // 세 변수의 값을 비교하여 바꿔주는 함수 호출cout << fixed;
	cout << fixed;
	cout.precision(6);
	cout << "큰 수부터 차례로 출력하면 : " << max << " " << mid << " " << min;
}
void exchange(double *a, double *b) {
	double temp = *a;	//값 교환 함수
	*a = *b;
	*b = temp;
}
void line_up(double *a, double *b, double *c) {
	if (*a < *b) exchange(a, b);	//교환 함수를 이용한 정렬
	if (*b < *c) exchange(b, c);
	if (*a < *b) exchange(a, b);
}
