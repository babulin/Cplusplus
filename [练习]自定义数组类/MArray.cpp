#include "MArray.h"

/*---------------------------------
 * 默认无参数构造
 */
MArray::MArray() {
	len = 0;
	space = nullptr;
}

/*---------------------------------
 * 按数组长度构造
 */
MArray::MArray(int len)
{
	if (len <= 0)
	{
		this->len = 0;
		return;
	}

	this->len = len;
	space = new int[this->len];
}

/*---------------------------------
 * 拷贝构造函数
 */
MArray::MArray(const MArray& other)
{
	if (other.len <= 0)
	{
		//没有数据可以拷贝
		return;
	}

	//拷贝长度
	len = other.len;
	//指针开辟新空间
	space = new int[len];
	//拷贝数组值
	for (int i = 0; i < len; i++)
	{
		space[i] = other.space[i];
	}
}

/*---------------------------------
 * 为数组添加值
 */
void MArray::setData(int index, int data)
{
	if (space == nullptr)
	{
		//返回错误
		return;
	}

	if (len <= index)
	{
		//索引值错误
		return;
	}
	space[index] = data;
}

/*---------------------------------
 * 返回值
 */
int MArray::getData(int index)
{
	return space[index];
}

/*---------------------------------
 * 返回数组长度
 */
int MArray::getLen()
{
	return len;
}

/*
* 重载 = 号操作符
*/
void MArray::operator=(const MArray& other)
{
	if (other.len <= 0)
	{
		//没有数据可以拷贝
		return;
	}

	//拷贝长度
	len = other.len;
	//指针开辟新空间
	space = new int[len];
	//拷贝数组值
	for (int i = 0; i < len; i++)
	{
		space[i] = other.space[i];
	}
}

/*
* 析构函数
*/
MArray::~MArray()
{
	if (space != nullptr)
	{
		delete[] space;
		space = nullptr;
		len = 0;
	}
}

