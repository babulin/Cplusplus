#include <iostream>

using namespace std;

int main(void) {

	const int a = 10;
	const int& re = a;//��������ó������ͱ����const

	int b = 20;
	const int& re2 = b;//��ȫ�͵Ŀ����ð�ȫ�ߵ�����
	//re2 = 300;//���ó����������޸�ֵ�ǲ����ܵ�

	cout << "B:" << b << endl;
	cout << "re2:" << re2 << endl;
	b = 300;
	cout << "B:" << b << endl;
	cout << "re2:" << re2 << endl;//re2�������޷��޸�ֵ��������ָ���bֵ�ı䣬��һ��ı�

	const int& a1 = 40;//����40 ������

}