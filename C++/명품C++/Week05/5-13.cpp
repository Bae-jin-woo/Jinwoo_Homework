#include <iostream>
#include <string>
using namespace std;
class Histogram{
	string str;
public:
	Histogram(string str) { this->str = str; }	//문자열을 매개변수로 받는 생성자
	void put(string str) { this->str.append(str); }	//매개변수로 입력받은 문자를 기존의 문자열에 추가
	void putc(string str) { this->str.append(str); }	//매개변수로 입력받은 문자를 기존의 문자열에 추가
	void print() { cout << str << endl; }	//문자열 출력
	void alphabet_count();
};
void Histogram::alphabet_count() {
	int count = 0;	//총 알파벳의 수
	int alphabet_count[27] = { NULL };	//
	int alphabet_length = str.length();	//입력받은 문자열의 길이
	for (int i = 0; i < alphabet_length; i++) {	//문자열의 길이만큼 반복
		if (isalpha(str[i])) {	//i번째 문자열의 인덱스가 알파벳이라면
			if (str[i] <= 90) {	//i번째 문자열의 인덱스가 대문자라면
				str[i] = tolower(str[i]);	//알파벳을 소문자로 바꿔준다
			}
			count++;	//전체알파벳 수 카운트
			alphabet_count[str[i] - 97]++;	//알파벳 수 카운트
		}
	}
	cout << endl << "총 알파벳 수 " << count << endl << endl;
	for (int i = 0; i < 27; i++) {	//알파벳 수 출력
		cout << char(i + 97) << " (" << alphabet_count[i] << ")" << " : ";
		for (int j = 0; j < alphabet_count[i]; j++) {	//알파벳 수만큼 *출력
			cout << "*";
		}
		cout << endl;
	}
}
int main() {
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc("-");
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();
	elvisHisto.alphabet_count();
}
