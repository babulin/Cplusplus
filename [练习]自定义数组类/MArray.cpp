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
int MArray::getLen() const
{
	return len;
}

/*
* ���� = �Ų�����
*/
MArray& MArray::operator=(const MArray& other)
{

	if (this == &other)
	{
		//��������
		return *this;
	}

	if (space != nullptr)
	{
		delete[] space;
		space = nullptr;
		len = 0;
	}

	if (other.len <= 0)
	{
		//û�����ݿ��Կ���
		return *this;
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

	return *this;
}

//����[]�±����
int& MArray::operator[](int index) const
{
	// TODO: �ڴ˴����� return ���
	if (index >= len)
	{
		//�޸����һ��
		return space[len - 1];
	}
	return space[index];
}

//���� !=
bool MArray::operator!=(MArray& arr2)
{
	return !(*this == arr2);//���õ� == ����
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

//[1]ȫ�ֺ������� <<
//[2]�������otherֻ�� other.getLen()���޷����ʣ�ԭ���� other.getLen(MArray* this); ����Ҳ��ֻ���޶���
std::ostream& operator<<(std::ostream& os,const MArray& other) {
	std::cout << "[<<����]�������飺" << std::endl;

	for (int i = 0; i < other.getLen(); i++)
	{
		std::cout << "arr[" << i << "] = " << other[i] << std::endl;
	}

	return os;
}

//����
std::istream& operator>>(std::istream& is, MArray& other)
{
	std::cout << "������" << other.getLen() << "����" << std::endl;

	for (int i = 0; i < other.getLen(); i++)
	{
		is >> other[i];
	}

	return is;
}

//ȫ��==����
bool operator==(MArray& arr1, MArray& arr2)
{
	if (arr1.len != arr2.len)
	{
		return false;
	}

	for (int i = 0; i < arr1.len; i++)
	{
		if (arr1[i] != arr2[i])
		{
			return false;
		}
	}

	return true;
}
