#include <iostream>
#include <string>
using namespace std;
int main()
{
	string password;
	string password2;
	cout << "새 암호를 입력하세요>>";
	getline(cin, password);	//첫 번째 문자열 입력
	cout << "새 암호를 다시 한 번 입력하세요>>";
	getline(cin, password2);	//두 번째 문자열 입력
	
	if (password == password2)	//문자열 비교
	{
		cout << "같습니다." << endl;
	}
	else
	{
		cout << "같지 않습니다." << endl;
	}	//결과 출력
	return 0;
}
