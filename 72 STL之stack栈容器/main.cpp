#include <iostream>
#include <stack>
using namespace std;

//stack 栈   先进后出，只能从顶端获取数据
//无迭代器，不能遍历，不支持随机访问
void func1() {
	//初始化
	stack<int> s1;
	stack<int> s2(s1);

	//stack操作
	s1.push(10);//压栈
	s1.push(20);//压栈
	s1.push(30);//压栈
	s1.push(100);//压栈

	//取出
	cout << "栈顶数据：" << s1.top() << endl;
	//删除栈顶数据
	s1.pop();

	//弹出数据
	while (!s1.empty()) {
		//取一个 删一个
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << " size:" << s1.size() << endl;
}


int main() {
	
	func1();

	//作业1：stack容器存放对象指针
	//作业2：stack容器存放对象
}