#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Nation {
	string nation;
	string capital;
public:
	Nation(string n, string c) { this->nation = n; this->capital = c; }
	string getNation() { return nation; }
	string getCapital() { return capital; }
	bool operator ==(Nation n){
		if (this->getCapital() == n.getCapital() && this->getNation() == n.getNation())
			return true;
		else return false;
	}
};



int main(){
	vector<Nation> v;
	int n = 0;
	string nation, capital;
	cout << "****나라의 수도 맞추기 게임을 시작합니다. *****" << endl;
	while (1) {
		cout << "정보 입력: 1, 퀴즈: 2, 종료: 3 >>";
		cin >> n;
		if (n == 1) {
			while (1) {
				cout << "현재 " << v.size() << "개의 나라가 입력되어 있습니다." << endl;
				cout << "나라와 수도를 입력하세요(no no이면 입력 끝)" << endl;
				cin >> nation >> capital;
				if (nation == "no" && capital == "no") {	//입력 종료
					break;
				}
				Nation n(nation, capital);
				for (int i = 0; i < v.size(); i++) {
					if (v[i] == n)
						cout << "already exists!!" << endl;
				}
				v.push_back(n);
			}
		}
		else if (n == 2) {	//0에서 벡터 사이즈 만큼의 난수를 만들어 퀴즈 인덱스로 사용
			string answer;
			while (1) {	//퀴즈
				srand((unsigned int)time(0));
				int index = rand() % v.size();
				cout << v[index].getNation() << "의 수도는?";
				cin >> answer;
				if (answer == "exit") break;
				if (answer == v[index].getCapital()) cout << "Correct !!!" << endl;
				else cout << "No !!!" << endl;
			}
		}
		else if (n == 3) {
			cout << "종료합니다..." << endl;
		}
	}
}
