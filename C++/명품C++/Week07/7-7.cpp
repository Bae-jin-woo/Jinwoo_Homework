#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Random {
public:
	//항상 다른 랜덤 수를 발생시키기 위한 seed를 설정하는 함수
	static void seed() { srand((unsigned)time(0)); }	//씨드 설정
	static int nextInt(int min = 0, int max = 32767);	//min과 max 사이의 정수 리턴
	static char nextAlphabet();	//랜덤 알파벳 문자 리턴
	static double nextDouble();	//0보다 크거나 같고 1보다 적은 랜덤 실수 리턴
};
int Random::nextInt(int min,int max) { //min과 max 사이의 정수 리턴
	return rand();
}
char Random::nextAlphabet() {
	int type = rand() % 2;
	char c;
	if (type == 0) {
		c = (rand() % 26) + 65;	//알파벳 소문자 난수
		return c;
	}
	else if (type == 1) {
		c = (rand() % 26) + 97;	//알파벳 대문자 난수
		return c;
	}
}
double Random::nextDouble() {
	double d = rand() / (double)RAND_MAX;	//0에서 1사이에 난수
	return d;
}

int main() {
	Random::seed();	//시드 설정
	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextInt() % 100 + 1 << ' ';
	}
	cout << endl;
	cout << "알파벳을 랜덤하게 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextAlphabet() << ' ';
	}
	cout << endl;
	cout << "랜덤한 실수를 10개 출력합니다" << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextDouble()<< ' ';
		if (i == 4)cout << endl;
	}
	cout << endl;
}

