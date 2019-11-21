#pragma once
#include <iostream>
using namespace std;

class MString
{
	//重载<<
	friend ostream& operator<<(ostream& os, MString& str);
	//重载>>
	friend istream& operator>>(istream& is, MString& str);
private:
	char* string;
public:
	MString();
	MString(const char* str);
	MString(const MString& str);
	//重载[]
	char& operator[](int index);
	//重载=
	MString& operator=(MString & str);
	//重载+
	MString operator+(MString& str);
	~MString();
};

