#include <iostream>
using namespace std;

//�����׳�����
class MException {
public:
	void show() {
		cout << "��������쳣����" << endl;
	}
};
int func1(int a,int b) {

	if (b == 0)
	{
		MException ome;
		throw ome;
		//throw b;//���׳�������ƥ��
	}

	return a / b;
}

void func2(int x,int y) {
	//try
	//{
	//	func1(x, y);
	//}
	//catch (int e)
	//{
	//	cout << "��������Ϊ" << e << "!" << endl;
	//}

	func1(x, y);
}



int main() {

	//�쳣���񣬿����������ף�ֱ�������񲢴���
	//func2(10, 0);

	try
	{
		func2(10, 0);
	}
	catch (MException e)
	{
		e.show();
		cout << "��������Ϊ" << "!" << endl;
	}
}