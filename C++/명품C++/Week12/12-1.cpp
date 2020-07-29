#include <iostream>
#include <string>
using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0;	//src를 다른 단위로 변환한다.
	virtual string getSourceString() = 0;	//src 단위 명칭
	virtual string getDestString() = 0;	//dest 단위 명칭
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다. ";
		cout << getSourceString() << "을 입력하세요>>";
		cin >> src;
		cout << "반환 결과: " << convert(src) << getDestString() << endl;
	}
};

class WonToDollar : public Converter {
protected:
	double convert(double src);
	string getSourceString();
	string getDestString();
public:
	WonToDollar(double ratio) : Converter(ratio) { this->ratio = ratio; }
};

double WonToDollar::convert(double src) {
	return src / ratio;
}

string WonToDollar::getSourceString(){
	return "원";
}

string WonToDollar::getDestString() {
	return "달러";
}

int main() {
	WonToDollar wd(1010);	//1달러에 1010원
	wd.run();
}
