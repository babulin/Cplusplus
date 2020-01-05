#include "Person.h"

template<class T>
Person<T>::Person(T age){
	this->m_Age = age;
}

template<class T>
void Person<T>::Show(){
	cout << "ÄêÁä£º" <<this->m_Age << endl;
}
