#include <iostream>
#include "MArray.h"

using namespace std;

int main() {
	//数组创建
	MArray arr(10);

	//添加元素
	for (int i = 0; i < 10; i++)
	{
		arr.setData(i, i + 1);
	}

	//遍历元素
	for (int i = 0; i < 10; i++)
	{
		cout << "arr[" << i << "] = " << arr.getData(i) << endl;
	}

	//数组复制
	MArray arr2 = arr;

	//遍历元素
	for (int i = 0; i < 10; i++)
	{
		cout << "arr2[" << i << "] = " << arr2.getData(i) << endl;
	}

	//数组赋值
	MArray arr3;

	//崩溃的原因是，arr3默认赋值函数arr, space指针被 arr3析构。arr再次析构时失败
	//为类添加 operator= 重载=号操作符之后深拷贝 space 单独创建并拷贝，就OK了
	arr3 = arr;

}