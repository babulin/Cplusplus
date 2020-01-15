#include <iostream>
#include <list>
using namespace std;

//初始化
void func1() {
	list<int> l1;
	list<int> l2(10, 1);//10个1初始化
	list<int> l3(l2);//拷贝构造
	list<int> l4(l3.begin(), l3.end());//指定区间

	for (list<int>::iterator  it = l4.begin(); it != l4.end(); it++)
	{
		cout << (*it) << " ";
	}

	cout << endl;
}

//插入删除
//不支持随机访问
void func2() {

	list<int> li;

	//尾部插入
	li.push_back(10);

	//头部插入
	li.push_front(20);

	//插入数据
	li.insert(li.begin(),30);//迭代器 插入数据
	li.insert(li.end(),200);//迭代器 插入数据

	list<int>::iterator it = li.begin();

	//it + 5;//不支持
	it++;
	it++;
	li.insert(it, 500);
	li.insert(it, 200);

	//删除
	//li.pop_front();
	//li.pop_back();

	//删除指定区间
	//li.erase(li.begin(), li.end());//迭代器区间
	//li.clear();//清除所有

	//删除所有匹配的元素
	li.remove(200);

	for (list<int>::iterator lit = li.begin(); lit != li.end(); lit++)
	{
		cout << (*lit) << " ";
	}
	cout << endl;
}

//大小操作
void func3() {
	list<int> l1;
	l1.size();//数量
	l1.empty();//判断空
	l1.resize(1);//放大缩小
	l1.resize(10,1);//放大缩小
}

//赋值操作
void func4() {
	list<int> l1;
	l1.assign(10, 1);

	list<int> l2;
	l2 = l1;//=号赋值

	l2.swap(l1);//交换
}

void ShowList(list<int>& li) {
	for (list<int>::iterator lit = li.begin(); lit != li.end(); lit++)
	{
		cout << (*lit) << " ";
	}
	cout << endl;
}

//排序 反转
void func5() {
	list<int> li;

	for (int i = 0; i < 10; i++)
	{
		li.push_back(i);
	}
	ShowList(li);

	//反转
	li.reverse();
	ShowList(li);
}

bool doSort(int v1,int v2) {
	return v1 > v2;
}

//排序
void func6() {
	list<int> li;
	li.push_back(2);
	li.push_back(1);
	li.push_back(7);
	li.push_back(5);
	ShowList(li);

	//默认 升序
	li.sort();
	ShowList(li);

	//指定 降序
	li.sort(doSort);
	ShowList(li);
}


int main() {
	//func1();
	//func2();

	//func5();
	func6();
}