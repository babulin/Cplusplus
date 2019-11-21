#include "MString.h"

MString::MString()
{
	string = nullptr;
}

MString::MString(const char* str)
{
	if (str == nullptr)
	{
		string = new char[0 + 1];
		strcpy_s(string, 1, str);
	}
	else {
		int len = strlen(str) + 1;
		string = new char[len];
		strcpy_s(string, len, str);
	}
}

//拷贝构造函数不用回收垃圾，因为是初始化时
MString::MString(const MString& str)
{
	int len = strlen(str.string) + 1;
	string = new char[len];
	strcpy_s(string, len, str.string);
}

//char& 是因为赋值 char* string 实际上类似char str[] 数组
char& MString::operator[](int index)
{
	return string[index];
}

//=号赋值重载
MString& MString::operator=(MString& str)
{
	//排除本身赋值
	if (this == &str)
	{
		return *this;
	}

	//回收垃圾
	if (string != nullptr)
	{
		delete[] string;
		string = nullptr;
	}

	//开辟空间
	int len = strlen(str.string) + 1;//因为strlen算字符串有效长度 有个\0
	string = new char[len];
	strcpy_s(string, len, str.string);

	return *this;
}

//重载+ 这里s1 + s2 对象本身不改变
MString MString::operator+(MString& str)
{
	MString temp;
	//计算总长度
	int len = strlen(string) + strlen(str.string) + 1;
	//开辟空间
	temp.string = new char[len];

	//[注意：strcat 对新开辟的空间有可能存在数据，添加导致报错]
	//尾部添加字符串
	//memset(temp.string, 0, len);
	//strcat_s(temp.string, len, string);

	//拷贝字符串
	strcpy_s(temp.string, len, string);
	//尾部继续添加 
	strcat_s(temp.string, len, str.string);

	return temp;
}

MString::~MString()
{
	if (string != nullptr)
	{
		delete[] string;
		string = nullptr;
	}

	cout << "~MString()执行了析构" << endl;
}

//友元函数
ostream& operator<<(ostream& os, MString& str)
{
	os << str.string;
	return os;
}

istream& operator>>(istream& is, MString& str)
{
	//1 清除str空间
	if (str.string != nullptr)
	{
		delete[] str.string;
		str.string = nullptr;
	}
	//2 添加临时变量
	char temp_str[4096] = { 0 };
	cin >> temp_str;

	//3 深拷贝
	int len = strlen(temp_str) + 1;
	str.string = new char[len];
	strcpy_s(str.string, len, temp_str);

	return is;
}
