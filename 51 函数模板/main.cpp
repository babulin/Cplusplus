#include <iostream>
using namespace std;

template <class T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
	cout << "调用mySwap函数模板" << endl;
}

template <class T>
void mySwap(T& a) {
	T temp = a;
	cout << "调用mySwap函数模板 重载" << "temp = " << temp << endl;
}

//普通函数参数类型自动转换
void mySwap(int a,char ch) {
	int num = a + ch;
	cout << "调用mySwap(int,char)普通函数" << " num = " << num << endl;
}

//普通函数参数类型自动转换
void mySwap(int a, int b) {
	int num = a + b;
	cout << "调用mySwap(int,int)普通函数" << " num = " << num << endl;
}


int main() {
	
#if 0
	//[1]自动类型推导
	//int 类型
	int a = 10;
	int b = 20;
	cout << "a = " << a << " b = " << b << endl;
	mySwap(a, b); //自动类型推导
	cout << "a = " << a << " b = " << b << endl;

	//float 类型
	float a1 = 10.5f;
	float b1 = 20.5f;
	cout << "a = " << a1 << " b = " << b1 << endl;
	mySwap(a1, b1);//自动类型推导
	cout << "a = " << a1 << " b = " << b1 << endl;

	//[2]显式指定类型
	char ch1 = 'A';
	char ch2 = 'B';
	cout << "ch1 = " << ch1 << " ch2 = " << ch2 << endl;
	mySwap<char>(ch1, ch2);//显式类型
	cout << "ch1 = " << ch1 << " ch2 = " << ch2 << endl;
#endif // 0

#if 0
	//注意
	//普通函数：自动类型转换，int 类型，可以传char类型，自动转换
	//函数模板：必须类型匹配
	int ia = 10;
	int ib = 20;
	char ca = 'A';
	char cb = 'B';

	//int char
	mySwap(ia, ca);//调用 mySwap(int a,char ch) 普通函数

	//int int
	mySwap(ia, ib);//调用 mySwap(int a,char ch) 函数模板

	//char int
	mySwap(ca, ib);//调用 mySwap(int a,char ch) 普通模板 [char 自动转换成 int]
#endif // 0

#if 0
	//函数模板可以重载
	int aa = 10;
	int bb = 20;

	//函数模板
	mySwap(aa, bb);

	//函数模板重载
	mySwap(aa);
#endif // 0


	int a = 10;
	int b = 20;
	//优先考虑匹配普通函数
	mySwap(a, b);

	//可以强制指定调用模板
	mySwap<int>(a, b);

	float f1 = 10.5f;
	float f2 = 20.5f;
	mySwap(f1, f2);
}