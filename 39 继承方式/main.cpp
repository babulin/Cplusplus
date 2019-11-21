#include <iostream>
using namespace std;

class Parent {
public:
	int pub;//类 内外都可以访问
protected:
	int pro;//类 内部可以访问，外部无法访问
private:
	int pri;//类 内部可以访问，外部无法访问
};

//--------------------------------------
//公有继承：
//--------------------------------------
class Child :public Parent {
public:
	void show() {
		cout << pub << endl;//可以访问
		cout << pro << endl;//可以访问
		//cout << pri << endl;//不可以
	}
};

class SubChild :public Child {
public:
	void show() {
		cout << pub << endl;//可以访问
		cout << pro << endl;//可以访问
		//cout << pri << endl;//不可以
	}
};

//--------------------------------------
//保护继承：
//--------------------------------------
class Child2 :protected Parent {
public:
	void show() {
		cout << pub << endl;//可以访问
		cout << pro << endl;//可以访问
		//cout << pri << endl;//不可以
	}
};

class SubChild2 :public Child2 {
public:
	void show() {
		cout << pub << endl;//可以访问
		cout << pro << endl;//可以访问
		//cout << pri << endl;//不可以
	}
};


//--------------------------------------
//私有继承：
//--------------------------------------
class Child3 :private Parent {
public:
	void show() {
		cout << pub << endl;//可以访问
		cout << pro << endl;//可以访问
		//cout << pri << endl;//不可以
	}
};

class SubChild3 :public Child3 {
public:
	void show() {
		//cout << pub << endl;//不可以
		//cout << pro << endl;//不可以
		//cout << pri << endl;//不可以
	}
};


int main() {

	Child c1;
	cout << c1.pub << endl;//可以
	//cout << c1.pro << endl;//不可以
	//cout << c1.pri << endl;//不可以

	Child2 c2;
	//cout << c2.pub << endl;//不可以
	//cout << c2.pro << endl;//不可以
	//cout << c2.pri << endl;//不可以

	SubChild2 sc2;
	//cout << sc2.pub << endl;//不可以
	//cout << sc2.pro << endl;//不可以
	//cout << sc2.pri << endl;//不可以
}