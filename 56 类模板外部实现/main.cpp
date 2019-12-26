#include <iostream>
using namespace std;

template <class T>
class Person {
protected:
	T mId;
	T mAge;
public:
	Person(T id,T age);
	void show();

	//---------------------------------------------------
	//重载左移操作符 非成员函数 [全局函数模板]
	template <class T>
	friend ostream& operator<<(ostream& os, Person<T>& p);
};


//类模板外部实现
template <class TE>
Person<TE>::Person(TE id,TE age) {
	mId = id;
	mAge = age;
}

//需指定类模板
template <class TE>
void Person<TE>::show() {
	cout << "id:" << mId << " age:" << mAge << endl;
}

//-----------------------------------------------------
//[全局函数模板] 并不是类模板函数实现
template <class T>
ostream& operator<<(ostream& os, Person<T>& p) {
	os << "id:" << p.mId << " age:" << p.mAge << endl;
	return os;
}

int main() {

	Person<int> p(10, 25);
	//p.show();
	cout << p;
}