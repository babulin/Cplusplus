#include <iostream>
#include <stack>
using namespace std;

//stack ջ   �Ƚ������ֻ�ܴӶ��˻�ȡ����
//�޵����������ܱ�������֧���������
void func1() {
	//��ʼ��
	stack<int> s1;
	stack<int> s2(s1);

	//stack����
	s1.push(10);//ѹջ
	s1.push(20);//ѹջ
	s1.push(30);//ѹջ
	s1.push(100);//ѹջ

	//ȡ��
	cout << "ջ�����ݣ�" << s1.top() << endl;
	//ɾ��ջ������
	s1.pop();

	//��������
	while (!s1.empty()) {
		//ȡһ�� ɾһ��
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << " size:" << s1.size() << endl;
}


int main() {
	
	func1();

	//��ҵ1��stack������Ŷ���ָ��
	//��ҵ2��stack������Ŷ���
}