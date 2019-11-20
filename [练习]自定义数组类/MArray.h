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
	int getLen() const;//�޶�this Ϊ const MArray* this
	MArray& operator=(const MArray& other);//���������� = ��

	int& operator[](int index)const;//���ǵ��ø÷����ı����� const MArray other;����

	bool operator!=(MArray& arr2);
};
