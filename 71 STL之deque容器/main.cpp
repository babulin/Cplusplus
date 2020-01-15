#include <iostream>
#include <deque>
using namespace std;

void printDeque(deque<int>& d) {
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++){
		cout << *it << " ";
	}
	cout << endl << "---------------------------" << endl;
}
//��ʼ��
void func1() {

	deque<int> d1;
	deque<int> d2(10,5);//10��ָ��Ԫ�س�ʼ��
	deque<int> d3(d2.begin(), d2.end());//ʹ��ָ���ռ��ʼ��
	deque<int> d4(d3);//���������ʼ��

	printDeque(d2);
	printDeque(d3);
	printDeque(d4);
}

//��ֵ ��С����
void func2() {
	deque<int> d1;
	deque<int> d2;
	deque<int> d3;

	d1.assign(10, 5);//ָ��10��Ԫ�ظ�ֵ
	d2.assign(d1.begin(), d1.end());//ʹ��ָ���ռ��ʼ��
	d3 = d2;//=��ֵ����

	//�����ռ�
	d1.swap(d2);//d1��d2����ָ��Ŀռ�

	//�Ƿ�Ϊ��
	if (d1.empty()){
		cout << "d1Ϊ��" << endl;
	}
	else {
		cout << "d1��Ϊ�� size => " << d1.size() << endl;
	}

	//���ô�С
	d1.resize(5);//�ӵ�����5��
	printDeque(d1);
	d1.resize(12, 1);//����Ϊ12������������1��ʼ��
	printDeque(d1);
}

//�����ɾ��
void func3() {

	deque<int> d1(5,1);
	printDeque(d1);

	//��ǰ�����
	d1.push_front(10);
	printDeque(d1);

	//�Ӻ������
	d1.push_back(20);
	printDeque(d1);

	//ɾ��ǰ��
	int val = d1.front();
	if (val == 10){
		d1.pop_front();
	}
	printDeque(d1);

	//ɾ������
	val = d1.back();
	if (val == 20) {
		d1.pop_back();
	}
	printDeque(d1);

}
int main() {
	//func1();
	//func2();
	func3();

	//p52;
}