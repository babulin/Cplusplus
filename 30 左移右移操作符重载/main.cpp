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

	//a1 << cout;//���˱��� ��Ť [д��ȫ��]
	//a1.operator<<(cout); a1 << cout;�ͱ�Ť��
	//ostream& operator<<(ostream& os) {
	//	os << m_a << endl;
	//	return os;
	//}

};

//��Ԫ����
ostream& operator<<(ostream& os, A& a1) {
	os << a1.m_a << endl;
	return os;
}

//��Ԫ����
istream& operator>>(istream& is, A& a1) {
	cout << "m_a:";
	is >> a1.m_a;
	return is;
}

int main() {

	A a1(1);

	//���
	//cout << a1;//operator<<(cout,a1)
	//cout << a1 << a1 << a1;//operator<<(cout,a1)

	//a1 << cout;//���˱��� ��Ť [д��ȫ��]

	//����
	cin >> a1;
	cout << a1;
}