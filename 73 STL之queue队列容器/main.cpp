#include <iostream>
#include <queue>
using namespace std;

void func1() {
	//��ʼ��
	queue<int> q;

	//���
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	//��βԪ��
	cout << "��β��" << q.back() << endl;

	//���˳�� �Ƚ��ȳ�
	while ( ! q.empty())
	{
		//��ȡ��ͷ����
		cout << q.front() << " ";
		//ɾ����ͷ����
		q.pop();
	}
}


int main() {
	func1();

	//��ҵ1��queue������Ŷ���ָ��
	//��ҵ2��queue�������stack����
}