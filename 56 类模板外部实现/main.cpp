#include <iostream>
using namespace std;

template <class T>
class Person {
protected:
	T mId;
	T mAge;
public:
	Person(T id,T age);
	void show();

	//---------------------------------------------------
	//�������Ʋ����� �ǳ�Ա���� [ȫ�ֺ���ģ��]
	template <class T>
	friend ostream& operator<<(ostream& os, Person<T>& p);
};


//��ģ���ⲿʵ��
template <class TE>
Person<TE>::Person(TE id,TE age) {
	mId = id;
	mAge = age;
}

//��ָ����ģ��
template <class TE>
void Person<TE>::show() {
	cout << "id:" << mId << " age:" << mAge << endl;
}

//-----------------------------------------------------
//[ȫ�ֺ���ģ��] ��������ģ�庯��ʵ��
template <class T>
ostream& operator<<(ostream& os, Person<T>& p) {
	os << "id:" << p.mId << " age:" << p.mAge << endl;
	return os;
}

int main() {

	Person<int> p(10, 25);
	//p.show();
	cout << p;
}