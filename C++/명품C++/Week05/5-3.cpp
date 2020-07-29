#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	int count = 0;
	cout << "문자열 입력>>";
	getline(cin, str);
	int i = 0;
	while(i!=str.length()) {	//str의 길이만큼 반복
		int j = str.find('a', i);	//문자열에 a가 있다면 그 인덱스 반환
		if (j < 0) { i++; }	//a가 없다면 다음 인덱스로 
		else{	//i번째 인덱스에 a가 있다면 
			count++;	//카운트하고
			i = j + 1;	//그 다음 인덱스부터 다시 반복
		}		
	}
	cout << "문자 a는 " << count << "개 있습니다." << endl;
}
