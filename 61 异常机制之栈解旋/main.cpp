#include <iostream>
using namespace std;

class Person {
public:
	Person() {
		cout << "���캯��~!" << endl;
	}
	~Person() {
		cout << "��������~!" << endl;
	}
};


int func1(int a, int b) {

	//�������쳣ʱ���Զ�����
	Person p1, p2;

	if (b == 0)
	{
		throw b;
	}

	return a / b;
}

int main() {
	try
	{
		//ջ����
		//try ������ִ�еľֲ��������ᱻ�ͷŵ�
		func1(10, 0);
	}
	catch (int e)
	{
		cout << "�쳣�ѱ�����" << endl;
	}

	cout << "���Ǻ���Ĵ���" << endl;
}