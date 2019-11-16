#include <iostream>
using namespace std;




class Dog {
public:
	char name[64];
	
	//面向对象
	void eat(const char* food) {
		cout << name << "吃" << food << endl;
	}

};

//面向过程 
void eat(Dog& dog,const char* food) {
	cout << dog.name << "吃" << food << endl;
}

int main(){

	Dog dog;
	strcpy_s(dog.name, "狗");

	//面向对象
	dog.eat("翔");

	//面向过程
	eat(dog, "翔");


	cin.get();
	return 0;
}