#pragma once
#include <iostream>
using namespace std;

class MString
{
	//����<<
	friend ostream& operator<<(ostream& os, MString& str);
	//����>>
	friend istream& operator>>(istream& is, MString& str);
private:
	char* string;
public:
	MString();
	MString(const char* str);
	MString(const MString& str);
	//����[]
	char& operator[](int index);
	//����=
	MString& operator=(MString & str);
	//����+
	MString operator+(MString& str);
	~MString();
};

