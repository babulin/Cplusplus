#include <iostream>
using namespace std;
struct typeA
{
	int& a;
};

struct typeB
{
	int* a;
};

//const 修饰 p；p指向无法改变，p指向的值可以变更
void motify(int *const p) 
{
	*p = 300;
}

//re引用 别名；int& a = main::&a 自动
void motify2(int& re)
{
	re = 300;
}

int main() {

	//引用所占用的大小跟指针是相等的
	cout << "sizeof(struct typeA)" << sizeof(struct typeA) << endl;
	cout << "sizeof(struct typeB)" << sizeof(struct typeB) << endl;

	int a = 10;
	int& re = a;

	//引用本质是常指针
	int* const p = &a;

	//调用
	motify(&a);
	motify2(a);

	return 0;
}