#include <iostream>
using namespace std;

//��ʼ��
void func1() {

	string str1;//�����޲ι���
	cout << "string() =>" << str1 << endl;

	//�ظ�����10��a
	string str2(10,'a');
	cout << "string(int,char) => " << str2 << endl;

	//�ַ�������
	string str3("abcdefg");
	cout << "string(char*) => " << str3 << endl;

	//��������
	string str4(str3);
	cout << "string(const string&) => " << str3 << endl;
}

//����
void func2() {
	//=������
	string str1;
	string str2("abcde");
	
	//=����������(char*����)
	str1 = "hello";
	cout << "str1 => " << str1 << endl;

	//=����������(string����)
	str1 = str2;
	cout << "str1 => " << str1 << " str2 => " << str2 << endl;

	str1 = 'a';
	cout << "str1 => " << str1 << endl;
	
	//��Ա������ֵ
	str1.assign("jkkkkk");
	cout << "str1 => " << str1 << endl;
}

//ȡֵ����
void func3() {
	string str1 = "abcde";
	
	//����[]������
	for (int i = 0; i < str1.size(); i++)
	{
		//��ֱ��ͨ��[]�±�ȡֵ
		cout << str1[i] << " ";
		str1[i] = str1[i] + 1;//����ǰֵ������һ����ĸ��ASCII��
	}
	cout << endl;

	//at()��Ա����
	for (int i = 0; i < str1.size(); i++)
	{
		//��ֱ��ͨ��[]�±�ȡֵ
		cout << str1.at(i) << " ";
	}
	cout << endl;

	//����: at()����Խ����out_of_range�쳣��[]����Խ��ֱ�ӹҵ�
	try
	{
		//�޷�����
		//cout << str1[100] << endl;

		//�׳��쳣
		cout << str1.at(100) << endl;
	}
	catch (...)
	{
		cout << "����Խ����" << endl;
	}
}

//ƴ�Ӳ���
void func4() {

	//+=����
	string str1 = "abcd";
	string str2 = "efgh";
	//+= string ����
	str1 += str2;
	//+= char* �ַ���
	str1 += "ijk";
	//+= char �ַ�
	str1 += 'l';

	cout << "str1 => " << str1 << endl;
	
	//��Ա����׷��
	string str3 = "12345";
	str1.append(str3);
	str1.append("678");
	cout << "str1 => " << str1 << endl;
}

//�ַ�������
void func5() {
	string str1 = "adekfgiofgoke";
	//��ǰ�������
	int pos = str1.find("fg");
	cout << "pos => " << pos << endl;

	//�Ӻ���ǰ��
	pos = str1.rfind("fg");
	cout << "pos => " << pos << endl;

}

//�ַ����滻
void func6() {
	string str1 = "abcdefg";

	//�滻
	str1.replace(0, 2, "123");
	cout << "str1 => " << str1 << endl;

}

//�ַ����Ƚ�
void func7() {
	string str1 = "abcd";
	string str2 = "abce";

	//s1 > s2 ���� 1��s1 < s2 ���� -1  ��� ���� 0
	if (str1.compare(str2) == 0)
	{
		cout << "�ַ������!" << endl;
	}
	else {
		cout << "�ַ��������!" << endl;
	}
}

//��ȡ�ַ���
void func8() {
	string str1 = "abcdefg";

	//��ȡ
	string str2 = str1.substr(1, 3);
	cout << "str2 => " << str2 << endl;
}

//�����ɾ��
void func9() {
	string str1 = "abcdefg";

	//��������
	str1.insert(3, "111");
	cout << "str1.insert(3, \"111\") => " << str1 << endl;

	//ɾ���ַ���
	str1.erase(0, 2);
	cout << "str1.erase(0, 2) => " << str1 << endl;

}

int main() {
	//func1();
	//func2();
	//func3();
	//func4();
	//func5();
	//func6();
	//func7();
	//func8();
	func9();

	//p44;
}