#include <iostream>
using namespace std;

template <class T>
class Animal {
protected:
	T mHp;
public:
	Animal(T hp) {
		mHp = hp;
	}

	void show() {
		cout << "hp = " << mHp << endl;
	}
};

//��ͨ��̳���ģ��
class Dog : public Animal<int> {
public:
	Dog(int hp):Animal(hp) {

	}
};

int main() {
	Dog dog(10);

	dog.show();
}