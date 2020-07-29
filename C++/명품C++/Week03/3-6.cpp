#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class EvenRandom {
	int n;
public:
	EvenRandom();
	int next();
	int nextInRange(int a, int b);
};
EvenRandom::EvenRandom() {
	srand((unsigned)time(0));	//seed설정
}
int EvenRandom::next() {
	n = rand();
	while (n % 2 == 1) n = rand();	//짝수난수 구하기
	return n;
}
int EvenRandom::nextInRange(int a, int b) {
	n = (a + (rand() % (b - a) + 1));	//a부터 b까지의 짝수난수 구하기
	while (n % 2 == 1) n = (a + (rand() % (b - a) + 1));
	return n;
}
int main() {
	EvenRandom r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10개--" << endl;
	for (int i = 0; i < 10; i++) {	//난수 출력
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "10 까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {	//난수 범위 출력
		int n = r.nextInRange(2, 10);
		cout << n << ' ';
	}
	cout << endl;
}
