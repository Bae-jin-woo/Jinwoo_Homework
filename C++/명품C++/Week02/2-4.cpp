#include <iostream>
using namespace std;
int main()
{
	double num[5];
	double Max_num = num[0];

	cout << "5개의 실수를 입력하라>>";
	cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4];	//실수 입력
	
	for (int i = 0; i <= 4; i++)
	{
		if (Max_num <= num[i])
		{
			Max_num = num[i];
		}
	}	//실수 크기 비교
	cout << "제일 큰 수 = " << Max_num;	//출력
	return 0;
}
