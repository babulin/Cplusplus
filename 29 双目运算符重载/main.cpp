#include <iostream>
using namespace std;

class A {

private:
	int m_a;

public:
	A(int a) {
		m_a = a;
	}

	//���Ҫ���� �ͷ������ã���Ϊ�����þ�����������
	A& operator-=(A& a) {
		m_a -= a.m_a;
		return *this;
	}

	A& operator+=(A& a) {
		m_a += a.m_a;
		return *this;
	}

	//Ĭ����ǰ++   ++a
	A& operator++() {
		m_a++;
		return *this;
	}

	//���صĺ�++   a++
	const A operator++(int) {
		m_a++;
		return *this;
	}

	//Ĭ����ǰ--   --a
	A& operator--() {
		m_a--;
		return *this;
	}

	//���صĺ�--   a--
	const A operator--(int) {
		m_a--;
		return *this;
	}

	void show() {
		cout << "m_a = " << m_a << endl;
	}


};

int main() {

	A a1(1);
	A a2(5);

	//��Ȼ���ȼ���+= -= �����������ȼ�
	//(a1 += a2) += a2;
	//a1.show();

	//(a1 -= a2) -= a2; //1-5-5 
	//a1.show();

	//++
	int a = 10;
	++a;//����
	++++a;//����
	a++;//����
	//a++++;//������ 

	//++a1;
	//a1.show();

	//a1++++;
	//a1.show();

	//ʵ��a++++ �����Եķ�ʽ
	//a1++;
	//a1.show();

	--a1;
	(--a1).show();

	a1--;
	a1.show();
}