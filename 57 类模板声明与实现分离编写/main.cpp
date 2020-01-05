#include "Person.hpp"
//#include "Person.cpp"
//#include "Person.h"

int main() {
	//由于 类模板2次编译，第一次 类模板语法编译，第二次 根据当前文件实际调用情况生成具体函数
	//因为先编译 main.cpp 编译器遇到Person.h声明，则将Person<int> p(10);
	//调用构造函数交给链接器来查找构造，函数一样，导致编译通过，调用失败
	Person<int> p(10);
	p.Show();

	//【解决，写成hpp 一个文件，相当于把代码写一起拷贝进来】
}