#include <iostream>
using namespace std;

class Parent {
public:
	int pub;//�� ���ⶼ���Է���
protected:
	int pro;//�� �ڲ����Է��ʣ��ⲿ�޷�����
private:
	int pri;//�� �ڲ����Է��ʣ��ⲿ�޷�����
};

//--------------------------------------
//���м̳У�
//--------------------------------------
class Child :public Parent {
public:
	void show() {
		cout << pub << endl;//���Է���
		cout << pro << endl;//���Է���
		//cout << pri << endl;//������
	}
};

class SubChild :public Child {
public:
	void show() {
		cout << pub << endl;//���Է���
		cout << pro << endl;//���Է���
		//cout << pri << endl;//������
	}
};

//--------------------------------------
//�����̳У�
//--------------------------------------
class Child2 :protected Parent {
public:
	void show() {
		cout << pub << endl;//���Է���
		cout << pro << endl;//���Է���
		//cout << pri << endl;//������
	}
};

class SubChild2 :public Child2 {
public:
	void show() {
		cout << pub << endl;//���Է���
		cout << pro << endl;//���Է���
		//cout << pri << endl;//������
	}
};


//--------------------------------------
//˽�м̳У�
//--------------------------------------
class Child3 :private Parent {
public:
	void show() {
		cout << pub << endl;//���Է���
		cout << pro << endl;//���Է���
		//cout << pri << endl;//������
	}
};

class SubChild3 :public Child3 {
public:
	void show() {
		//cout << pub << endl;//������
		//cout << pro << endl;//������
		//cout << pri << endl;//������
	}
};


int main() {

	Child c1;
	cout << c1.pub << endl;//����
	//cout << c1.pro << endl;//������
	//cout << c1.pri << endl;//������

	Child2 c2;
	//cout << c2.pub << endl;//������
	//cout << c2.pro << endl;//������
	//cout << c2.pri << endl;//������

	SubChild2 sc2;
	//cout << sc2.pub << endl;//������
	//cout << sc2.pro << endl;//������
	//cout << sc2.pri << endl;//������
}