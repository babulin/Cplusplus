#pragma once

template <class T>
class MyArray {
protected:
	int m_size;//当前数组大小
	int m_capacity;//当前数组最大容量
	T* p_addr;//容器地址指针 T类型
public:
	//构造函数
	MyArray(int capacity);
	//析构函数
	~MyArray();

	//增加数据
	void push(T& data);

	//返回大小
	int getSize() {
		return m_size;
	}

	//重写[]操作符
	T& operator[](int index);
};
