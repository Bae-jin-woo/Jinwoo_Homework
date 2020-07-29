#include <iostream>
#include <string>
using namespace std;

class Shape {
	Shape* next;
protected:
	virtual void draw() { cout << "Shape" << endl; }
public:
	Shape() { next = NULL; }
	virtual ~Shape(){}
	void paint() { draw(); }
	Shape* add(Shape *p) { this->next = p; return p; }
	Shape* getNext() { return next; }
	void setNext(Shape *p) { this->next = p->next; }
};

class Circle : public Shape {
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

class UI {
public:
	static int selectMenu()
	{
		int select;
		cout << "삽입:1, 삭제:2, 보기:3, 종료:4 >> ";
		cin >> select;
		return select;
	}

	static int selectShape()
	{
		int select;
		cout << "선:1, 원:2, 사각형:3 >> ";
		cin >> select;
		return select;
	}

	static void error()
	{
		cout << "잘못입력하셨습니다!!" << endl;
	}

	static int deleteMenu()
	{
		int indexOfDelete;
		cout << "삭제하고자 하는 도형의 인덱스 >> ";
		cin >> indexOfDelete;
		return indexOfDelete;
	}
};

class GraphicEditor : public Shape{
	Shape *pStart, *pLast, *p;
public:
	void run() {
		pStart = NULL;
		static int numOfElement = 0;
		cout << "그래픽 에디터입니다." << endl;
		while (1) {
			int menu = UI::selectMenu();
			if (menu == 1) {
				int shape = UI::selectShape();
				if (numOfElement==0) {	//최초 삽입일 경우 Start에 객체 생성
					switch (shape) {
					case 1: pStart = new Line(); break;
					case 2: pStart = new Circle(); break;
					case 3: pStart = new Rect(); break;
					default: UI::error();
					}
					pLast = pStart;
				}
				else {	//최초 삽입이 아닐 경우  Last를 이동하고 객체 생성
					switch (shape) {
					case 1: pLast = pLast->add(new Line()); break;
					case 2: pLast = pLast->add(new Circle()); break;
					case 3: pLast = pLast->add(new Rect()); break;
					default: UI::error();
					}
				}
				numOfElement++;
			}
			else if (menu == 2) {
				int indexOfDelete = UI::deleteMenu();

				p = pStart;
				if (indexOfDelete == 0) { // 0번 삭제일 때
					pStart = p->getNext(); // start를 다음 객체로 바꾼다.
					numOfElement--; // 요소 개수를 1 감소시킨다.
				}
				else if (indexOfDelete <= (numOfElement - 1)) {
					Shape *prev = p; Shape *node = p->getNext();
					int num = indexOfDelete;
					while (indexOfDelete != 1) {
						prev = node; // 현재 노드를 다음 노드로 바꾼다.
						node = node->getNext(); // 다음 노드를 다다음 노드로 바꾼다.
						indexOfDelete--; // 개체 수를 감소시킨다.
					}
					prev->setNext(node); // 현재 노드를 다음 노드로 설정한다.
					numOfElement--; // 개체 수 감소
					if (numOfElement == 1)  pLast = pStart;

					// 남은 요소가 1개일 때, 마지막이 처음이다.

					if (numOfElement == num) pLast = prev;
					delete node; // 노드를 해제한다.
				}
				else UI::error();
			}
			else if (menu == 3) {
				int i = 0; p = pStart;
				while (p != NULL) { 
					cout << i << " :";
					p->paint(); 
					p = p->getNext(); 
					i++;
				}
			}
			else if (menu == 4) {
				cout << "프로그램을 종료합니다." << endl;
				return;
			}
		}
	}

};

int main() {
	GraphicEditor gc;
	gc.run();
}
