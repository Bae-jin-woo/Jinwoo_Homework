#include <iostream>
#include <string>
using namespace std;

class Person {
	int id;
	double weight;
	string name;
public:
	
	Person(int id = 1 , string name = "grace", double weight=20.5) {
		this->id = id;
		this->name = name;
		this->weight = weight;
	}
	void show() { cout << id << ' ' << weight << ' ' << name << endl; }
};

int main() {
	Person grace, ashely(2, "Ashley"), helen(3, "Helen", 32.5);
	grace.show();
	ashely.show();
	helen.show();
}
