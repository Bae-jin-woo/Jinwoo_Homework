#include <iostream>
using namespace std;

class Statistics {
	int i = 0;
	int *data = new int[i+1];
	
public:
	Statistics() {
		data[i] = NULL;
	}
	bool operator !() {
		if (data[i] == NULL) return true;
		else return false;
	}
	Statistics& operator<<(int n) {	//temp를 사용해 임시로 값을 저장하고 배열을 확장해 다시 저장
		data[i++] = n; 
		int *temp = new int[i + 1];
		for (int j = 0; j < i; j++)
			temp[j] = data[j];
		data = new int[i + 1];
		for (int j = 0; j < i; j++)
			data[j] = temp[j];
		return *this;
	}
	void operator~() {
		for (int j = 0; j < i; j++) 
			cout << data[j] << " ";
		cout << endl;
	}
	int operator >>(int& avg) {
		int sum=0;
		for (int j = 0; j < i; j++)
			sum += data[j];
		avg = sum / i;
		return avg;
	}
};

int main() {
	Statistics stat;
	if (!stat) cout << "현재 통계 데이터가 없습니다." << endl;
	int x[5];
	cout << "5개의 정수를 입력하라>>";
	for (int i = 0; i < 5; i++) cin >> x[i];

	for (int i = 0; i < 5; i++) stat << x[i];
	stat << 100 << 200;	//100,200을 통계 객체에 삽입한다.
	~stat;	//통계 데이터를 모두 출력한다.

	int avg = 0;
	stat >> avg;	//통계 데이터로부터 평균을 받는다.
	cout << "avg = " << avg << endl;
}
