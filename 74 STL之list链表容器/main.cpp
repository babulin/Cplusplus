#include <iostream>
#include <list>
using namespace std;

//��ʼ��
void func1() {
	list<int> l1;
	list<int> l2(10, 1);//10��1��ʼ��
	list<int> l3(l2);//��������
	list<int> l4(l3.begin(), l3.end());//ָ������

	for (list<int>::iterator  it = l4.begin(); it != l4.end(); it++)
	{
		cout << (*it) << " ";
	}

	cout << endl;
}

//����ɾ��
//��֧���������
void func2() {

	list<int> li;

	//β������
	li.push_back(10);

	//ͷ������
	li.push_front(20);

	//��������
	li.insert(li.begin(),30);//������ ��������
	li.insert(li.end(),200);//������ ��������

	list<int>::iterator it = li.begin();

	//it + 5;//��֧��
	it++;
	it++;
	li.insert(it, 500);
	li.insert(it, 200);

	//ɾ��
	//li.pop_front();
	//li.pop_back();

	//ɾ��ָ������
	//li.erase(li.begin(), li.end());//����������
	//li.clear();//�������

	//ɾ������ƥ���Ԫ��
	li.remove(200);

	for (list<int>::iterator lit = li.begin(); lit != li.end(); lit++)
	{
		cout << (*lit) << " ";
	}
	cout << endl;
}

//��С����
void func3() {
	list<int> l1;
	l1.size();//����
	l1.empty();//�жϿ�
	l1.resize(1);//�Ŵ���С
	l1.resize(10,1);//�Ŵ���С
}

//��ֵ����
void func4() {
	list<int> l1;
	l1.assign(10, 1);

	list<int> l2;
	l2 = l1;//=�Ÿ�ֵ

	l2.swap(l1);//����
}

void ShowList(list<int>& li) {
	for (list<int>::iterator lit = li.begin(); lit != li.end(); lit++)
	{
		cout << (*lit) << " ";
	}
	cout << endl;
}

//���� ��ת
void func5() {
	list<int> li;

	for (int i = 0; i < 10; i++)
	{
		li.push_back(i);
	}
	ShowList(li);

	//��ת
	li.reverse();
	ShowList(li);
}

bool doSort(int v1,int v2) {
	return v1 > v2;
}

//����
void func6() {
	list<int> li;
	li.push_back(2);
	li.push_back(1);
	li.push_back(7);
	li.push_back(5);
	ShowList(li);

	//Ĭ�� ����
	li.sort();
	ShowList(li);

	//ָ�� ����
	li.sort(doSort);
	ShowList(li);
}


int main() {
	//func1();
	//func2();

	//func5();
	func6();
}