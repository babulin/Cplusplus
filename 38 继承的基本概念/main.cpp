#include <iostream>
using namespace std;

class Student {
private:
public:
	int id;
	string name;

	//无参数构造
	Student() {

	}

	Student(int _id, string _name) {
		id = _id;
		name = _name;
	}

	void show() {
		cout << "id = " << id << "  name = " << name << endl;
	}
};

//继承
class Student2 :public Student {
private:
	int score;
public:
	//Student2(int _id, string _name, int _score)
	//{
	//	//默认调用 Student(); 无参数构造
	//	id = _id;
	//	name = _name;
	//	score = _score;
	//}

	Student2(int _id, string _name, int _score) :Student(_id, _name) 
	{
		//默认调用 Student(); 无参数构造
		score = _score;
	}

	void show() {
		Student::show();
		cout << " score = " << score << endl;
	}
};

int main() {
	Student s1(10, "张三");
	s1.show();

	Student2 s2(11, "李四", 100);
	s2.show();
}