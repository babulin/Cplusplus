#include <iostream>
using namespace std;

//����򵥵���
class Parent {
public:
	int a;
public:
	Parent(int a) {
		this->a = a;
	}

	virtual void show() {
		cout << "Parent::show() a = " << a << endl;
	}
};

//����̳и��� 
class Child : public Parent {
public:
	//���ӱ���
	int b;
public:
	Child(int a) :Parent(a) {

	}
	virtual void show() {
		cout << "Child::show() a = " << a << endl;
	}
};

int main() {
	
	//��ʱ����ռ�������ռ�һ����
	cout << "sizeof(Parent) = " << sizeof(Parent) << endl;
	cout << "sizeof(Child) = " << sizeof(Child) << endl;

	cout << "--------------------------" << endl;

	//����һ�������������
	Child carr[] = { Child(0),Child(1), Child(2) };

	//����ָ��ָ�������������
	Child* pc = carr;
	for (int i = 0; i < 3; i++)
	{
		//����������д�ĺ���
		pc->show();
		pc++;
	}

#if 0
	//����ָ��ָ�������������
	Parent* pp = carr;
	for (int i = 0; i < 3; i++)
	{
		//����������д�ĺ���
		pp->show();
		pp++;
	}

	//��ʱ��Ϊ������ռ� = ����ռ� ���� pp++ �� pp + = sizeof(Parent); pp+=8;
	//�������ռ��븸�಻һ�����Ͳ����ø���ָ��������������
#endif // 0

	cout << "--------------------------" << endl;

}