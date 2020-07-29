#include <iostream>
#include <string>
using namespace std;
int main()
{
	string name;
	string address;	//스트링 클래스를 이용한 문자열 선언
	int age;
	cout << "이름은?";
	getline(cin, name);
	cout << "주소는?";
	getline(cin, address);
	cout << "나이는?";	
	cin >> age;
	cout << name << "," << address << "," << age << "세" << endl;	//출력
	return 0;
}
