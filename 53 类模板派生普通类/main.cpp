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

//普通类继承类模板
class Dog : public Animal<int> {
public:
	Dog(int hp):Animal(hp) {

	}
};

int main() {
	Dog dog(10);

	dog.show();
}