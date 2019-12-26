#include "Animal.h"
/**
 * 构造函数
 */
Animal::Animal(string name, int hp) {
	mName = name;
	mHp = hp;
}

/**
 * 析构函数
 */
Animal::~Animal() {

}

void Animal::show() {
    cout << "name = " << mName << " hp = " << mHp << endl;
}