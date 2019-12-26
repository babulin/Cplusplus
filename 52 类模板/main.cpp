#include <iostream>
using namespace std;

template <typename T>
class Person {
protected:
	T mAge;
	T mSex;

public:
	Person(T age,T sex):mAge(age),mSex(sex) {

	}

	void show() {
		cout << "age = " << mAge << " sex = " << mSex << endl;
	}
};


int main() {

	//int
	Person<int> person(21, 1);
	person.show();

	//string
	string age = "25Ëê";
	string sex = "ÄÐ";
	Person<string> person2(age, sex);
	person2.show();
}