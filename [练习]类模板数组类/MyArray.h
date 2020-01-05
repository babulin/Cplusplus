#pragma once

template <class T>
class MyArray {
protected:
	int m_size;//��ǰ�����С
	int m_capacity;//��ǰ�����������
	T* p_addr;//������ַָ�� T����
public:
	//���캯��
	MyArray(int capacity);
	//��������
	~MyArray();

	//��������
	void push(T& data);

	//���ش�С
	int getSize() {
		return m_size;
	}

	//��д[]������
	T& operator[](int index);
};
