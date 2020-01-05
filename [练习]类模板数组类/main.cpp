#include <iostream>
#include "MyArray.hpp"
using namespace std;

class Person {
protected:
	char* m_verson;
	string m_name;
	int m_hp;
public:
	Person() {
		cout << "Person() �޲ι���" << endl;
		m_name = "";
		m_hp = 0;
		m_verson = nullptr;
	};
	Person(string name,int hp, const char* verson):m_name(name), m_hp(hp) {
		cout << "Person() �вι���" << endl;
		//���ٿռ�
		int len = strlen(verson) + 1;
		m_verson = (char*)malloc(len);
		strcpy_s(m_verson, len, verson);
	}

	~Person() {
		cout << "�汾��" << m_verson << "~Person()��������" << endl;
		if (m_verson != nullptr){
			free(m_verson);
			m_verson = nullptr;
		}
	}

	void show() {
		cout << "�汾��"<< m_verson <<" m_name:" << m_name << " m_hp:" << m_hp << endl;
	}

	Person(const Person& p) {
		m_name = p.m_name;
		m_hp = p.m_hp;

		//���ٿռ�
		int len = strlen(p.m_verson) + 1;
		m_verson = (char*)malloc(len);
		strcpy_s(m_verson, len, p.m_verson);

		cout << "�汾��" << m_verson << "Person() ��������" << endl;
	}

	Person& operator=(const Person &p) {
		
		if (m_verson != nullptr)
		{
			free(m_verson);
			m_verson = nullptr;
		}

		m_name = p.m_name;
		m_hp = p.m_hp;

		//���ٿռ�
		int len = strlen(p.m_verson) + 1;
		m_verson = (char*)malloc(len);
		strcpy_s(m_verson, len, p.m_verson);

		cout << "m_name:" << p.m_name << "= ������" << endl;

		return *this;
	}
};


int main() {

	Person p1("սʿ", 2000, "v1.0.0");
	Person p2("��ʦ", 1200, "v1.0.1");

	//Person * pp = new Person[2];
	//pp[0] = p1;
	//pp[1] = p2;

	//delete[] pp;

	//����һ��װperson���͵�5����С����
	//��ע�⡿�������鿪��ʱ�򿪱����ڴ�ռ�
	MyArray<Person> mArr(2);

	//��Ϊpush�ڲ� ʹ�� = �ţ���ô������T => Person ��=��������д
	//ע�⣺��ζ�ű����ܱ�����
	mArr.push(p1);
	mArr.push(p2);

	//����
	for (int i = 0; i < mArr.getSize(); i++)
	{
		mArr[i].show();
	}
#if 0


	//5����С����
	MyArray<int> mArr(5);

	mArr.push(1);
	mArr.push(2);
	mArr.push(3);

	//����
	for (int i = 0; i < mArr.getSize(); i++)
	{
		cout << mArr[i] << endl;
	}
#endif // 0

	return 0;
}