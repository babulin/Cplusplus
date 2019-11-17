#include "MArray.h"

/*---------------------------------
 * Ĭ���޲�������
 */
MArray::MArray() {
	len = 0;
	space = nullptr;
}

/*---------------------------------
 * �����鳤�ȹ���
 */
MArray::MArray(int len)
{
	if (len <= 0)
	{
		this->len = 0;
		return;
	}

	this->len = len;
	space = new int[this->len];
}

/*---------------------------------
 * �������캯��
 */
MArray::MArray(const MArray& other)
{
	if (other.len <= 0)
	{
		//û�����ݿ��Կ���
		return;
	}

	//��������
	len = other.len;
	//ָ�뿪���¿ռ�
	space = new int[len];
	//��������ֵ
	for (int i = 0; i < len; i++)
	{
		space[i] = other.space[i];
	}
}

/*---------------------------------
 * Ϊ�������ֵ
 */
void MArray::setData(int index, int data)
{
	if (space == nullptr)
	{
		//���ش���
		return;
	}

	if (len <= index)
	{
		//����ֵ����
		return;
	}
	space[index] = data;
}

/*---------------------------------
 * ����ֵ
 */
int MArray::getData(int index)
{
	return space[index];
}

/*---------------------------------
 * �������鳤��
 */
int MArray::getLen()
{
	return len;
}

/*
* ���� = �Ų�����
*/
void MArray::operator=(const MArray& other)
{
	if (other.len <= 0)
	{
		//û�����ݿ��Կ���
		return;
	}

	//��������
	len = other.len;
	//ָ�뿪���¿ռ�
	space = new int[len];
	//��������ֵ
	for (int i = 0; i < len; i++)
	{
		space[i] = other.space[i];
	}
}

/*
* ��������
*/
MArray::~MArray()
{
	if (space != nullptr)
	{
		delete[] space;
		space = nullptr;
		len = 0;
	}
}

