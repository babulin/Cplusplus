#include <iostream>
using namespace std;

class A {
private:
	int m_a;
	char name[64];
	char* desc;

public:
	//Ĭ���޲�������
	A() {
		m_a = 0;
		strcpy_s(name, "");//�ַ�������
		desc = new char[1];
		strcpy_s(desc, 1, "");
	}

	//�в������캯��
	A(int a,const char* name, const char* desc) {
		m_a = a;
		strcpy_s(this->name, name);

		int len = strlen(desc) + 1;//����һ�� \0 ��������
		this->desc = new char[len];
		strcpy_s(this->desc, len, desc);
	}

	//�������� [ָ�����]
	A(const A& other) {
		m_a = other.m_a;
		strcpy_s(this->name, other.name);

		int len = strlen(other.desc) + 1;//����һ�� \0 ��������
		this->desc = new char[len];
		strcpy_s(this->desc, len, other.desc);
	}

	//�ȺŲ��������� a3 = a2
	A& operator=(const A& other) {

		//��ֹ������
		if (this == &other)
		{
			//����һ��
			return *this;
		}

		//�������
		if (desc != NULL)
		{
			delete[] desc;
			desc = NULL;
			m_a = 0;
			strcpy_s(name, "");
		}

		//�ֵ
		m_a = other.m_a;
		strcpy_s(this->name, other.name);

		int len = strlen(other.desc) + 1;//����һ�� \0 ��������
		this->desc = new char[len];
		strcpy_s(this->desc, len, other.desc);

		return *this;
	}

	void show() {
		cout << "m_a = " << m_a << endl;
		cout << "name = " << name << endl;
		cout << "desc = " << desc << endl;
	}

	~A() {
		if (desc != NULL)
		{
			delete[] desc;
			desc = NULL;
		}
	}
};

int main() {
	A a1;
	a1.show();

	A a2(10, "����", "����һ������");
	a2.show();

	A a3 = a2;
	a3.show();

	//=�ŷ����� ���൱�ڸ�ֵ
	A a4(20,"����","ϲ���Ⱦ�");
	A a5(20,"����","����ϰ�");
	(a5 = a3) = a4;//���ص������� (a5 = a3) (a5 = a4)
	a4.show();

}