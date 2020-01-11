#include <iostream>
#include <vector>//动态数组
#include <algorithm>//算法
using namespace std;

//回调函数
void PrintVector(int v) {
	cout << v << endl;
}

//可以存放常用类型
void func1() {
	
	//定义容器
	vector<int> vec;
	//向后插入数据
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	//迭代器类型
	vector<int>::iterator pBegin = vec.begin();
	vector<int>::iterator pEnd = vec.end();

	//迭代器算法
	for_each(vec.begin(), vec.end(), PrintVector);

}

//可以存放自定义类型
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
	//对象
	Person p1(1,10),p2(2,20);
	vp.push_back(p1);
	vp.push_back(p2);

	//自己遍历
	for (vector<Person>::iterator it = vp.begin();it != vp.end(); it++){
		(*it).show();
	}
}

//指针类型
void func3() {
	vector<Person*> vp;
	//对象
	vp.push_back(new Person(1,10));
	vp.push_back(new Person(2,20));

	//自己遍历
	for (vector<Person*>::iterator it = vp.begin(); it != vp.end(); it++) {
		(*it)->show();
	}
}

int main() {
	//func1();
	func2();
	//func3();
}