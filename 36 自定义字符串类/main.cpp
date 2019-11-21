#include <iostream>
#include <string>
#include "MString.h"
using namespace std;

int main() {

	string str1 = "abcd1234";
	string str2 = "abc";

	//加法
	//cout << "+ " << str1 + str2 << endl;

	//=号
	//cout << "= " << (str1 = str2) << endl;
#if 0
	//自定义类
	MString s1("abc");
	MString s2(s1);
	MString s3 = "ABC";

	//cout<<
	cout << s1 << endl;
	cout << s2 << endl;
	//[]
	s1[0] = 'A';
	cout << s1 << endl;
	//=
	s3 = s1;
	cout << s3 << endl;
	//cin>>
	MString s4 = "abc";
	cin >> s4;
	cout << s4 << endl;
#endif // 0
	//+
	MString s5 = "abc";
	MString s6 = "123";
	MString s7 = s5 + s6;
	cout << s7 << endl;
	cout << s5 << endl;
	cout << s6 << endl;

}