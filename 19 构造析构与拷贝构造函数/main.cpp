#include <iostream>
using namespace std;


class Hum {

private:
	int mAge;
	int mId;
public:
	//Ĭ���޲ҹ��캯��
	Hum() {
		mAge = 0;
		mId = 0;
		cout << "Hum()�޲ι���:" << this << endl;
	}

	//����
	Hum(int id) {
		mId = id;
		mAge = 0;
		cout << "Hum(int id)�вι���:" << this << endl;
	}

	//����
	Hum(int id, int age) {
		mId = id;
		mAge = age;
		cout << "Hum(int id,int age)�вι���:" << this << endl;
	}

	//��ʽ�������캯��
	//Ĭ�Ͽ��� ��ָ��������
	Hum(const Hum& hum) {
		mAge = hum.mAge;
		mId = hum.mId;
		cout << "Hum(const Hum& hum)��������" << this << endl;
	}

	//=�� ��ֵ������
	void operator=(const Hum& hum) {
		mId = hum.mId;
		mAge = hum.mAge;
		cout << "=�Ų�������ֵ" << endl;
	}

	void eat() {
		cout << "age = " << mAge << " id = " << mId << " address:" << this << endl;
	}

	//��������
	//����������˭�ȹ���ģ�˭������
	~Hum() {
		cout << "��������:" << mId << " address:" << this << endl;
	}


};

//����Ϊ�β� �ǿ�������
//Hum hum = hum2;
void func(Hum hum) {
	hum.eat();
}

//����Ϊ����ֵ
Hum func2() {
	Hum temp(10, 20);
	return temp;
}//�������� = temp ��������

int main() {

	//Ĭ���޲ι���
	Hum hum;
	//hum.eat();

	//�в�������
	Hum hum1(1);

	//Ĭ�Ͽ�������
	Hum hum2(hum1);

	//���ÿ��� ����ʼ����ʱ����õĿ������죩
	Hum hum3 = hum2;

	//���õ��Ǹ�ֵ
	Hum hum4;
	hum4 = hum2;

	//������������ʱ��û���κα������������������󽫲���ʹ��
	//����ִ����� ��������
	//�����ھֲ�����Ҳ����������
	Hum hum5 = func2();//hum5������;���������� ת������ hum5 

	//hum4 =�Ų�������ֵ
	//Ȼ����������������
	hum4 = func2();

	//�βε��õ��ǿ�������
	func(hum2);


	//cin.get();
	return 0;
}