#include <iostream>
#include <stdexcept>

using namespace std;
//--------------------------------------
//�쳣��
class MyOutOfRange : public exception {
protected:
	char* pError;
public:
	MyOutOfRange(const char* error) {
		int len = strlen(error) + 1;
		pError = new char[len];
		strcpy_s(pError, len, error);
	}

	~MyOutOfRange() {
		if (pError != nullptr) {
			delete[] pError;
			pError = nullptr;
		}
	}

	virtual char const* what() const
	{
		return pError;
	}
};


//----------------------------
//��ͨ��
class Person {
protected:
	int mAge;
	int mHp;
public:
	Person() {
		mAge = 0;
		mHp = 0;
	}

	void setAge(int age) {
		if (age < 0 || age > 100){
			throw out_of_range("���������0~100֮�䣡");
		}

		mAge = age;
	}

	void setHp(int hp) {
		if (hp < 1 || hp > 1000) {
			throw MyOutOfRange("hp������1~1000֮�䣡");
		}

		mHp = hp;
	}
};



int main() {

	Person p;

	try{
		p.setAge(1000);
	}
	catch (exception e){
		cout << e.what() << endl;
	}


	try {
		p.setHp(10000);
	}
	catch (exception& e) {
		//����� exception e ��ͨ���� ������˿�������
		//���� exception& e
		cout << e.what() << endl;
	}
}