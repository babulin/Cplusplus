#include <iostream>
using namespace std;

class A{};
class B{};
class C :public B{};


//基础类型，继承关系的对象指针或引用
void _static_cast() {
	//-----------------------------
	// static_cast<T>()
	//[1]普通类型转换
	int a = 97;
	char ch = static_cast<char>(a);

	cout << "[1] int类型转换为char ch = " << ch << endl;

	//------------------------------
	//将父类指针转换为子类指针
	B* opB = NULL;
	C* opC = static_cast<C*>(opB);

	//将子类指针转换为父类指针
	C* opC1 = NULL;
	B* opB1 = static_cast<B*>(opC1);

	//------------------------------
	//将父类引用转换为子类引用
	B oB;
	B& oB1 = oB;
	C& oC = static_cast<C&>(oB1);

	//将子类引用转换为父类引用
	C oC1;
	C& oC2 = oC1;
	B& oB2 = static_cast<B&>(oC2);

	//[结论]static_cast 能转换 基础类型，具有继承关系对象的指针，和继承关系对象的引用
}

//具有继承关系的指针或者引用
//转换时进行 安全检查
void _dynamic_cast() {

	//只能将子类转换成父类的指针或者引用
	//------------------------------
	C* opC = NULL;
	B* opB = dynamic_cast<B*>(opC);

	//------------------------------
	C oC;
	C& oC1 = oC;
	B& oB = dynamic_cast<B&>(oC1);

	//子类到父类 （大到小，安全转换）
}

//指针 引用 或者对象指针
void _const_cast() {
	//将const引用变量转换为普通类型引用
	int a = 10;
	const int& b = a;
	int& c = const_cast<int&>(b);
	c = 20;

	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;

	//-------------------------------
	//const指针转换成 普通指针
	const int* p1 = &a;
	int* p2 = const_cast<int*>(p1);
	*p2 = 30;

	//普通指针 转换成 const指针
	const int* p3 = const_cast<const int*>(p2);

	cout << "p1:" << *p1 << endl;
	cout << "p2:" << *p2 << endl;
	cout << "p3:" << *p3 << endl;

	//-------------------------------
}


//强制类型转换
typedef void (*VFUNC)(int, int);
typedef int (*IFUNC)(int, char);

void doSomething(int a,int b) {
	cout << "做了什么乱七八糟的事情" << "a:" << a << " b:" << b << endl;
}

//强制类型转换
void _reinterpret_cast() {
	//1.指针类型
	A* oA = nullptr;
	B* oB = reinterpret_cast<B*>(oA);

	//2.函数指针
	VFUNC vfunc = doSomething;
	IFUNC ifunc = reinterpret_cast<IFUNC>(vfunc);

	ifunc(1, 'A');
}

int main() {

	//_const_cast();
	_reinterpret_cast();
	
}