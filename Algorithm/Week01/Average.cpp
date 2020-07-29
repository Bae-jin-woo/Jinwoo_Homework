//2015112128 배진우
#pragma warning (disable: 4996)
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string s;
	vector<double> num;
	stringstream stream1;
	double count = 0;
	double is_num;
	cout << "배열을 입력해주세요: ";
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {	//문자열 형식으로 숫자와 공백을 입력받아 
		stream1.str(s);						//공백을 기준으로 숫자 추출
		while (stream1 >> is_num)
			num.push_back(is_num);
	}
	int size = num.size();
	double* avr = new double[size];
	cout << "Avr 출력" << endl;
	for (int i = 0; i < size; i++) {	//count 변수에 숫자를 가산하면서 avr 배열에 각각의 평균 저장
		count += num[i];
		avr[i] = count / (i + 1);
		cout << " Avr[" << i << "]: " << avr[i] << endl;
	}
	delete[] avr;
	return 0;
}
