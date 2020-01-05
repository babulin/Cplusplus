#pragma once
#include <iostream>
using namespace std;

template <class T>
class Person {
protected:
	T m_Age;
public:
	Person(T age);
	void Show();
};


