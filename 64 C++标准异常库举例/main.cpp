#include <iostream>
#include <stdexcept>

using namespace std;
//--------------------------------------
//异常类
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
//普通类
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
			throw out_of_range("年龄必须在0~100之间！");
		}

		mAge = age;
	}

	void setHp(int hp) {
		if (hp < 1 || hp > 1000) {
			throw MyOutOfRange("hp必须在1~1000之间！");
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
		//如果是 exception e 普通对象 则调用了拷贝构造
		//引用 exception& e
		cout << e.what() << endl;
	}
}