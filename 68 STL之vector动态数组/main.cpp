#include <iostream>
#include <vector>//��̬����
#include <algorithm>//�㷨
using namespace std;

//�ص�����
void PrintVector(int v) {
	cout << v << endl;
}

//���Դ�ų�������
void func1() {
	
	//��������
	vector<int> vec;
	//����������
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	//����������
	vector<int>::iterator pBegin = vec.begin();
	vector<int>::iterator pEnd = vec.end();

	//�������㷨
	for_each(vec.begin(), vec.end(), PrintVector);

}

//���Դ���Զ�������
class Person {
protected:
	int mId;
	int mAge;
public:
	Person(int id, int age) : mId(id), mAge(age) {
	
	}

	void show() {
		cout << "id = " << mId << " age = " << mAge << endl;
	}
};

void func2() {
	vector<Person> vp;
	//����
	Person p1(1,10),p2(2,20);
	vp.push_back(p1);
	vp.push_back(p2);

	//�Լ�����
	for (vector<Person>::iterator it = vp.begin();it != vp.end(); it++){
		(*it).show();
	}
}

//ָ������
void func3() {
	vector<Person*> vp;
	//����
	vp.push_back(new Person(1,10));
	vp.push_back(new Person(2,20));

	//�Լ�����
	for (vector<Person*>::iterator it = vp.begin(); it != vp.end(); it++) {
		(*it)->show();
	}
}

int main() {
	//func1();
	func2();
	//func3();
}