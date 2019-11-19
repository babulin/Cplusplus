#include <iostream>
using namespace std;

class A {
	friend ostream& operator<<(ostream& os, A& a1);
	friend istream& operator>>(istream& is, A& a1);
private:
	int m_a;
public:
	A(int a) {
		m_a = a;
	}

	//a1 << cout;//变了本意 别扭 [写在全局]
	//a1.operator<<(cout); a1 << cout;就别扭了
	//ostream& operator<<(ostream& os) {
	//	os << m_a << endl;
	//	return os;
	//}

};

//友元函数
ostream& operator<<(ostream& os, A& a1) {
	os << a1.m_a << endl;
	return os;
}

//友元函数
istream& operator>>(istream& is, A& a1) {
	cout << "m_a:";
	is >> a1.m_a;
	return is;
}

int main() {

	A a1(1);

	//输出
	//cout << a1;//operator<<(cout,a1)
	//cout << a1 << a1 << a1;//operator<<(cout,a1)

	//a1 << cout;//变了本意 别扭 [写在全局]

	//输入
	cin >> a1;
	cout << a1;
}