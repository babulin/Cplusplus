#include "Animal.h"
/**
 * ���캯��
 */
Animal::Animal(string name, int hp) {
	mName = name;
	mHp = hp;
}

/**
 * ��������
 */
Animal::~Animal() {

}

void Animal::show() {
    cout << "name = " << mName << " hp = " << mHp << endl;
}