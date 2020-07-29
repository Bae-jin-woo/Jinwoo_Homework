#include <iostream>
#include <string>
using namespace std;
int main()
{
	char name[100];
	char large_name[100] = { NULL };	//가장 긴 이름
	cout << "5명의 이름을 ';'로 구분하여 입력하세요" << endl << ">>";
	for (int i = 1; i <= 5; i++)
	{
		cin.getline(name, 100, ';');	//이름 입력
		cout << i << " : " << name << endl;	
		if (strlen(name)>=strlen(large_name))
		{
			strcpy(large_name, name);	//가장 긴 이름 저장
		}
	}
	cout << "가장 큰 이름은 " << large_name << endl;
	return 0;
}
