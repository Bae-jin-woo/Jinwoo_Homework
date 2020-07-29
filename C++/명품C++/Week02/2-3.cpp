#include <iostream>
using namespace std;
int main()
{
	int num1, num2, result;
	
	cout << "두 수를 입력하라>>";
	cin >> num1 >> num2;	//숫자 입력
	if (num1>=num2)
	{
		result = num1;
	}
	else
	{
		result = num2;
	}	//숫자 크기 비교
	cout << "큰 수 = " << result;	//출력
	return 0;
}
