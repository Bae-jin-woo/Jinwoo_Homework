#include <iostream>
#include <string>
using namespace std;

class Board {
public:
	static int count;
	static string *str;	//게시글을 저장하기 위한 문자열배열
	static void print();
	static void add(string s);
};
void Board::add(string s) {
	str[count++] = s;	//전역변수를 카운트하면서 문자를 문자열 배열에 저장
}
void Board::print() {
	cout << "*****게시판입니다.********" << endl;
	for (int i = 0; i <count; i++) {
		cout << i << ": " << str[i] << endl;
	}
}
string *Board::str = new string[10];	//static 멤버변수 초기화
int Board::count = 0;	

int main() {
	Board::add("중간고사는 감독 없는 자율 시험입니다.");
	Board::add("코딩 라운지 많이 이용해 주세요");
	Board::print();
	Board::add("진소린 학생이 경진대회 입상하였습니다. 축하해주세요");
	Board::print();
	delete[] Board::str;
}

