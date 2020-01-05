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
		cout << "Person() 无参构造" << endl;
		m_name = "";
		m_hp = 0;
		m_verson = nullptr;
	};
	Person(string name,int hp, const char* verson):m_name(name), m_hp(hp) {
		cout << "Person() 有参构造" << endl;
		//开辟空间
		int len = strlen(verson) + 1;
		m_verson = (char*)malloc(len);
		strcpy_s(m_verson, len, verson);
	}

	~Person() {
		cout << "版本：" << m_verson << "~Person()析构函数" << endl;
		if (m_verson != nullptr){
			free(m_verson);
			m_verson = nullptr;
		}
	}

	void show() {
		cout << "版本："<< m_verson <<" m_name:" << m_name << " m_hp:" << m_hp << endl;
	}

	Person(const Person& p) {
		m_name = p.m_name;
		m_hp = p.m_hp;

		//开辟空间
		int len = strlen(p.m_verson) + 1;
		m_verson = (char*)malloc(len);
		strcpy_s(m_verson, len, p.m_verson);

		cout << "版本：" << m_verson << "Person() 拷贝函数" << endl;
	}

	Person& operator=(const Person &p) {
		
		if (m_verson != nullptr)
		{
			free(m_verson);
			m_verson = nullptr;
		}

		m_name = p.m_name;
		m_hp = p.m_hp;

		//开辟空间
		int len = strlen(p.m_verson) + 1;
		m_verson = (char*)malloc(len);
		strcpy_s(m_verson, len, p.m_verson);

		cout << "m_name:" << p.m_name << "= 操作符" << endl;

		return *this;
	}
};


int main() {

	Person p1("战士", 2000, "v1.0.0");
	Person p2("法师", 1200, "v1.0.1");

	//Person * pp = new Person[2];
	//pp[0] = p1;
	//pp[1] = p2;

	//delete[] pp;

	//申请一个装person类型的5个大小容器
	//【注意】对象数组开辟时则开辟了内存空间
	MyArray<Person> mArr(2);

	//因为push内部 使用 = 号，那么调用了T => Person 的=操作符重写
	//注意：意味着必须能被拷贝
	mArr.push(p1);
	mArr.push(p2);

	//遍历
	for (int i = 0; i < mArr.getSize(); i++)
	{
		mArr[i].show();
	}
#if 0


	//5个大小容器
	MyArray<int> mArr(5);

	mArr.push(1);
	mArr.push(2);
	mArr.push(3);

	//遍历
	for (int i = 0; i < mArr.getSize(); i++)
	{
		cout << mArr[i] << endl;
	}
#endif // 0

	return 0;
}