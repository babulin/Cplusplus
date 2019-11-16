#include <iostream>
using namespace std;

//��������
int func(int a, int b) {
	cout << "func a=" << a << " b=" << b << endl;
	return 0;
}

//[1]���庯������
typedef int(MYFUNC)(int, int);

//[2]����һ���������͵�ָ������
typedef int(*PMYFUNC)(int, int);

//[3]����ָ������أ���������ƥ��
int func(int a, int b,int c) {
	cout << "func a=" << a << " b=" << b << " c=" << c << endl;
	return 0;
}

int main(void) 
{
	/////////////��1��/////////////
	//�ú������͵ı���
	MYFUNC *pfunc;
	pfunc = func;//�����������ǵ�ַ

	pfunc(10, 20);
	(*pfunc)(10, 20);//ͬ��

	/////////////��2��/////////////
	//�ú������͵�ָ�����
	PMYFUNC pfun = nullptr;
	pfun = func;
	pfun(100,200);

	/////////////��3��/////////////
	//ֱ�Ӷ���һ������ָ�����
	int(*fp3)(int, int) = nullptr;
	fp3 = func;
	fp3(101, 102);
	//fp3(1, 2, 3);//�������

	/////////////��4��/////////////
	//����ָ�붨��ʱ�����뺯��ƥ��
	//����ָ�븳ֵʱ�����������ص� �����޷���ʽת����������ȫƥ��
	int(*fp4)(int, int, int) = nullptr;
	fp4 = func;
	fp4(1, 2, 3);

	cin.get();
	return 0;
}