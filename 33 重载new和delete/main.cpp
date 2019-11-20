#include <iostream>
using namespace std;

class A {
private:
	int m_a;
public:
	A() {
		cout << "A() ���캯��" << endl;
		m_a = 0;
	}

	A(int a) {
		cout << "A(int a) ���캯��" << endl;
		m_a = a;
	}

	//����new ��ʵ�ǿ��ٿռ��С ��������ָ��
	void * operator new(size_t size) {
		cout << "������new����" << endl;
 		return malloc(size);
	}

	//����new[] ����ʹ�õ�malloc �ռ��С
	void* operator new[](size_t size) {
		cout << "������new����" << endl;
		return malloc(size);
	}

	//����delete ��ʵ�ǿ��ٿռ��С ��������ָ��
	void operator delete(void * p) {
		cout << "������delete����" << endl;
		if (p != NULL)
		{
			free(p);
			p = NULL;
		}
	}

	//����delete ��ʵ�ǿ��ٿռ��С ��������ָ��
	void operator delete[](void* p) {
		cout << "������delete����" << endl;
		if (p != NULL)
		{
			free(p);
			p = NULL;
		}
	}

	~A() {
		cout << "~A() ��������" << endl;
	}
};


int main() {

	//�ܽ᣺ ����new���� -> ���캯�� -> �������� -> ����delete������

	A* a3 = new A[5];//a3->operator new[](sizeof(A[5]));A[5] ��С
	delete[] a3;
	

	//���ȵ����أ��ڵ�����
	A* a2 = new A(5);//a2->operator new(sizeof(A)); A�Ĵ�С
	delete a2;
}