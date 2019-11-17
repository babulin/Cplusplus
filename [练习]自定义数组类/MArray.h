#pragma once


class MArray {
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
	int getLen();
	void operator=(const MArray& other);//²Ù×÷·ûÖØÔØ = ºÅ
};