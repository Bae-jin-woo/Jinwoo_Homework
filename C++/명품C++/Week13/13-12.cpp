#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Word {
	string Eword;
	string Kword;
public:
	Word(string e, string k) { this->Eword = e; this->Kword = k; }
	string getEword() { return Eword; }
	string getKword() { return Kword; }
};

int main() {
	vector<Word> v;
	string bogi[4];
	string answer;
	int number[4];
	int type;
	string kword;
	string eword;
	srand((unsigned)time(0));

	cout << "***** 영어 어휘 테스트를 시작합니다. *****" << endl;
	v.push_back(Word("human", "인간"));
	v.push_back(Word("society", "사회"));
	v.push_back(Word("emotion", "감정"));
	v.push_back(Word("painting", "그림"));
	v.push_back(Word("dall", "인형"));
	v.push_back(Word("trade", "거래"));
	v.push_back(Word("honey", "애인"));
	v.push_back(Word("stock", "주식"));

	while (1) {
		cout << "어휘 삽입: 1, 어휘 테스트 : 2, 프로그램 종료: 그외키 >>";
		cin >> type;
		if (type == 1) {
			while (1) {
				cout << "영어 >>";
				cin >> eword;
				if (eword == "exit") break;	//exit을 입력하면 입력 끝
				cout << "한글 >>";
				cin >> kword;
				v.push_back(Word(eword,kword));
			}
		}
		else if (type == 2) {
			cout << "영어 어휘 테스트를 시작합니다. 1~4 외 다른 입력 시 종료" << endl;
			
			while (1) {
				srand((unsigned)time(0));
				int n = rand() % v.size();	//0 ~ 벡터 인덱스 사이의 난수 생성
				bogi[0] = v[n].getKword();
				answer = bogi[0];
				cout << v[n].getEword() << "?" << endl;
				
				while (1) {
					for (int i = 1; i < 4; i++) {
						n = rand() % v.size();
						bogi[i] = v[n].getKword();
					}
					if (bogi[0] != bogi[1] && bogi[0] != bogi[2] && bogi[0] != bogi[3] && 
						bogi[1] != bogi[2] && bogi[1] != bogi[3] && bogi[2] != bogi[3]) {
						break;
					}
				}
				
				
				while (1) {	//보기 순서 섞기
					for (int i = 0; i < 4; i++) {
						number[i] = rand() % 4;
					}
					if (number[0] != number[1] && number[0] != number[2] && number[0] != number[3] &&
						number[1] != number[2] && number[1] != number[3] && number[2] != number[3])
						break;
				}
				
				int result;
				for (int i = 1; i < 5; i++)
					cout << "(" << i << ") " << bogi[number[i - 1]] << " ";
				cout << ":>";
				cin >> result;

				if (result != 1 && result != 2 && result != 3 && result != 4)	//입력한 숫자가 1,2,3,4가 아니면 종료
					break;
				else if (answer == bogi[number[result - 1]])
					cout << "Excellent !!" << endl;
				else if (result == 1 || result == 2 || result == 3 || result == 4)
					cout << "No. !!" << endl;
			}
		}
		else {
			cout << "프로그램을 종료합니다..." << endl;
			break;
		}
	}
}
