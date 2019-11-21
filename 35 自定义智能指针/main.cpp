#include <iostream>
#include <memory>//����ָ��ͷ�ļ�
using namespace std;

class A
{
public:
	A(int a){
		m_a = a;
		cout << "A()���캯��" << endl;
	}

	void show() {
		cout << "m_a = " << m_a << endl;
	}


	~A()
	{
		cout << "~A()��������" << endl;
	}

private:
	int m_a;
};

//�Զ�������ָ����
class MAutoPtr {
private:
	A* ptr;
public:
	MAutoPtr(A *pA) {
		ptr = pA; //�൱���ǰѶ����ַ ���� ptr������
	}

	//�ع� ��ĳ���������
	A* operator->() {
		return ptr;
	}

	//�ع� ��ĳ���������
	A& operator*() {
		return *ptr;
	}

	~MAutoPtr() {
		if (ptr != NULL)
		{
			delete ptr;
			ptr = NULL;
		}
	}
};



int main() {
	//��ָͨ��
	int* p = new int;
	delete p;

	//����ָ��[ģ��]
	auto_ptr<int> ptr(new int);
	*ptr = 20;//ʹ�� ����Ҫ�ͷţ��Զ��ͷ�


	//����ָͨ��
	A* a1 = new A(10);
	a1->show();
	(*a1).show();
	delete a1;

	//������ָ��
	auto_ptr<A> pa(new A(20));
	pa->show();
	(*pa).show();
	//����Ҫ�����ͷ�

	//�Զ�������ָ����
	MAutoPtr mPa(new A(100));
	mPa->show();
	(*mPa).show();

	return 0;
}