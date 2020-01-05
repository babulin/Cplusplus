#include <iostream>
using namespace std;

class A{};
class B{};
class C :public B{};


//�������ͣ��̳й�ϵ�Ķ���ָ�������
void _static_cast() {
	//-----------------------------
	// static_cast<T>()
	//[1]��ͨ����ת��
	int a = 97;
	char ch = static_cast<char>(a);

	cout << "[1] int����ת��Ϊchar ch = " << ch << endl;

	//------------------------------
	//������ָ��ת��Ϊ����ָ��
	B* opB = NULL;
	C* opC = static_cast<C*>(opB);

	//������ָ��ת��Ϊ����ָ��
	C* opC1 = NULL;
	B* opB1 = static_cast<B*>(opC1);

	//------------------------------
	//����������ת��Ϊ��������
	B oB;
	B& oB1 = oB;
	C& oC = static_cast<C&>(oB1);

	//����������ת��Ϊ��������
	C oC1;
	C& oC2 = oC1;
	B& oB2 = static_cast<B&>(oC2);

	//[����]static_cast ��ת�� �������ͣ����м̳й�ϵ�����ָ�룬�ͼ̳й�ϵ���������
}

//���м̳й�ϵ��ָ���������
//ת��ʱ���� ��ȫ���
void _dynamic_cast() {

	//ֻ�ܽ�����ת���ɸ����ָ���������
	//------------------------------
	C* opC = NULL;
	B* opB = dynamic_cast<B*>(opC);

	//------------------------------
	C oC;
	C& oC1 = oC;
	B& oB = dynamic_cast<B&>(oC1);

	//���ൽ���� ����С����ȫת����
}

//ָ�� ���� ���߶���ָ��
void _const_cast() {
	//��const���ñ���ת��Ϊ��ͨ��������
	int a = 10;
	const int& b = a;
	int& c = const_cast<int&>(b);
	c = 20;

	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;

	//-------------------------------
	//constָ��ת���� ��ָͨ��
	const int* p1 = &a;
	int* p2 = const_cast<int*>(p1);
	*p2 = 30;

	//��ָͨ�� ת���� constָ��
	const int* p3 = const_cast<const int*>(p2);

	cout << "p1:" << *p1 << endl;
	cout << "p2:" << *p2 << endl;
	cout << "p3:" << *p3 << endl;

	//-------------------------------
}


//ǿ������ת��
typedef void (*VFUNC)(int, int);
typedef int (*IFUNC)(int, char);

void doSomething(int a,int b) {
	cout << "����ʲô���߰��������" << "a:" << a << " b:" << b << endl;
}

//ǿ������ת��
void _reinterpret_cast() {
	//1.ָ������
	A* oA = nullptr;
	B* oB = reinterpret_cast<B*>(oA);

	//2.����ָ��
	VFUNC vfunc = doSomething;
	IFUNC ifunc = reinterpret_cast<IFUNC>(vfunc);

	ifunc(1, 'A');
}

int main() {

	//_const_cast();
	_reinterpret_cast();
	
}