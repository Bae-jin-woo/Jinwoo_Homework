#include <iostream>
#include <string>
using namespace std;
class Console {	//메뉴를 출력하는 함수, 사용자로부터 메뉴 선택, 비행시간, 사용자 이름, 좌석 번호 등을 입력받는 멤버 함수들을 구현.
public:
	static void start();
	static int menu();
	static int time();
	static int num();
	static string name();
};
void Console::start() {
	cout << "***** 한성항공에 오신것을 환영합니다 *****" << endl;
}
int Console::menu() {
	cout << endl << endl;
	cout << "예약:1, 취소:2, 보기:3, 끝내기:4>> ";
	int n;
	cin >> n;
	return n;
}
int Console::time() {
	cout << "07시:1, 12시:2, 17시:3>> ";
	int t;
	cin >> t;
	return t;
}
int Console::num() {
	cout << "좌석 번호>> ";
	int num;
	cin >> num;
	return num;
}
string Console::name() {
	cout << "이름 입력>> ";
	string name;
	cin >> name;
	return name;
}
class Seat {	//하나의 좌석을 구현하는 클래스, 예약자 이름 저장. 좌석에 대한 예야그 취소, 보기 등 관리
	string seatName;
public:
	Seat() { seatName = "---"; }
	string getName() { return seatName; }
	void setName(string name) { seatName = name; }
};
class Schedule {	//하나의 스케쥴을 구현하는 클래스. 8개의 seat객체 생성. Seat 객체에 예약, 취소, 보기 등 관리
	Seat *seat;
	string time;
public:
	Schedule() { seat = new Seat[8]; }
	~Schedule() { delete[] seat; }
	void setTime(string t) { time = t; }
	void show() {
		cout << time << " :";
		for (int i = 0; i < 8; ++i)
			cout << seat[i].getName() << "\t";
		cout << endl;
	}
	void reservationSeat(int num, string name) {
		seat[num - 1].setName(name);
	}
	void cancleSeat(int num, string name) {
		seat[num - 1].setName("---");
	}
};
class AirlineBook {	//스케줄 객체 3개 생성, 예약시스템 작동
	Schedule *schedule;
public:
	AirlineBook() {
		schedule = new Schedule[3];
		schedule[0].setTime("07시");
		schedule[1].setTime("12시");
		schedule[2].setTime("17시");
	}
	~AirlineBook() { delete[] schedule; }
	void reservation(int t) {
		schedule[t - 1].show();
		int num = Console::num();
		string name = Console::name();
		schedule[t - 1].reservationSeat(num, name);
	}
	void cancle(int t) {
		schedule[t - 1].show();
		int num = Console::num();
		string name = Console::name();
		schedule[t - 1].cancleSeat(num, name);
	}
	void showAll() {
		for (int i = 0; i < 3; ++i)
			schedule[i].show();
	}
};

int main() {
	AirlineBook airlinebook;
	Console::start();
	for (;;) {
		int n = Console::menu();
		if (n == 1) {
			int t = Console::time();
			airlinebook.reservation(t);
		}
		else if (n == 2) {
			int t = Console::time();
			airlinebook.cancle(t);
		}
		else if (n == 3) {
			airlinebook.showAll();
		}
		else if (n == 4) {
			cout << "예약 시스템을 종료합니다." << endl;
			break;
		}
		else {

		}
	}
} 

