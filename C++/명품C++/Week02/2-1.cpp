#include <iostream>
using namespace std;
int main()
{
	int num;
	for (num = 1; num <= 100; num++)
	{
		cout << num << '\t';	//각 정수는 탭으로 분리
		if (num%10 == 0)
		{
			cout << '\n';	//10단위로 개행
		}
	}
	return 0;
}
