//2015112128 배진우
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

bool arr[100][100]; // i부터 j까지의 회문을 저장

bool palindrome(string s, int i, int j) {
	if (i >= j) // i j가 교차하면 true. 
		return true; // 재귀를 다시 역순으로 탈출하며 한 번이라도 팰린드롬이 아니면 false로 바뀌고 전체가 팰린드롬이면 true 리턴

	if (s[i] != s[j]) // i번쨰와 j번째 문자가 다르다면 회문이 아니므로 false
		return arr[i][j] = false;

	if (arr[i][j]) // i부터 j까지가 회문이면 true, 아니면 false
		return arr[i][j];

	return palindrome(s, i + 1, j - 1); // 같다면 i와 j를 각각 한칸씩 이동시켜 순환
}

int main() {
	string filePath = "C://Users//jw969//Desktop//exam_palindrome.txt";
	ifstream openFile(filePath.data());
	if (openFile.is_open()) {
		string line;
		while (getline(openFile, line)) {
			cout << line << endl;
			int length = line.size();
			if (palindrome(line, 0, line.size() - 1)) // 초기 left는 0이고 right는 전체 사이즈-1 이다.
				cout << "--Palindrome!!--" << "\n";
			else cout << "--Not Palindrome!!--" << "\n";
		}
		openFile.close();
	}
}

