#include <iostream>
using namespace std;

//����һ int[5] ��������
typedef int(ARRAY_INT)[5];

//������
typedef int(*ARRAY_INT_P)[5];

//��������
typedef int(ARRAY)[];

int main() {
	//int[10] ��������
	ARRAY_INT int10 = { 1,2,3,4,5};

	for (size_t i = 0; i < 5; i++)
	{
		int10[i] = i;
	}

	for (size_t i = 0; i < 5; i++)
	{
		cout << int10[i] << endl;
	}

	cout << "----------------------" << endl;
	//��ͨ����
	int arr[5] = {};
	//arr -> ��ַ [][][][][]


	//��������ָ��
	ARRAY_INT* pa = &arr;
	//ָ������
	ARRAY_INT_P p = &arr;

	//int[5] �� p ָ�� = arr�ĵ�ַ

	for (size_t i = 0; i < 5; i++)
	{
		(*pa)[i] = i;
		//(*p)[i] = i;
	}

	for (size_t i = 0; i < 5; i++)
	{
		cout << (*pa)[i] << endl;
		//cout << (*p)[i] << endl;
	}

	//��������
	ARRAY array = {1,2,3,4,5,6,7};

}