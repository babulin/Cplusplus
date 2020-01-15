#include <iostream>
#include <deque>
using namespace std;

void printDeque(deque<int>& d) {
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++){
		cout << *it << " ";
	}
	cout << endl << "---------------------------" << endl;
}
//初始化
void func1() {

	deque<int> d1;
	deque<int> d2(10,5);//10个指定元素初始化
	deque<int> d3(d2.begin(), d2.end());//使用指定空间初始化
	deque<int> d4(d3);//拷贝构造初始化

	printDeque(d2);
	printDeque(d3);
	printDeque(d4);
}

//赋值 大小操作
void func2() {
	deque<int> d1;
	deque<int> d2;
	deque<int> d3;

	d1.assign(10, 5);//指定10个元素赋值
	d2.assign(d1.begin(), d1.end());//使用指定空间初始化
	d3 = d2;//=赋值操作

	//交换空间
	d1.swap(d2);//d1与d2交换指向的空间

	//是否为空
	if (d1.empty()){
		cout << "d1为空" << endl;
	}
	else {
		cout << "d1不为空 size => " << d1.size() << endl;
	}

	//重置大小
	d1.resize(5);//扔掉后面5个
	printDeque(d1);
	d1.resize(12, 1);//重置为12个，新增的用1初始化
	printDeque(d1);
}

//插入和删除
void func3() {

	deque<int> d1(5,1);
	printDeque(d1);

	//从前面插入
	d1.push_front(10);
	printDeque(d1);

	//从后面插入
	d1.push_back(20);
	printDeque(d1);

	//删除前面
	int val = d1.front();
	if (val == 10){
		d1.pop_front();
	}
	printDeque(d1);

	//删除后面
	val = d1.back();
	if (val == 20) {
		d1.pop_back();
	}
	printDeque(d1);

}
int main() {
	//func1();
	//func2();
	func3();

	//p52;
}