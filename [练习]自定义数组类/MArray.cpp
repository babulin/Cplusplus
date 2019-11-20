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
int MArray::getLen() const
{
	return len;
}

/*
* 重载 = 号操作符
*/
MArray& MArray::operator=(const MArray& other)
{

	if (this == &other)
	{
		//对象自身
		return *this;
	}

	if (space != nullptr)
	{
		delete[] space;
		space = nullptr;
		len = 0;
	}

	if (other.len <= 0)
	{
		//没有数据可以拷贝
		return *this;
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

	return *this;
}

//重载[]下标符号
int& MArray::operator[](int index) const
{
	// TODO: 在此处插入 return 语句
	if (index >= len)
	{
		//修改最后一个
		return space[len - 1];
	}
	return space[index];
}

//重载 !=
bool MArray::operator!=(MArray& arr2)
{
	return !(*this == arr2);//调用的 == 重载
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

//[1]全局函数重载 <<
//[2]如果我想other只读 other.getLen()将无法访问，原因是 other.getLen(MArray* this); 方法也加只读限定符
std::ostream& operator<<(std::ostream& os,const MArray& other) {
	std::cout << "[<<重载]遍历数组：" << std::endl;

	for (int i = 0; i < other.getLen(); i++)
	{
		std::cout << "arr[" << i << "] = " << other[i] << std::endl;
	}

	return os;
}

//右移
std::istream& operator>>(std::istream& is, MArray& other)
{
	std::cout << "请输入" << other.getLen() << "个数" << std::endl;

	for (int i = 0; i < other.getLen(); i++)
	{
		is >> other[i];
	}

	return is;
}

//全局==重载
bool operator==(MArray& arr1, MArray& arr2)
{
	if (arr1.len != arr2.len)
	{
		return false;
	}

	for (int i = 0; i < arr1.len; i++)
	{
		if (arr1[i] != arr2[i])
		{
			return false;
		}
	}

	return true;
}
