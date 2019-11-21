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

//�������캯�����û�����������Ϊ�ǳ�ʼ��ʱ
MString::MString(const MString& str)
{
	int len = strlen(str.string) + 1;
	string = new char[len];
	strcpy_s(string, len, str.string);
}

//char& ����Ϊ��ֵ char* string ʵ��������char str[] ����
char& MString::operator[](int index)
{
	return string[index];
}

//=�Ÿ�ֵ����
MString& MString::operator=(MString& str)
{
	//�ų�����ֵ
	if (this == &str)
	{
		return *this;
	}

	//��������
	if (string != nullptr)
	{
		delete[] string;
		string = nullptr;
	}

	//���ٿռ�
	int len = strlen(str.string) + 1;//��Ϊstrlen���ַ�����Ч���� �и�\0
	string = new char[len];
	strcpy_s(string, len, str.string);

	return *this;
}

//����+ ����s1 + s2 �������ı�
MString MString::operator+(MString& str)
{
	MString temp;
	//�����ܳ���
	int len = strlen(string) + strlen(str.string) + 1;
	//���ٿռ�
	temp.string = new char[len];

	//[ע�⣺strcat ���¿��ٵĿռ��п��ܴ������ݣ���ӵ��±���]
	//β������ַ���
	//memset(temp.string, 0, len);
	//strcat_s(temp.string, len, string);

	//�����ַ���
	strcpy_s(temp.string, len, string);
	//β��������� 
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

	cout << "~MString()ִ��������" << endl;
}

//��Ԫ����
ostream& operator<<(ostream& os, MString& str)
{
	os << str.string;
	return os;
}

istream& operator>>(istream& is, MString& str)
{
	//1 ���str�ռ�
	if (str.string != nullptr)
	{
		delete[] str.string;
		str.string = nullptr;
	}
	//2 �����ʱ����
	char temp_str[4096] = { 0 };
	cin >> temp_str;

	//3 ���
	int len = strlen(temp_str) + 1;
	str.string = new char[len];
	strcpy_s(str.string, len, temp_str);

	return is;
}
