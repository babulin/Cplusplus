#include <iostream>
#include <vector>
using namespace std;


void printVector(vector<int> &v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//��ʼ��
void func1() {
	vector<int> v1;//Ĭ�Ϲ���

	//�����ʼ��
	int arr[] = { 10,20,30,40 };
	vector<int> v2(arr, arr + sizeof(arr) / sizeof(int));//v2(pbegin,pend);
	vector<int> v3(v2.begin(), v2.end());

	//��������
	vector<int> v4(v3);

	printVector(v2);
	printVector(v3);
	printVector(v4);

}

//��ֵ����
void func2() {
	//�����ʼ��
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	vector<int> v2;
	//��Ա������ֵ
	v2.assign(v1.begin(), v1.end());

	vector<int> v3;
	//����=��ֵ
	v3 = v2;

	int arr1[] = { 100,200,300,400 };
	vector<int> v4(arr1, arr1 + sizeof(arr1) / sizeof(int));

	//v4��v1���� ָ�뽻����
	v4.swap(v1);

	printVector(v1);
	printVector(v2);
	printVector(v3);
	printVector(v4);
}

//��С����
void func3() {

	//�����ʼ��
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));
	
	//��С����
	cout << "size:" << v1.size() << endl;
	
	//�ж��Ƿ�Ϊ��
	if (v1.empty()) {
		cout << "v1 ��Ϊ��" << endl;
	}
	else {
		cout << "v1 ��Ϊ��" << endl;
	}

	printVector(v1);

	//��С ��ȥ����
	v1.resize(2);
	printVector(v1);

	//���� Ĭ�ϲ���0
	v1.resize(6);
	printVector(v1);

	//���� Ĭ��ֵ��ʼ��
	v1.resize(8, 1);
	printVector(v1);

	//����������Ŀռ��С
	//size:װ�ص�Ԫ�ظ���
	//[һ���������ռ䣬�����ٽ�������(�����µĿռ䣬����������)]
	cout << "size:" << v1.size() << endl;
	cout << "����:" << v1.capacity() << endl;
}

//��ȡ����
void func4() {
	//�����ʼ��
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;

	//����at() ���쳣  [] �����쳣

	//���ص�һ��Ԫ��
	cout << "front:" << v1.front() << endl;
	//�������һ��Ԫ��
	cout << "back:" << v1.back() << endl;
}


//����ɾ��
void func5() {

	vector<int> v;
	v.push_back(10);
	v.push_back(20);

	//ͷ����
	v.insert(v.begin(), 30);

	//β����
	v.insert(v.end(), 40);

	//�м�������ʲ���
	v.insert(v.begin() + 2, 100);

	//��ע��һ��֧��[] ���ʣ�����֧��ָ��+2�ȶ�֧���������
	printVector(v);


	//ɾ����һ��Ԫ��
	v.erase(v.begin());
	printVector(v);

	//ɾ���ڶ��������
	v.erase(v.begin() + 1, v.end());
	printVector(v);

	//���
	v.clear();
	cout << "size:" << v.size() << endl;
}


//����swap�����ռ�
void func6() {
	
	vector<int> v;

	for (size_t i = 0; i < 1000; i++)
	{
		v.push_back(i);
	}
	cout << "size:" << v.size() << endl;
	cout << "����:" << v.capacity() << endl;
	cout<< "-----------------------" << endl;


	//��С�ռ�
	v.resize(10);
	cout << "size:" << v.size() << endl;
	cout << "����:" << v.capacity() << endl;
	cout << "-----------------------" << endl;

	//swap() ��������
	//vector<int>(v).swap(v);//����������v������֮��������������
	vector<int> v2(v);
	v2.swap(v);
	cout << "size:" << v.size() << endl;
	cout << "����:" << v.capacity() << endl;
}

//reserve Ԥ���ռ�[��Ϊ��̬��������ʱ������������ռ䣬��������]
void func7() {

	//reserve Ԥ���ռ� resize ����

	int num = 0;//ͳ����������ռ�
	int* address = NULL;

	vector<int> v;

	//Ԥ���ռ�
	v.reserve(1000);

	for (int i = 0; i < 1000; i++)
	{
		v.push_back(i);

		//��һ��Ԫ�ص��׵�ַ �ı�ʱ�ᴥ��
		if (address != &(v[0]))
		{
			address = &(v[0]);//������һ���׵�ַ
			num++;
		}
	}

	cout << "�������:" << num << endl;
}

int main() {
	//func1();
	//func2();
	//func3();
	//func4();
	//func5();
	//func6();
	func7();

	//p-47
}