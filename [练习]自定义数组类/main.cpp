#include <iostream>
#include "MArray.h"

using namespace std;


int main() {
	//数组创建
	MArray arr(5),arr1(5);
	cin >> arr;
	cout << arr;

	//赋值
	arr1 = arr;

	if (arr != arr1)
	{
		cout << "数组不一样" << endl;
	}
	else {
		cout << "数组一样" << endl;
	}

	//添加元素
	//for (int i = 0; i < 10; i++)
	//{
	//	//arr.setData(i, i + 1);
	//	arr[i] = i + 1;//space[i] = i + 1;需要[]重载返回 space[i]的别名
	//}

	//遍历元素
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << "arr[" << i << "] = " << arr[i] << endl;
	//}
	

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

	arr2 = arr;//操作符重载后，判断是否自身，清除垃圾，深度拷贝

}