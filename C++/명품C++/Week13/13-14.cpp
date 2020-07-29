#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int type;
	string password;
	string name;
	map<string, string> passwordManager;
	cout << "*****암호 관리 프로그램 WHO를 시작합니다 *****" << endl;
	while (1) {
		cout << "삽입:1, 검사:2, 종료:3 >>";
		cin >> type;
		if (type == 1) {
			cout << "이름 암호 >>";
			cin >> name >> password;
			passwordManager.insert(make_pair(name, password));
		}
		else if (type == 2) {
			cout << "이름? ";
			cin >> name;
			while (1) {
				cout << "암호? ";
				cin >> password;
				if (passwordManager[name] == password) {
					cout << "통과!!" << endl;
					break;
				}
				cout << "실패~~" << endl;
			}
		}
		else if (type == 3) {
			cout << "프로그램을 종료합니다 ..." << endl;
			break;
		}
	}
}
