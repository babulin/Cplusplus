#include <iostream>
using namespace std;




class Dog {
public:
	char name[64];
	
	//�������
	void eat(const char* food) {
		cout << name << "��" << food << endl;
	}

};

//������� 
void eat(Dog& dog,const char* food) {
	cout << dog.name << "��" << food << endl;
}

int main(){

	Dog dog;
	strcpy_s(dog.name, "��");

	//�������
	dog.eat("��");

	//�������
	eat(dog, "��");


	cin.get();
	return 0;
}