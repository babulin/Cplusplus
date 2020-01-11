#include <iostream>
using namespace std;

//初始化
void func1() {

	string str1;//调用无参构造
	cout << "string() =>" << str1 << endl;

	//重复构造10个a
	string str2(10,'a');
	cout << "string(int,char) => " << str2 << endl;

	//字符串构造
	string str3("abcdefg");
	cout << "string(char*) => " << str3 << endl;

	//拷贝构造
	string str4(str3);
	cout << "string(const string&) => " << str3 << endl;
}

//操作
void func2() {
	//=操作符
	string str1;
	string str2("abcde");
	
	//=操作符重载(char*类型)
	str1 = "hello";
	cout << "str1 => " << str1 << endl;

	//=操作符重载(string类型)
	str1 = str2;
	cout << "str1 => " << str1 << " str2 => " << str2 << endl;

	str1 = 'a';
	cout << "str1 => " << str1 << endl;
	
	//成员方法赋值
	str1.assign("jkkkkk");
	cout << "str1 => " << str1 << endl;
}

//取值操作
void func3() {
	string str1 = "abcde";
	
	//重载[]操作符
	for (int i = 0; i < str1.size(); i++)
	{
		//可直接通过[]下标取值
		cout << str1[i] << " ";
		str1[i] = str1[i] + 1;//将当前值往后移一个字母（ASCII）
	}
	cout << endl;

	//at()成员方法
	for (int i = 0; i < str1.size(); i++)
	{
		//可直接通过[]下标取值
		cout << str1.at(i) << " ";
	}
	cout << endl;

	//区别: at()访问越界抛out_of_range异常，[]访问越界直接挂掉
	try
	{
		//无法捕获
		//cout << str1[100] << endl;

		//抛出异常
		cout << str1.at(100) << endl;
	}
	catch (...)
	{
		cout << "数据越界了" << endl;
	}
}

//拼接操作
void func4() {

	//+=重载
	string str1 = "abcd";
	string str2 = "efgh";
	//+= string 对象
	str1 += str2;
	//+= char* 字符串
	str1 += "ijk";
	//+= char 字符
	str1 += 'l';

	cout << "str1 => " << str1 << endl;
	
	//成员方法追加
	string str3 = "12345";
	str1.append(str3);
	str1.append("678");
	cout << "str1 => " << str1 << endl;
}

//字符串查找
void func5() {
	string str1 = "adekfgiofgoke";
	//从前往后查找
	int pos = str1.find("fg");
	cout << "pos => " << pos << endl;

	//从后往前找
	pos = str1.rfind("fg");
	cout << "pos => " << pos << endl;

}

//字符串替换
void func6() {
	string str1 = "abcdefg";

	//替换
	str1.replace(0, 2, "123");
	cout << "str1 => " << str1 << endl;

}

//字符串比较
void func7() {
	string str1 = "abcd";
	string str2 = "abce";

	//s1 > s2 返回 1；s1 < s2 返回 -1  相等 返回 0
	if (str1.compare(str2) == 0)
	{
		cout << "字符串相等!" << endl;
	}
	else {
		cout << "字符串不相等!" << endl;
	}
}

//截取字符串
void func8() {
	string str1 = "abcdefg";

	//截取
	string str2 = str1.substr(1, 3);
	cout << "str2 => " << str2 << endl;
}

//插入和删除
void func9() {
	string str1 = "abcdefg";

	//插入数据
	str1.insert(3, "111");
	cout << "str1.insert(3, \"111\") => " << str1 << endl;

	//删除字符串
	str1.erase(0, 2);
	cout << "str1.erase(0, 2) => " << str1 << endl;

}

int main() {
	//func1();
	//func2();
	//func3();
	//func4();
	//func5();
	//func6();
	//func7();
	//func8();
	func9();

	//p44;
}