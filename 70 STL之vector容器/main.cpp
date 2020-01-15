#include <iostream>
#include <vector>
using namespace std;


void printVector(vector<int> &v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//初始化
void func1() {
	vector<int> v1;//默认构造

	//数组初始化
	int arr[] = { 10,20,30,40 };
	vector<int> v2(arr, arr + sizeof(arr) / sizeof(int));//v2(pbegin,pend);
	vector<int> v3(v2.begin(), v2.end());

	//拷贝构造
	vector<int> v4(v3);

	printVector(v2);
	printVector(v3);
	printVector(v4);

}

//赋值操作
void func2() {
	//数组初始化
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	vector<int> v2;
	//成员方法赋值
	v2.assign(v1.begin(), v1.end());

	vector<int> v3;
	//重载=赋值
	v3 = v2;

	int arr1[] = { 100,200,300,400 };
	vector<int> v4(arr1, arr1 + sizeof(arr1) / sizeof(int));

	//v4与v1交换 指针交换了
	v4.swap(v1);

	printVector(v1);
	printVector(v2);
	printVector(v3);
	printVector(v4);
}

//大小操作
void func3() {

	//数组初始化
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));
	
	//大小数量
	cout << "size:" << v1.size() << endl;
	
	//判断是否为空
	if (v1.empty()) {
		cout << "v1 已为空" << endl;
	}
	else {
		cout << "v1 不为空" << endl;
	}

	printVector(v1);

	//缩小 舍去后面
	v1.resize(2);
	printVector(v1);

	//增大 默认补充0
	v1.resize(6);
	printVector(v1);

	//增大 默认值初始化
	v1.resize(8, 1);
	printVector(v1);

	//容量：申请的空间大小
	//size:装载的元素个数
	//[一次性申请大空间，不够再进行扩充(申请新的空间，拷贝旧数据)]
	cout << "size:" << v1.size() << endl;
	cout << "容量:" << v1.capacity() << endl;
}

//存取数据
void func4() {
	//数组初始化
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;

	//区别：at() 抛异常  [] 不抛异常

	//返回第一个元素
	cout << "front:" << v1.front() << endl;
	//返回最后一个元素
	cout << "back:" << v1.back() << endl;
}


//插入删除
void func5() {

	vector<int> v;
	v.push_back(10);
	v.push_back(20);

	//头插入
	v.insert(v.begin(), 30);

	//尾插入
	v.insert(v.end(), 40);

	//中间随机访问插入
	v.insert(v.begin() + 2, 100);

	//备注：一般支持[] 访问，或者支持指针+2等都支持随机访问
	printVector(v);


	//删除第一个元素
	v.erase(v.begin());
	printVector(v);

	//删除第二个到最后
	v.erase(v.begin() + 1, v.end());
	printVector(v);

	//清空
	v.clear();
	cout << "size:" << v.size() << endl;
}


//巧用swap收缩空间
void func6() {
	
	vector<int> v;

	for (size_t i = 0; i < 1000; i++)
	{
		v.push_back(i);
	}
	cout << "size:" << v.size() << endl;
	cout << "容量:" << v.capacity() << endl;
	cout<< "-----------------------" << endl;


	//缩小空间
	v.resize(10);
	cout << "size:" << v.size() << endl;
	cout << "容量:" << v.capacity() << endl;
	cout << "-----------------------" << endl;

	//swap() 交换数据
	//vector<int>(v).swap(v);//匿名函数与v交换，之后匿名函数销毁
	vector<int> v2(v);
	v2.swap(v);
	cout << "size:" << v.size() << endl;
	cout << "容量:" << v.capacity() << endl;
}

//reserve 预留空间[因为动态数组增长时，会重新申请空间，拷贝数据]
void func7() {

	//reserve 预留空间 resize 区别

	int num = 0;//统计重新申请空间
	int* address = NULL;

	vector<int> v;

	//预留空间
	v.reserve(1000);

	for (int i = 0; i < 1000; i++)
	{
		v.push_back(i);

		//第一个元素的首地址 改变时会触发
		if (address != &(v[0]))
		{
			address = &(v[0]);//等于下一个首地址
			num++;
		}
	}

	cout << "申请次数:" << num << endl;
}

int main() {
	//func1();
	//func2();
	//func3();
	//func4();
	//func5();
	//func6();
	func7();

	//p-47
}