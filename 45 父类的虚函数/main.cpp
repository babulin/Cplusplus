#include <iostream>
#include <string>
using namespace std;

//����������
class Animal {
private:
protected:
	string name;

public:

	Animal(string _name) {
		name = _name;
		cout << "Animal()" << endl;
	}

	//������virtual���Σ���ʾ�麯������������д
	virtual void run() {
		cout << name << "��ʼ����[������]" << endl;
	}

	//virtual ��������������������д�����ȵ������������
	virtual ~Animal() {
		cout << "~Animal()" << endl;
	}
};

//��
class Dog :public Animal{
private:

public:
	Dog(string _name) :Animal(_name) {
		cout << "Dog()" << endl;
	}

	//���� virtual ���ӿɶ��ԣ���ʾ�Ӹ�����д
	virtual void run() {
		cout << name << "��ʼ����[����]" << endl;
	}

	virtual ~Dog() {
		cout << "~Dog()" << endl;
	}
};

//è
class Cat :public Animal {
private:

public:
	Cat(string _name) :Animal(_name) {
		cout << "Cat()" << endl;
	}

	virtual void run() {
		cout << name << "��ʼ����[è��]" << endl;
	}

	virtual ~Cat() {
		cout << "~Cat()" << endl;
	}
};

//����ָ������� ָ���������ʱ �����麯�������ñ�������д�ĺ���
void doRun(Animal* animal) {
	//��̬����[���ݲ�ͬ�Ķ�����е��ú���]
	animal->run();

	delete animal;//�������������������������  [~Dog()->~Animal(),����Ĭ�ϻ��������Լ����ٵ��ø�������]
}

int main() {

	//Animal* animal = new Animal("����");

	Dog* dog = new Dog("С��");
	//dog->run();
	//Cat* cat = new Cat("С��");
	//cat->run();

	//ͨ��������Ϊ�β� ����ʵ��
	//doRun(animal);
	doRun(dog);
	//doRun(cat);

	//delete animal;
	//delete dog;
	//delete cat;

	//�ܽ᣺��̬��3������
	//[1]�̳�
	//[2]�麯����д
	//[3]����ָ������� �Ӷ���


	//���أ���д���ض���
	//���أ���ͬ�������� ������һ�£�������һ��
	//��д��������д���� �麯��
	//�ض��壺������ͨ�����͸�����ͨ����һ�� 
}