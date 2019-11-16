#include <iostream>
using namespace std;


class Hum {

private:
	int mAge;
	int mId;
public:
	//默认无惨构造函数
	Hum() {
		mAge = 0;
		mId = 0;
		cout << "Hum()无参构造:" << this << endl;
	}

	//重载
	Hum(int id) {
		mId = id;
		mAge = 0;
		cout << "Hum(int id)有参构造:" << this << endl;
	}

	//重载
	Hum(int id, int age) {
		mId = id;
		mAge = age;
		cout << "Hum(int id,int age)有参构造:" << this << endl;
	}

	//显式拷贝构造函数
	//默认拷贝 对指针有问题
	Hum(const Hum& hum) {
		mAge = hum.mAge;
		mId = hum.mId;
		cout << "Hum(const Hum& hum)拷贝构造" << this << endl;
	}

	//=号 赋值操作符
	void operator=(const Hum& hum) {
		mId = hum.mId;
		mAge = hum.mAge;
		cout << "=号操作符赋值" << endl;
	}

	void eat() {
		cout << "age = " << mAge << " id = " << mId << " address:" << this << endl;
	}

	//析构函数
	//析构函数：谁先构造的，谁后被析构
	~Hum() {
		cout << "析构函数:" << mId << " address:" << this << endl;
	}


};

//类作为形参 是拷贝构造
//Hum hum = hum2;
void func(Hum hum) {
	hum.eat();
}

//类作为返回值
Hum func2() {
	Hum temp(10, 20);
	return temp;
}//匿名对象 = temp 拷贝构造

int main() {

	//默认无参构造
	Hum hum;
	//hum.eat();

	//有参数构造
	Hum hum1(1);

	//默认拷贝函数
	Hum hum2(hum1);

	//调用拷贝 （初始化的时候调用的拷贝构造）
	Hum hum3 = hum2;

	//调用的是赋值
	Hum hum4;
	hum4 = hum2;

	//返回匿名对象时；没有任何变量接收它，匿名对象将不会使用
	//函数执行完毕 立即回收
	//函数内局部对象：也是立即回收
	Hum hum5 = func2();//hum5不拷贝;把匿名对象 转正起名 hum5 

	//hum4 =号操作符赋值
	//然后析构了匿名对象
	hum4 = func2();

	//形参调用的是拷贝构造
	func(hum2);


	//cin.get();
	return 0;
}