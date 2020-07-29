#include <iostream>
#include <string>
using namespace std;
int main()
{
	char string[100];
	int count = 0;
	cout << "문자들을 입력하라(100개 미만)." << endl;
	cin.getline(string, 100, '\n');	//띄어쓰기가 가능한 문자열 입력
	for (int i = 0; i < 100; i++)
	{
		if (string[i]=='x')
		{
			count++;	//x를 찾으면 카운트
		}
	}
	cout << "x의 개수는 " << count;	//출력
	return 0;
}
