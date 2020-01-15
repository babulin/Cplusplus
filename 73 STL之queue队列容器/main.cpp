#include <iostream>
#include <queue>
using namespace std;

void func1() {
	//初始化
	queue<int> q;

	//入队
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	//队尾元素
	cout << "队尾：" << q.back() << endl;

	//输出顺序 先进先出
	while ( ! q.empty())
	{
		//获取队头数据
		cout << q.front() << " ";
		//删除队头数据
		q.pop();
	}
}


int main() {
	func1();

	//作业1：queue容器存放对象指针
	//作业2：queue容器存放stack容器
}