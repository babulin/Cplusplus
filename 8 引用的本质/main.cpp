#include <iostream>
using namespace std;
struct typeA
{
	int& a;
};

struct typeB
{
	int* a;
};

//const ���� p��pָ���޷��ı䣬pָ���ֵ���Ա��
void motify(int *const p) 
{
	*p = 300;
}

//re���� ������int& a = main::&a �Զ�
void motify2(int& re)
{
	re = 300;
}

int main() {

	//������ռ�õĴ�С��ָ������ȵ�
	cout << "sizeof(struct typeA)" << sizeof(struct typeA) << endl;
	cout << "sizeof(struct typeB)" << sizeof(struct typeB) << endl;

	int a = 10;
	int& re = a;

	//���ñ����ǳ�ָ��
	int* const p = &a;

	//����
	motify(&a);
	motify2(a);

	return 0;
}