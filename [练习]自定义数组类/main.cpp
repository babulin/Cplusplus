#include <iostream>
#include "MArray.h"

using namespace std;


int main() {
	//���鴴��
	MArray arr(5),arr1(5);
	cin >> arr;
	cout << arr;

	//��ֵ
	arr1 = arr;

	if (arr != arr1)
	{
		cout << "���鲻һ��" << endl;
	}
	else {
		cout << "����һ��" << endl;
	}

	//���Ԫ��
	//for (int i = 0; i < 10; i++)
	//{
	//	//arr.setData(i, i + 1);
	//	arr[i] = i + 1;//space[i] = i + 1;��Ҫ[]���ط��� space[i]�ı���
	//}

	//����Ԫ��
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << "arr[" << i << "] = " << arr[i] << endl;
	//}
	

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

	arr2 = arr;//���������غ��ж��Ƿ����������������ȿ���

}