#include <iostream>
using namespace std;


//����int ����
void func1() {
	throw 1;
}

//����char* ����
void func2() {
	throw "exception";
}

class MyException {
protected:
	char* m_errMsg;
public:
	MyException(const char* errMsg) {
		//����
		int len = strlen(errMsg) + 1;
		m_errMsg = new char[len];
		//strcpy_s(Ŀ��ָ��,Դ���ݳ���,Դ����ָ��)
		strcpy_s(m_errMsg, len, errMsg);
		cout << "MyException()���캯��" << endl;
	}

	//��������
	MyException(const MyException& ex) {
		//����
		int len = strlen(ex.m_errMsg) + 1;
		m_errMsg = new char[len];
		//strcpy_s(Ŀ��ָ��,Դ���ݳ���,Դ����ָ��)
		strcpy_s(m_errMsg, len, ex.m_errMsg);
		cout << "MyException()��������" << endl;
	}

	~MyException() {
		if (m_errMsg != nullptr)
		{
			delete[] m_errMsg;
			m_errMsg = nullptr;
		}

		cout << "~MyException()����:error = " << &m_errMsg << endl;
	}

	void show() {
		cout << "�쳣��Ϣ:" << m_errMsg << endl;
	}
};


//������������
void func3() {
	//������������ �� e�ǿ�������
	throw MyException("�����쳣��������");
}

//p29-2-13�쳣��������
int main() {

	try
	{
		func3();
	}
	//catch (MyException e)
	//{
	//	//��ͨ����
	//	e.show();
	//}
	catch (MyException & e)
	{
		//���ö���
		e.show();
	}
	//catch (MyException * e)
	//{
	//	//���ö���
	//	e->show();
	//}
	
}