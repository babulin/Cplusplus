#include <iostream>
#include "MArray.h"

using namespace std;

int main() {
	//���鴴��
	MArray arr(10);

	//���Ԫ��
	for (int i = 0; i < 10; i++)
	{
		arr.setData(i, i + 1);
	}

	//����Ԫ��
	for (int i = 0; i < 10; i++)
	{
		cout << "arr[" << i << "] = " << arr.getData(i) << endl;
	}

	//���鸴��
	MArray arr2 = arr;

	//����Ԫ��
	for (int i = 0; i < 10; i++)
	{
		cout << "arr2[" << i << "] = " << arr2.getData(i) << endl;
	}

	//���鸳ֵ
	MArray arr3;

	//������ԭ���ǣ�arr3Ĭ�ϸ�ֵ����arr, spaceָ�뱻 arr3������arr�ٴ�����ʱʧ��
	//Ϊ����� operator= ����=�Ų�����֮����� space ������������������OK��
	arr3 = arr;

}