#include <iostream>
#include <string>
using namespace std;
int main()
{
	char coffee[100];
	int num;
	int income = 0;
	cout << "에스프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다." << endl;
	while (income < 20000)	//20000원 이상 벌면 반복 종료
	{
		cout << "주문>>";
		cin >> coffee >> num;	//커피와 잔 수 입력
		if (strcmp(coffee, "에스프레소") == 0)	//문자열 비교를 통한 구분
		{
			cout << 2000 * num << "원입니다. 맛있게드세요" << endl;
			income += (2000 * num);
		}
		else if (strcmp(coffee, "아메리카노") == 0)
		{
			cout << 2300 * num << "원입니다. 맛있게드세요" << endl;
			income += (2300 * num);
		}
		else if (strcmp(coffee, "카푸치노") == 0)
		{
			cout << 2500 * num << "원입니다. 맛있게드세요" << endl;
			income += (2500 * num);	
		}
		else
		{
			cout << "올바른 숫자를 입력해주세요" << endl;
		}	
	}
	cout << "오늘 " << income << "원을 판매하여 카페를 닫습니다. 내일 봐요~~~" << endl;
	return 0;
}	
