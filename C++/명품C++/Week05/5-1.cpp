#include <iostream>
using namespace std;
class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r; green = g; blue = b; }
	void SetColor(int r, int g, int b) { red = r; green = g; blue = b; }
	void Show() { cout << red << ' ' << green << ' ' << blue << endl; }
};
int main() {
	Color screenColor(255, 0, 0);	//빨간색의 screenColor 객체 생성
	Color *p;	//Color 타입의 포인터 변수 p 선언
	p = &screenColor;	//p가 screenColor의 주소를 가지도록 코드 작성
	p->Show();	//p와 show()를 이용하여 screenColor 색 출력
	Color colors[3];	//Color의 일차원배열 colors 선언, 원소는 3개
	p = colors;	//p가 colors 배열을 가리키도록 코드 작성
	p->SetColor(255, 0, 0);		//p와 setColor()를 이용하여 colors[0],colors[1],colors[2]가
	(p+1)->SetColor(0, 255, 0);	//각각 빨강,초록,파랑색을 가지도록 코드 작성
	(p+2)->SetColor(0, 0, 255);	
	for (int i = 0; i < sizeof(colors)/sizeof(Color); i++)
		(p + i)->Show();	//p와 show()를 이용하여 colors 배열의 모든 객체의 색, 출력, for문 이용
}
