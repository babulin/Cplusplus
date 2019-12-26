#pragma once
#include <iostream>
#include <string>
using namespace std;


class Animal {

protected:
	int mHp;
	string mName;

public:
	Animal(string name,int hp);
	~Animal();
	void show();
};