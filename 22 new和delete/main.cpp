#include<iostream>
using namespace std;

class Test {
private:
	int m_a;
	int m_b;
public:
	Test(int a, int b) {
		m_a = a;
		m_b = b;
		cout << "Test����" << endl;
	}

	void show() {
		cout << "a=" << m_a << " b=" << m_b << endl;
	}

	~Test() {
		cout << "Test����" << endl;
	}
};

void useMalloc() {
	int* pint = (int*)malloc(sizeof(int));//�����ǿ��ٶ��ٸ��ֽ�

	*pint = 10;//ָ��Ϊ���ٵĿռ丳ֵ
	cout << "pint=" << *pint <<" :"<< pint << endl;
	if (pint != NULL)
	{
		free(pint);
		pint = NULL;
	}

	//��������
	int* parray = (int*)malloc(sizeof(int) * 10);//����10��int��С
	for (int i = 0; i < 10; i++)
	{
		parray[i] = i + 1;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d", parray[i]);
	}
	printf("\n");
	if (parray != NULL)
	{
		free(parray);
		parray = NULL;
	}

}

void useNew() {
	//���ٱ���
	int* pint = new int;
	*pint = 10;
	cout << "pint=" << *pint << " sizeof(pint) = "<< sizeof(pint) <<" :" << pint << endl;
	if (pint != NULL)
	{
		delete pint;
		pint = NULL;
	}

	//��������
	int a(10);//��ʼ������
	int a1 = int(10);//��������ת�� һ������
	
	int* parray = new int[10];//10��int
	for (int i = 0; i < 10; i++)
	{
		parray[i] = i + 1;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << parray[i];
	}
	cout << endl;

	if (parray != NULL)
	{
		delete[] parray;
	}

	cout << "=======================" << endl;
	//���Ͽ��ٶ���
	Test* t1 = new Test(1,2);//������
	t1->show();
	delete t1;//������
}



int main() {
	//ʹ��malloc �� free ��׼�� stdlib.h
	useMalloc();

	//ʹ��new �� delete 
	useNew();
}