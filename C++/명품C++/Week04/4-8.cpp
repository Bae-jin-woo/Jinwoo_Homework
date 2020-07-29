#include <iostream>
using namespace std;

struct student {
	int num;		// 학번을 저장할 멤버
	char name[20];	// 이름을 저장할 멤버
	int score[5];	// 5과목의 점수를 저장할 멤버
	double avg;	// 평균을 저장할 멤버
};
void Show(struct student s);
double SetAverage(struct student s);
int main() {
	struct student s;
	s.num = 315;	//구조체 초기화
	strcpy(s.name, "홍길동");
	s.score[0] = 82;
	s.score[1] = 93;
	s.score[2] = 74;
	s.score[3] = 90;
	s.score[4] = 65;
	Show(s);
	return 0;
}
void Show(struct student s) {	//출력 함수
	cout << "학번 : " << s.num << endl;
	cout << "이름 : " << s.name << endl;
	cout << "점수 : ";
	for (int i = 0; i < 5; i++)
		cout << s.score[i] << " ";
	cout << endl;
	cout << "평균 : " << SetAverage(s);
}
double SetAverage(struct student s) {	//평균값 반환함수
	double total = 0;
	for (int i = 0; i < 5; i++)
		total += s.score[i];
	s.avg = total / 5;
	return s.avg;
}
