#include <iostream>
#include <iomanip>
using namespace std;

//cin.get()
//�ӻ�������ȡһ���ַ�
void func1() {
	char ch;

	//ѭ��ÿ�δӻ�������һ���ַ�
	//EOF = ctrl+z
	//while ((ch = cin.get()) != EOF)
	//{
	//	cout << ch << endl;
	//}

	//��ȡһ���ַ�
	ch = cin.get();
	cout << "cin.get() => " << ch << endl;

	cin.get(ch);
	cout <<"cin.get(ch) => "<< ch << endl;

	//��ȡ256 �ַ���
	char buf[256] = { 0 };
	cin.get(buf, 256);
	cout << "cin.get(buf, 256) => " << buf << endl;
}

//cin.getline()
//�ӻ�������ȡһ�� ����ȡ '\n'
void func2() {
	char buf[256] = { 0 };
	cin.getline(buf,256);
	cout << "cin.getline(buf,256) => " << buf << endl;//����ȡ \n
}

//cin.ignore()
//���Ի�����һ���ַ� 
void func3() {
	char ch;

	ch = cin.get();
	cout <<"cin.get() => "<< ch << endl;

	//cin.ignore();//����һ���ַ� abcd
	//cin.ignore(2);//����2���ַ�
	cin.ignore(10, '\n');//����10��֮ǰ���� \n ��ǰ����

	ch = cin.get();
	cout << "cin.get() => " << ch << endl;
}

//cin.peek()
//�鿴������1���ַ���
void func4() {
	char ch;
	ch = cin.peek();//͵��һ���ַ� abcd
	if (ch >= '0' && ch <= '9')
	{
		int number;
		cin >> number;
		cout << "�������������:" << number << endl;
	}
	else {
		char buf[256] = { 0 };
		cin >> buf;
		cout << "����������ַ���:" << buf << endl;
	}
}

//cin.putback()
//�Żػ�������ǰλ��
void func5() {

	char ch;
	ch = cin.get();

	if (ch >= '0' && ch <= '9') {
		//�Żػ�������ǰλ��
		cin.putback(ch);
		int number;
		cin >> number;
		cout << "�������������:" << number << endl;
	}
	else {
		//�Żػ�������ǰλ��
		cin.putback(ch);
		char buf[256] = { 0 };
		cin >> buf;
		cout << "����������ַ���:" << buf << endl;
	}
}

//��׼�����
void func() {

	cout << "cout.flush() => ˢ�»�����" << endl;
	//cout.flush();

	cout << "cout.put('H').put('e') => ����ַ� ";
	cout.put('H').put('e').put('l').put('l').put('o') << endl;

	//��ʽ�����
	int number = 15;

	cout.setf(ios::showbase);//���������ʽ

	//8�������
	cout.unsetf(ios::dec);//ж��10����
	cout.setf(ios::oct);//ʹ��8����
	cout << number << endl;

	//16�������
	cout.unsetf(ios::oct);//ж��8����
	cout.setf(ios::hex);//16����
	cout << number << endl;

	//��ʽλ
	cout.width(10);//���
	cout.fill('*');//����λ���
	cout.setf(ios::left);//���뷽ʽ
	cout << number << endl;


	//ͨ�����Ʒ�
	int number1 = 14;

	cout << hex //16����
		<< setiosflags(ios::showbase) //��ʾ������ʽ
		<< setw(10)	//���
		<< setfill('*') //����λ
		<< setiosflags(ios::left) //���뷽ʽ
		<< number1
		<< endl;


}

int main() {
	//func1();
	//func2();
	//func3();
	//func4();
	//func5();
	func();
}