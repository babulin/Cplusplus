#include <iostream>
using namespace std;

//指定抛出异常类型
void func1() throw(int,float,char) {

	throw "abc";
}

//不能抛出任何异常类型
void func2() throw(){
	throw - 1;
}

//可以抛出任何异常类型
void func3(){

	throw - 1;
}

int main() {

	try
	{
		func1();
	}
	catch (char* ch)
	{
		cout << "char*:" << ch << endl;
	}
	catch (int ie)
	{
		cout << "int:" << ie << endl;
	}
	catch (float fe)
	{
		cout << "float:" << fe << endl;
	}
	catch (...) {
		cout << "捕获未知异常类型" << endl;
	}
}