#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	string str;
	while (str != "exit") {
		cout << "아래의 한 줄을 입력하세요. exit를 입력하면 종료합니다" << endl;
		getline(cin, str);	//문자열 입력
		srand((unsigned)time(0));	//seed 설정
		int n = rand() % str.length();	//0부터 문자열 길이만큼의 난수 생성
		int change = 97 + rand() % (122 - 97);	//a부터 z까지의 아스키 코드 랜덤 생성
		if (str != "exit") {	//exit를 누르면 종료해야 하므로 예외처리
			str[n] = change;
			cout << ">>" << str << endl;
		}
	}
}
