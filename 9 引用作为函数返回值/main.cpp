#include <iostream>

using namespace std;

void getA(int* a)
{
	int b = 30;
	*a = b;
}

int getA1() 
{
	int a = 10;
	return a;
}

char* getA2(int num)
{
	char* p = NULL;
	p = (char*)malloc(num);
	return p;
}

void getA3(char** pp, int num)
{
	char* p = NULL;
	p = (char*)malloc(num);
	*pp = p; //��ָ��ppָ���ֵ���Ϊ pָ���ֵ���ı�ָ��
}

//������Ϊ����ֵ����Ҫ���ؾֲ���������
int& getA4() {
	int b = 20;
	return b;//����
}

//��̬�����������ǿ��Ե�
int& getA5() {
	static int sa = 10;
	return sa;
}

int main(void) {
	int a = 10;
	char* pp = NULL;
	
	getA(&a);//ֵ���� ָ��ı�a��ֵ

	a = getA1();//����ֵ����
	
	pp = getA2(10);//����ָ��ֵ����

	getA3(&pp,10);//��ָ��pp�ĵ�ַ����ȥ

	int b = 0;
	b = getA4();//b = temp ֵ����

	int &bre = getA4();//���ؾֲ��������ú󣬺���ִ����ϱ�����

	cout << bre << endl;
	cout << bre << endl;

	int& sbre = getA5();//���ؾֲ��������ú󣬺���ִ����ϱ�����

	cout << sbre << endl;
	cout << sbre << endl;

	//����ܷ��������ǾͿ���������
	getA5() = 1000;//���÷��ص��Ǳ�������
	cout << sbre << endl;
}