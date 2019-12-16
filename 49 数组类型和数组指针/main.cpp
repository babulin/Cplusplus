#include <iostream>
using namespace std;

//方法一 int[5] 数组类型
typedef int(ARRAY_INT)[5];

//方法二
typedef int(*ARRAY_INT_P)[5];

//数组类型
typedef int(ARRAY)[];

int main() {
	//int[10] 数组类型
	ARRAY_INT int10 = { 1,2,3,4,5};

	for (size_t i = 0; i < 5; i++)
	{
		int10[i] = i;
	}

	for (size_t i = 0; i < 5; i++)
	{
		cout << int10[i] << endl;
	}

	cout << "----------------------" << endl;
	//普通定义
	int arr[5] = {};
	//arr -> 地址 [][][][][]


	//数组类型指针
	ARRAY_INT* pa = &arr;
	//指针类型
	ARRAY_INT_P p = &arr;

	//int[5] 的 p 指针 = arr的地址

	for (size_t i = 0; i < 5; i++)
	{
		(*pa)[i] = i;
		//(*p)[i] = i;
	}

	for (size_t i = 0; i < 5; i++)
	{
		cout << (*pa)[i] << endl;
		//cout << (*p)[i] << endl;
	}

	//数组类型
	ARRAY array = {1,2,3,4,5,6,7};

}