#include "MyArray.h"

template <class T>
MyArray<T>::MyArray(int capacity){
	m_capacity = capacity;
	m_size = 0;

	//���ٿռ�
	p_addr = new T[m_capacity];
}

template<class T>
MyArray<T>::~MyArray(){

	if (p_addr != nullptr){
		delete[] p_addr;
	}
}

template<class T>
void MyArray<T>::push(T& data){
	
	//��ǰ�����Ƿ��Ѿ�������
	if (m_size >= m_capacity) {
		return;
	}

	p_addr[m_size] = data;
	m_size++;
}

template<class T>
T& MyArray<T>::operator[](int index)
{
	return p_addr[index];
}

