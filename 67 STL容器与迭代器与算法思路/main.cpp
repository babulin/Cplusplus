#include <iostream>
using namespace std;

//-----------------------
//�㷨
//ͳ��Ҫ��ѯ�����ݸ���
int myCout(int* begin, int* end, int val) {
	int num = 0;
	while (begin != end)
	{
		if (*begin == val)
		{
			num++;
		}
		begin++;//ָ��ָ����һ��
	}

	return num;
}


int main() {
	//--------------------
	//����
	int arr[] = { 0,1,2,5,6,8,0,3,6,8,0 };

	//������
	int* pBegin = arr;//ָ���׵�ַ
	int* pEnd = &(arr[sizeof(arr) / sizeof(int)]);//ȡ���һ��Ԫ����һ���ĵ�ַ

	//---------------------
	//������ʹ���㷨
	int num = myCout(pBegin, pEnd, 0);
	cout << "0 �ĸ��� num:" << num << endl;
}