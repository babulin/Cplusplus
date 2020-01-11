#include <iostream>
#include <fstream>
using namespace std;

void func1() {
	//���ļ�
	const char* sourceFile = "source.txt";
	const char* tagrgetFile = "target.txt";
	ifstream fp(sourceFile, ios::in);
	ofstream ofp(tagrgetFile, ios::out | ios::app);//д��ģʽ��׷��д��

	//ifstream is;
	//is.open(file);

	if (!fp)
	{
		cout << "���ļ�" << sourceFile << "ʧ�ܣ�" << endl;
		return;
	}

	//��ȡ
	char ch;
	while (fp.get(ch))
	{
		cout << ch;
		ofp.put(ch);
	}

	//�ر�
	fp.close();
	ofp.close();
}

//�������ļ����� �������л�

class Person {
protected:
	//ʮ������ 0100 0000 0200 0000 0300 0000
	//���ԣ�����������������Ⱥ�˳���й�
	int mId; //0100 0000
	int mAge;//0200 0000
	int mSex;//0300 0000
public:
	Person() {
		mAge = 0;
		mId = 0;
		mSex = 0;
	}

	Person(int id, int age) : mId(id), mAge(age) {
		mSex = 0;
	}

	void show() {
		cout << "id = " << mId << " age = " << mAge << " sex = "<< mSex << endl;
	}
};

void func2() {
	const char* file = "Person.bin";
#if 0
	//������д���ļ�
	Person p1(1, 100);

	//�Զ�����д�뷽ʽ���ļ�
	ofstream ofp(file, ios::out | ios::binary);
	ofp.write((char*)&p1, sizeof(p1));
	ofp.close();
#endif // 0

	//�Զ����ƶ�ȡ��ʽ��
	ifstream fp(file, ios::in | ios::binary);
	Person pp;
	fp.read((char*)&pp, sizeof(pp));
	fp.close();

	pp.show();
}

int main() {

	//func1();
	func2();
}