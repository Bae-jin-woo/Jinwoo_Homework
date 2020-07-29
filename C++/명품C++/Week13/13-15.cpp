#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius, string name) {
		this->radius = radius; this->name = name;
	}
	double getArea() { return 3.14*radius*radius; }
	string getName() { return name; }
	int getRadius() { return radius; }
};

int main() {
	vector<Circle*> v;
	int type;
	int r;
	string name;
	cout << "원을 삽입하고 삭제하는 프로그램입니다." << endl;
	while (1) {
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>";
		cin >> type;
		if (type == 1) {	//반지름과 이름을 입력받아 클래스를 만들고 벡터에 삽입
			cout << "생성하고자 하는 원의 반지름과 이름은 >>";
			cin >> r >> name;
			v.push_back(new Circle(r,name));
		}
		else if (type == 2) {
			cout << "삭제하고자 하는 원의 이름은 >>";
			cin >> name;
			vector<Circle*>::iterator it;
			it = v.begin();
			while(it != v.end()) {	//이름이 같은 모든 원 삭제
				if ((*it)->getName() == name) 
					it = v.erase(it);
				else 
					++it;
			}
		}
		else if (type == 3) {
			for (int i = 0; i < v.size(); i++)
				cout << v[i]->getRadius() <<" "<<v[i]->getName() << endl;
			cout << endl;
		}
		else if (type == 4) {
			cout << "프로그램을 종료합니다 ..." << endl;
			break;
		}
	}
}
