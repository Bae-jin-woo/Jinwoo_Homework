#include <iostream>
#include <string>
using namespace std;
int main()
{
	char string[20];
	while (1)
	{
		cout << "종료하고싶으면 yes를 입력하세요>>";
		cin.getline(string, 20, '\n');	//공백을 포함하는 문자열 입력
		if (strcmp(string, "yes") == 0)
		{
			cout << "종료합니다...";
			break;	//yes를 입력하면 종료
		}
	}
	return 0;
}
