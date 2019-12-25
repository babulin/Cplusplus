#include <iostream>
using namespace std;

template <class T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
	cout << "����mySwap����ģ��" << endl;
}

template <class T>
void mySwap(T& a) {
	T temp = a;
	cout << "����mySwap����ģ�� ����" << "temp = " << temp << endl;
}

//��ͨ�������������Զ�ת��
void mySwap(int a,char ch) {
	int num = a + ch;
	cout << "����mySwap(int,char)��ͨ����" << " num = " << num << endl;
}

//��ͨ�������������Զ�ת��
void mySwap(int a, int b) {
	int num = a + b;
	cout << "����mySwap(int,int)��ͨ����" << " num = " << num << endl;
}


int main() {
	
#if 0
	//[1]�Զ������Ƶ�
	//int ����
	int a = 10;
	int b = 20;
	cout << "a = " << a << " b = " << b << endl;
	mySwap(a, b); //�Զ������Ƶ�
	cout << "a = " << a << " b = " << b << endl;

	//float ����
	float a1 = 10.5f;
	float b1 = 20.5f;
	cout << "a = " << a1 << " b = " << b1 << endl;
	mySwap(a1, b1);//�Զ������Ƶ�
	cout << "a = " << a1 << " b = " << b1 << endl;

	//[2]��ʽָ������
	char ch1 = 'A';
	char ch2 = 'B';
	cout << "ch1 = " << ch1 << " ch2 = " << ch2 << endl;
	mySwap<char>(ch1, ch2);//��ʽ����
	cout << "ch1 = " << ch1 << " ch2 = " << ch2 << endl;
#endif // 0

#if 0
	//ע��
	//��ͨ�������Զ�����ת����int ���ͣ����Դ�char���ͣ��Զ�ת��
	//����ģ�壺��������ƥ��
	int ia = 10;
	int ib = 20;
	char ca = 'A';
	char cb = 'B';

	//int char
	mySwap(ia, ca);//���� mySwap(int a,char ch) ��ͨ����

	//int int
	mySwap(ia, ib);//���� mySwap(int a,char ch) ����ģ��

	//char int
	mySwap(ca, ib);//���� mySwap(int a,char ch) ��ͨģ�� [char �Զ�ת���� int]
#endif // 0

#if 0
	//����ģ���������
	int aa = 10;
	int bb = 20;

	//����ģ��
	mySwap(aa, bb);

	//����ģ������
	mySwap(aa);
#endif // 0


	int a = 10;
	int b = 20;
	//���ȿ���ƥ����ͨ����
	mySwap(a, b);

	//����ǿ��ָ������ģ��
	mySwap<int>(a, b);

	float f1 = 10.5f;
	float f2 = 20.5f;
	mySwap(f1, f2);
}