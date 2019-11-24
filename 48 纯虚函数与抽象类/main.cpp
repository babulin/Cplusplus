#include <iostream>
#include <string>
using namespace std;

//类中，有一个纯虚函数，则为抽象类，
//继承抽象类必须重写所有纯虚函数
//抽象类无法被实例化
class Object {
protected:
	//id
	int id;
	//对象昵称
	string name;
	//血值
	int hp;
public:
	Object(int _id, string _name, int _hp) {
		id = _id;
		name = _name;
		hp = _hp;
	}

	//[纯虚函数]展示基本属性
	virtual void show() = 0;
};


class Human :public Object {
public:
	Human(int _id, string _name, int _hp) :Object(_id, _name, _hp) {

	}

	//展示基本属性
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

	//展示基本属性
	virtual void show() {
		cout << "id:" << id << endl;
		cout << "name:" << name << endl;
		cout << "hp:" << hp << endl;
		cout << "type:" << "升级2.0" << endl;
	}
};



//业务层 只与抽象类编程
int main() {

	//如果升级，只需要将类重写抽象类升级即可；

	Object* oh = new Monster(1, "战士", 100);
	//Object* om = new Monster(2, "稻草人", 200);

	oh->show();
	//om->show();

	delete oh;
	//delete om;
}