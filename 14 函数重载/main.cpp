#include <iostream>
using namespace std;

//�������� [1]��������ͬ�������������������ͣ�����˳��ͬ
//[2]����ֵ�����ǹ��ɺ������ص�����

int func(int a,int b) {
	cout << "func1" << endl;
	return 0;
}

//�������أ�[3]��ҪдĬ�ϲ�����Ϊ�˱������ʱ�������壬����ƥ��
//func(10, 10); ��������
char func(int a,int b,int = 0) {
	cout << "func2" << endl;
	return 0;
}

//�������أ�[4]�����������ʽת����Ҳ��ƥ��
void print(int a) {
	cout << "int����:" << a << endl;
}

#if 1
void print(char a) {
	cout << "char����:" << a << endl;
}
#endif // 0

int main()
{
	func(10, 10, 0);//���Ժ�func2ƥ��

	//char Ҳ������ʽת����int ���Կ���ƥ�䡣
	//�����char ��ȫƥ�䣬������
	print(10);
	print('a');

	cin.get();
}
