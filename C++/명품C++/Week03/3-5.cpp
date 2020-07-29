#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Random {
public:
	Random();
	int next();
	int nextInRange(int a, int b);
};
Random::Random() {
	srand((unsigned)time(0));	//seed설정
}
int Random::next() {
	return rand();
}
int Random::nextInRange(int a, int b) {
	return a + (rand() % (b - a) + 1);	//a부터 b까지의 난수 구하기
}

int main() {
	Random r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10개--" << endl;
	for (int i = 0; i < 10; i++) {	//난수 출력
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {	//난수 범위 출력
		int n = r.nextInRange(2, 4);
		cout << n << ' ';
	}
	cout << endl;
}
