#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cout << "아래의 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl << ">>";
	while (str != "exit") {
		getline(cin, str);	//문자열 입력
		if (str != "exit") {	//exit예외처리
			for (int i = str.length() - 1; i >= 0; i--) {
				cout << str[i];	//역순으로 출력
			}
		}
		cout<<endl;
	}
#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cout << "아래의 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl << ">>";
	while (str != "exit") {
		getline(cin, str);	//문자열 입력
		if (str != "exit") {	//exit예외처리
			for (int i = str.length() - 1; i >= 0; i--) {
				cout << str[i];	//역순으로 출력
			}
		}
		cout<<endl;
	}
}
