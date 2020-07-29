//2015112128 배진우
#include <iostream>
#include <string>
using namespace std;

int gcd(int num1,int num2);

int main() {
	int num1=0, num2=0;
	cout << "숫자 2개 입력>>";
	cin >> num1 >> num2;
	cout << gcd(num1, num2) << endl;
}
int gcd(int num1, int num2) {	//두 개의 수중에서 작은수를 구하여 1부터 작은 수까지 루프를 돌며 나누어 떨어지는
	int min = num1 <= num2 ? num1 : num2;	//가장 큰 수를 찾아 구한다.
	int result = 0;
	for (int i = 1; i <= min; i++) {
		if (num1 % i == 0 && num2 % i == 0)
			result = i;
	}
	return result;
}