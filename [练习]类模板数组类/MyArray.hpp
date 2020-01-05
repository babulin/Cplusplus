#include "MyArray.h"

template <class T>
MyArray<T>::MyArray(int capacity){
	m_capacity = capacity;
	m_size = 0;

	//开辟空间
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
	
	//当前容器是否已经满负荷
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

