#include <iostream>
#include <string>
using namespace std;

int cal(int num1, char *cal_type, int num2);

int main()
{
	int num1, num2;
	char *cal_type = NULL;	//strtok 함수를 사용하기 위해 포인터 변수 사용
	char string[100];
	while (1)
	{
		cout << "?";
		cin.getline(string, 100);	//공백을 포함한 문자열 입력
		num1 = atoi(strtok(string, " "));	//문자열에서 공백이 나올때까지 읽고 공백은 NULL로 바꾸고 정수로 변환
		cal_type = strtok(NULL, " ");	//첫번째 공백부터 두번째 공백 사이에 문자를 읽어서 문자열의 포인터 주소 반환
		num2 = atoi(strtok(NULL, " "));	
		cout << num1 << cal_type << num2 << "=" << cal(num1, cal_type, num2) << endl;
	}
	return 0;
}

int cal(int num1, char *cal_type, int num2)
{
	if (strcmp(cal_type, "+") == 0)	return num1 + num2;
	else if (strcmp(cal_type, "-") == 0)	return num1 - num2;
	else if (strcmp(cal_type, "*") == 0)	return num1 * num2;
	else if (strcmp(cal_type, "/") == 0)	return num1 / num2;
	else if (strcmp(cal_type, "%") == 0)	return num1 % num2;
	else {
		cout << "잘못된 값입니다." << endl;
		exit(1);
	}
}
