#include <iostream>
using namespace std;

class Student {
private:
public:
	int id;
	string name;

	//�޲�������
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

//�̳�
class Student2 :public Student {
private:
	int score;
public:
	//Student2(int _id, string _name, int _score)
	//{
	//	//Ĭ�ϵ��� Student(); �޲�������
	//	id = _id;
	//	name = _name;
	//	score = _score;
	//}

	Student2(int _id, string _name, int _score) :Student(_id, _name) 
	{
		//Ĭ�ϵ��� Student(); �޲�������
		score = _score;
	}

	void show() {
		Student::show();
		cout << " score = " << score << endl;
	}
};

int main() {
	Student s1(10, "����");
	s1.show();

	Student2 s2(11, "����", 100);
	s2.show();
}