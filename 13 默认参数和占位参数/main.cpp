#include <iostream>
using namespace std;

//Ĭ�ϲ��� [1]ֻ�ܴ�������
int getVolume(int len,int w = 10,int h = 10) {
	cout << "len = " << len << endl;
	cout << "w = " << w << endl;
	cout << "h = " << h << endl;
	return len * w * h;
}

//int ռλ��������C++��֮ǰΪ��ռλ ����дint=0
void func2(int x,int) 
{
	cout << "x = " << endl;
}

//Ϊ��ռλ ����дint=0
void func3(int x, int = 0)
{
	cout << "x = " << endl;
}

int main()
{
	cout << "Volume = " << getVolume(10, 2, 5) << endl;
	func2(10,1);
	func3(10);

	cin.get();
}
