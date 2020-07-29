#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Shape {
protected:
	virtual void draw() = 0;
public:
	void paint() { draw(); }
};
class Circle : public Shape{
protected:
	void draw() { cout << "Circle" << endl; }
};
class Rect : public Shape {
protected:
	void draw() { cout << "Rectangle" << endl; }
};
class Line : public Shape {
protected:
	void draw() { cout << "Line" << endl; }
};
int main() {
	vector<Shape*> v;
	vector<Shape*>::iterator it = v.begin();
	int type;
	cout << "그래픽 에디터입니다." << endl;
	while (1) {
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>";
		cin >> type;
		switch (type) {
		case 1:
			int shape;
			cout << "선:1, 원:2, 사각형:3 >>";
			cin >> shape;
			if (shape == 1) v.push_back(new Line()); 
			else if (shape == 2) v.push_back(new Circle()); 
			else if (shape == 3) v.push_back(new Rect());
			break;
		case 2:
		{
			auto it = v.begin();
			int index;
			cout << "삭제하고자 하는 도형의 인덱스 >>";
			cin >> index;
			for (int i = 0; i < v.size(); i++) {
				if (index == i)
					it = v.erase(it);
				else it++;
			}
			break;
		}
		case 3:{
			int i = 0;
			for (it = v.begin(); it != v.end(); it++) {
				cout << i << ": ";
				(*it)->paint();
				i++;
			}
			break;
			}
		case 4: cout << "프로그램을 종료합니다..." << endl; exit(1);
		default: cout << " 다시 입력" << endl;
		}
	}
}
