#include <iostream>
#include <string>
using namespace std;
int main()
{
	string string;
	cout << "문자열 입력>>";
	getline(cin, string);	//문자열 입력
	int size = string.length();	//문자열의 길이
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << string[j];	//순차적으로 출력
		}
		cout << endl;
	}
	return 0;
}
