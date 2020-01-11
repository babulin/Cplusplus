#include <iostream>
using namespace std;

//-----------------------
//算法
//统计要查询的数据个数
int myCout(int* begin, int* end, int val) {
	int num = 0;
	while (begin != end)
	{
		if (*begin == val)
		{
			num++;
		}
		begin++;//指针指向下一个
	}

	return num;
}


int main() {
	//--------------------
	//容器
	int arr[] = { 0,1,2,5,6,8,0,3,6,8,0 };

	//迭代器
	int* pBegin = arr;//指向首地址
	int* pEnd = &(arr[sizeof(arr) / sizeof(int)]);//取最后一个元素下一个的地址

	//---------------------
	//迭代器使用算法
	int num = myCout(pBegin, pEnd, 0);
	cout << "0 的个数 num:" << num << endl;
}