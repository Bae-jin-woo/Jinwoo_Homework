#include <iostream>
using namespace std;
int main()
{
	int c = 0;
	int man;
	cout << "****** 승리장에 오신 것을 환영합니다. *******" << endl;
	while (c!=4)	//4번을 입력할때까지 반복
	{
		cout << "짬뽕:1, 짜장:2, 군만두:3, 종료:4>>";
		cin >> c;
		switch (c)
		{
		case 1:
		{
			cout << "몇인분?";
			cin >> man;
			cout << "짬뽕 " << man << "인분 나왔습니다." << endl;
			break;
		}
		case 2:
		{
			cout << "몇인분?";
			cin >> man;
			cout << "짜장 " << man << "인분 나왔습니다." << endl;
			break;
		}
		Case 3:
		{
			cout << "몇인분?";
			cin >> man;
			cout << "군만두 " << man << "인분 나왔습니다." << endl;
			break;
		}
		case 4:
		{
			cout << "오늘 영업은 끝났습니다." << endl;
			break;
		}
		default:
			cout << "다시 주문하세요!!!" << endl;
			break;	//잘못 입력할 경우
		}
	}
	return 0;
}
