#include <iostream>
using namespace std;
int main()
{
	int k, n = 0;
	int sum = 0;
	cout << "끝 수를 입력하세요>>";
	cin >> n;	//숫자 입력
	for (k = 1; k <= n; k++)
	{
		sum += k;	//숫자 더하기
	}
	cout << "1에서" << n << "까지의 합은" << sum << "입니다." << endl;
	return 0;
}
