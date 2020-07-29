#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	map<string, int> dic;
	int type;
	int score;
	string name;
	cout << "**** 점수관리 프로그램 HIGH SCORE을 시작합니다 ******" << endl;
	while (1) {
		cout << "입력:1, 조회:2, 종료:3 >>";
		cin >> type;
		if (type == 1) {
			cout << "이름과 점수 >>";
			cin >> name >> score;
			dic.insert(make_pair(name, score));
		}
		else if (type == 2) {
			cout << "이름 >>";
			cin >> name;
			cout << name << "의 점수는 " << dic[name] << endl;
		}
		else if (type == 3) {
			cout << "프로그램을 종료합니다 ..." << endl;
			break;
		}
	}
}
