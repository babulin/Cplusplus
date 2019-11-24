#include <iostream>
#include <string>
using namespace std;

//���У���һ�����麯������Ϊ�����࣬
//�̳г����������д���д��麯��
//�������޷���ʵ����
class Object {
protected:
	//id
	int id;
	//�����ǳ�
	string name;
	//Ѫֵ
	int hp;
public:
	Object(int _id, string _name, int _hp) {
		id = _id;
		name = _name;
		hp = _hp;
	}

	//[���麯��]չʾ��������
	virtual void show() = 0;
};


class Human :public Object {
public:
	Human(int _id, string _name, int _hp) :Object(_id, _name, _hp) {

	}

	//չʾ��������
	virtual void show() {
		cout << "id:" << id << endl;
		cout << "name:" << name << endl;
		cout << "hp:" << hp << endl;
	}
};

class Monster :public Object {
public:
	Monster(int _id, string _name, int _hp) :Object(_id, _name, _hp) {

	}

	//չʾ��������
	virtual void show() {
		cout << "id:" << id << endl;
		cout << "name:" << name << endl;
		cout << "hp:" << hp << endl;
		cout << "type:" << "����2.0" << endl;
	}
};



//ҵ��� ֻ���������
int main() {

	//���������ֻ��Ҫ������д�������������ɣ�

	Object* oh = new Monster(1, "սʿ", 100);
	//Object* om = new Monster(2, "������", 200);

	oh->show();
	//om->show();

	delete oh;
	//delete om;
}