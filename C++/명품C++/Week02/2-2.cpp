#include <iostream>
using namespace std;
int main()
{
	int a, b;
	for (a = 1; a <= 9; a++)
	{
		for (b = 1; b <= 9; b++)
		{
			cout << b << "*" << a << "=" << b * a << "\t";	//구구단 출력
		}
		cout << endl;	//개행
	}
	return 0;
}
