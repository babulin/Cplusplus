#include<iostream>
using namespace std;

class Test {
private:
	int m_a;
	int m_b;
public:
	Test(int a, int b) {
		m_a = a;
		m_b = b;
		cout << "Test构造" << endl;
	}

	void show() {
		cout << "a=" << m_a << " b=" << m_b << endl;
	}

	~Test() {
		cout << "Test析构" << endl;
	}
};

void useMalloc() {
	int* pint = (int*)malloc(sizeof(int));//这里是开辟多少个字节

	*pint = 10;//指针为开辟的空间赋值
	cout << "pint=" << *pint <<" :"<< pint << endl;
	if (pint != NULL)
	{
		free(pint);
		pint = NULL;
	}

	//开辟数组
	int* parray = (int*)malloc(sizeof(int) * 10);//开辟10个int大小
	for (int i = 0; i < 10; i++)
	{
		parray[i] = i + 1;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d", parray[i]);
	}
	printf("\n");
	if (parray != NULL)
	{
		free(parray);
		parray = NULL;
	}

}

void useNew() {
	//开辟变量
	int* pint = new int;
	*pint = 10;
	cout << "pint=" << *pint << " sizeof(pint) = "<< sizeof(pint) <<" :" << pint << endl;
	if (pint != NULL)
	{
		delete pint;
		pint = NULL;
	}

	//开辟数组
	int a(10);//初始化变量
	int a1 = int(10);//匿名变量转正 一个道理
	
	int* parray = new int[10];//10个int
	for (int i = 0; i < 10; i++)
	{
		parray[i] = i + 1;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << parray[i];
	}
	cout << endl;

	if (parray != NULL)
	{
		delete[] parray;
	}

	cout << "=======================" << endl;
	//堆上开辟对象
	Test* t1 = new Test(1,2);//调构造
	t1->show();
	delete t1;//调析构
}



int main() {
	//使用malloc 和 free 标准库 stdlib.h
	useMalloc();

	//使用new 和 delete 
	useNew();
}