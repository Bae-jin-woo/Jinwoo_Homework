#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class Player {
	string name;
public:
	int play_number[3];	//랜덤 숫자를 입력받을 배열
	Player(){}	
	Player(string name) { this->name = name; }	//문자열을 매개변수로 받는 생성자
	string getName() { return name; }
};
class GamblingGame {
	Player p1, p2;
	int result = 1;	//승부가 나면 0으로 바뀌면서 종료
public:
	GamblingGame(Player p1, Player p2);	//플레이어 2명을 매개변수로 받는 생성자
	void set_result(int n) { this->result = n;}
};
GamblingGame::GamblingGame(Player p1, Player p2) {
	this->p1 = p1, this->p2 = p2;	//매개변수로 받은 플레이어 객체 대입
	while (result != 0) {
		if (result==1){	//첫번쨰 선수 차례
			char c;
			cout << p1.getName() << "<Enter>" << endl;
			cin.get(c);
			if (c == '\n') {	//엔터를 입력받으면
				srand((unsigned)time(0));	//seed 설정
				for (int i = 0; i < 3; i++) {
					p1.play_number[i] = rand() % 3;	//0부터 2사이 난수 생성
					cout << p1.play_number[i] << "\t";	//난수 출력
				}
				if ((p1.play_number[0] == p1.play_number[1]) && (p1.play_number[1] == p1.play_number[2])) {	//세 랜덤 숫자가 같다면
					cout <<"\t"<<p1.getName() << "님 승리!!" << endl;
					 set_result(0);	//게임 종료
				}
				else {	//그렇지 않다면
					cout << "\t아쉽군요!!" << endl;
					set_result(-1);	//두번째 선수 차례로
				}
					
			}
		}
		else if (result == -1) {	//두번째 선수 차례
			char c;
			cout << p2.getName() << "<Enter>" << endl;
			cin.get(c);
			if (c == '\n') {	//엔터를 입력받으면
				srand((unsigned)time(0));	//seed 설정
				for (int i = 0; i < 3; i++) {
					p2.play_number[i] = rand() % 3;	//0부터 2사이 난수 생성
					cout << p2.play_number[i] << "\t";	//난수 출력
				}
				if ((p2.play_number[0] == p2.play_number[1]) && (p2.play_number[1] == p2.play_number[2])) {	//세 랜덤 숫자가 같다면
					cout << "\t" << p2.getName() << "님 승리!!" << endl;
					set_result(0);	//게임 종료
				}
				else {	//그렇지 않다면
					cout << "\t아쉽군요!!" << endl;
					set_result(1);	//첫번째 선수 차례로
				}

			}
		}
	}
}
int main() {	
	string name1, name2;
	cout << "***** 겜블링 게임을 시작합니다*****" << endl;
	cout << "첫번째 선수 이름 >>";	//이름 입력
	cin >> name1;
	cout << "두번쨰 선수 이름>>";
	cin >> name2;
	Player p1(name1), p2(name2);	//플레이어 생성
	GamblingGame(p1, p2);
}

