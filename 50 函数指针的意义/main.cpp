#include <iostream>
using namespace std;

//����һ ��������:  ����ֵ () (�βθ��������ͣ�˳��)
typedef int(FUNC)(int,int);

//������ ����ָ��:
typedef int(*FUNC_P)(int, int);

//����
int func1(int a,int b) 
{
	cout << "func1" << endl;
	cout << "a = " << a << ",b = " << b << endl;
	return 0;
}

//����
int func2(int a, int b)
{
	cout << "func2" << endl;
	cout << "a + b = " << a + b << endl;
	return 0;
}

//����
int func3(int a, int b)
{
	cout << "func2" << endl;
	cout << "a * b = " << a * b << endl;
	return 0;
}

//����ָ��ӿ�
//void iFunc(int(*fp)(int, int),int a,int b) {
void iFunc(FUNC * fp,int a,int b) {
	cout << "�̶�ҵ��1" << endl;
	fp(a, b);
	cout << "�̶�ҵ��2" << endl;
}

int main() {

	//����һ
	FUNC* fp1 = NULL;	//����
	fp1 = func1;		//��ֵ
	fp1(100, 200);		//����
	(*fp1)(100, 200);	//��Ч

	//������
	FUNC_P fp2 = NULL;	//����
	fp2 = func1;		//��ֵ
	fp2(200, 300);		//����

	//������
	int (*fp3)(int, int) = NULL;	//����
	fp3 = func1;					//��ֵ
	fp3(300, 400);					//����


	cout << "----------------------" << endl;
	//����ָ��ӿڶ�̬
	iFunc(func1, 100, 200);
	iFunc(func2, 300, 400);
	iFunc(func3, 500, 600);
}