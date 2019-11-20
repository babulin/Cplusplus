#pragma once
#include <iostream>

class MArray {
	friend std::ostream& operator<<(std::ostream& os, const MArray& other);
	friend std::istream& operator>>(std::istream& is, MArray& other);
	friend bool operator==(MArray& arr1,MArray& arr2);
private:
	int len;
	int* space;

public:
	MArray();
	MArray(int len);
	MArray(const MArray& other);
	~MArray();

	void setData(int index, int data);
	int getData(int index);
	int getLen() const;//限定this 为 const MArray* this
	MArray& operator=(const MArray& other);//操作符重载 = 号

	int& operator[](int index)const;//就是调用该方法的必须是 const MArray other;对象

	bool operator!=(MArray& arr2);
};
