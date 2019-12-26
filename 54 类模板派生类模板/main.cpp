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

//类模板继承类模板
template <class T>
class Dog : public Animal<T> {
public:
	Dog(T hp):Animal<T>(hp) {

	}
};

int main() {

	Dog<int> dog(1000);
	dog.show();

	string hp = "100w";
	Dog<string> dog1(hp);
	dog1.show();
}