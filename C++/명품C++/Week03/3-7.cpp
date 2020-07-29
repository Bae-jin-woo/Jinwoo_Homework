#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class SelectableRandom {
	string str;
public:
	SelectableRandom(string s);
	int next();
	int nextInRange(int a, int b);
	string getstr() { return str; }	//private 변수인 s를 호출
};
SelectableRandom::SelectableRandom(string s) {
	str = s;
	srand((unsigned)time(0));	//seed설정
}
int SelectableRandom::next() {
	int n = rand();
	if(str == "짝수")
		while (n % 2 == 1) n = rand();	//짝수난수 구하기
	else if(str == "홀수")
		while (n % 2 == 0) n = rand();	//홀수난수 구하기	
	return n;
}
int SelectableRandom::nextInRange(int a, int b) {
	int n = (a + (rand() % (b - a) + 1));
	if(str=="짝수")	//a부터 b까지의 짝수난수 구하기
		while (n % 2 == 1) n = (a + (rand() % (b - a) + 1));
	else if(str=="홀수")	//a부터 b까지의 홀수난수 구하기
		while (n % 2 == 0) n = (a + (rand() % (b - a) + 1));
	return n;
}
int main() {
	SelectableRandom r("홀수");
	SelectableRandom rr("짝수");
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10개--" << endl;
	for (int i = 0; i < 10; i++) {	//난수 출력
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "10 까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {	//난수 범위 출력
		int n = rr.nextInRange(2, 10);
		cout << n << ' ';
	}
	cout << endl;
}
