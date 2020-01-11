#include <iostream>
#include <iomanip>
using namespace std;

//cin.get()
//从缓冲区读取一个字符
void func1() {
	char ch;

	//循环每次从缓冲区拿一个字符
	//EOF = ctrl+z
	//while ((ch = cin.get()) != EOF)
	//{
	//	cout << ch << endl;
	//}

	//读取一个字符
	ch = cin.get();
	cout << "cin.get() => " << ch << endl;

	cin.get(ch);
	cout <<"cin.get(ch) => "<< ch << endl;

	//读取256 字符串
	char buf[256] = { 0 };
	cin.get(buf, 256);
	cout << "cin.get(buf, 256) => " << buf << endl;
}

//cin.getline()
//从缓冲区读取一行 不读取 '\n'
void func2() {
	char buf[256] = { 0 };
	cin.getline(buf,256);
	cout << "cin.getline(buf,256) => " << buf << endl;//不读取 \n
}

//cin.ignore()
//忽略缓冲区一个字符 
void func3() {
	char ch;

	ch = cin.get();
	cout <<"cin.get() => "<< ch << endl;

	//cin.ignore();//忽略一个字符 abcd
	//cin.ignore(2);//忽略2个字符
	cin.ignore(10, '\n');//忽略10个之前遇到 \n 提前结束

	ch = cin.get();
	cout << "cin.get() => " << ch << endl;
}

//cin.peek()
//查看缓冲区1个字符串
void func4() {
	char ch;
	ch = cin.peek();//偷窥一个字符 abcd
	if (ch >= '0' && ch <= '9')
	{
		int number;
		cin >> number;
		cout << "您输入的是数字:" << number << endl;
	}
	else {
		char buf[256] = { 0 };
		cin >> buf;
		cout << "您输入的是字符串:" << buf << endl;
	}
}

//cin.putback()
//放回缓冲区当前位置
void func5() {

	char ch;
	ch = cin.get();

	if (ch >= '0' && ch <= '9') {
		//放回缓冲区当前位置
		cin.putback(ch);
		int number;
		cin >> number;
		cout << "您输入的是数字:" << number << endl;
	}
	else {
		//放回缓冲区当前位置
		cin.putback(ch);
		char buf[256] = { 0 };
		cin >> buf;
		cout << "您输入的是字符串:" << buf << endl;
	}
}

//标准输出流
void func() {

	cout << "cout.flush() => 刷新缓冲区" << endl;
	//cout.flush();

	cout << "cout.put('H').put('e') => 输出字符 ";
	cout.put('H').put('e').put('l').put('l').put('o') << endl;

	//格式化输出
	int number = 15;

	cout.setf(ios::showbase);//输出基本格式

	//8进制输出
	cout.unsetf(ios::dec);//卸载10进制
	cout.setf(ios::oct);//使用8进制
	cout << number << endl;

	//16进制输出
	cout.unsetf(ios::oct);//卸载8进制
	cout.setf(ios::hex);//16进制
	cout << number << endl;

	//格式位
	cout.width(10);//宽度
	cout.fill('*');//不足位填充
	cout.setf(ios::left);//对齐方式
	cout << number << endl;


	//通过控制符
	int number1 = 14;

	cout << hex //16进制
		<< setiosflags(ios::showbase) //显示基础格式
		<< setw(10)	//宽度
		<< setfill('*') //补充位
		<< setiosflags(ios::left) //对齐方式
		<< number1
		<< endl;


}

int main() {
	//func1();
	//func2();
	//func3();
	//func4();
	//func5();
	func();
}