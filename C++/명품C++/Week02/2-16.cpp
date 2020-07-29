#include <iostream>
#include <string>
using namespace std;
int main()
{
	char text[10000];
	int alphabet_count[26] = { NULL };
	int count = 0;
	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << endl;
	cout << "텍스트의 끝은 ; 입니다. 10000개까지 가능합니다." << endl;
	cin.getline(text, 10000, ';');	//공백을 포함한 10000개의 문자 입력
	int text_size = strlen(text);	//문자 길이
	for (int i = 0; i < text_size; i++)
	{
		if (isalpha(text[i]))	//i번째 문자가 알파벳이라면
		{
			if (text[i] <= 90)	//i번째 문자가 대문자라면
			{
				text[i] = tolower(text[i]);	//소문자로 변환
			}
			count++;	//알파벳 전체수 증가
			alphabet_count[text[i] - 97]++;	//알파벳 증가
		}
	}
	cout << "총 알파벳 수 " << count << endl;		//알파벳 전체수 출력
	for (int i = 0; i < sizeof(alphabet_count)/4; i++)	//알파벳 수만큼 반복해서
	{
		char alphabet = i + 97;	
		cout << alphabet << " " << "(" << alphabet_count[i] << ") : ";	//타이핑 수를 출력하고
		for (int j = 0; j < alphabet_count[i]; j++)
		{
			cout << "*";	//알파벳 타이핑 수 만큼 * 출력
		}
		cout << endl;
	}
	return 0;
}
