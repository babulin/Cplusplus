#include <iostream>
using namespace std;

//ָ���׳��쳣����
void func1() throw(int,float,char) {

	throw "abc";
}

//�����׳��κ��쳣����
void func2() throw(){
	throw - 1;
}

//�����׳��κ��쳣����
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
		cout << "����δ֪�쳣����" << endl;
	}
}