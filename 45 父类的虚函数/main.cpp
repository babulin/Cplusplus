#include <iostream>
#include <string>
using namespace std;

//基础动物类
class Animal {
private:
protected:
	string name;

public:

	Animal(string _name) {
		name = _name;
		cout << "Animal()" << endl;
	}

	//父类用virtual修饰，表示虚函数，被子类重写
	virtual void run() {
		cout << name << "开始奔跑[动物类]" << endl;
	}

	//virtual 虚析构函数：被子类重写，则先调用子类的析构
	virtual ~Animal() {
		cout << "~Animal()" << endl;
	}
};

//狗
class Dog :public Animal{
private:

public:
	Dog(string _name) :Animal(_name) {
		cout << "Dog()" << endl;
	}

	//加上 virtual 增加可读性，表示从父类重写
	virtual void run() {
		cout << name << "开始奔跑[狗类]" << endl;
	}

	virtual ~Dog() {
		cout << "~Dog()" << endl;
	}
};

//猫
class Cat :public Animal {
private:

public:
	Cat(string _name) :Animal(_name) {
		cout << "Cat()" << endl;
	}

	virtual void run() {
		cout << name << "开始奔跑[猫类]" << endl;
	}

	virtual ~Cat() {
		cout << "~Cat()" << endl;
	}
};

//父类指针或引用 指向子类对象时 调用虚函数将调用被子类重写的函数
void doRun(Animal* animal) {
	//动态联编[根据不同的对象进行调用函数]
	animal->run();

	delete animal;//在这里进行析构：父类虚析构  [~Dog()->~Animal(),子类默认会先析构自己，再调用父类析构]
}

int main() {

	//Animal* animal = new Animal("动物");

	Dog* dog = new Dog("小汪");
	//dog->run();
	//Cat* cat = new Cat("小喵");
	//cat->run();

	//通过基类作为形参 子类实参
	//doRun(animal);
	doRun(dog);
	//doRun(cat);

	//delete animal;
	//delete dog;
	//delete cat;

	//总结：多态的3个条件
	//[1]继承
	//[2]虚函数重写
	//[3]父类指针或引用 子对象


	//重载，重写，重定义
	//重载：相同作用域中 函数名一致，参数不一致
	//重写：子类重写父类 虚函数
	//重定义：子类普通函数和父类普通函数一样 
}