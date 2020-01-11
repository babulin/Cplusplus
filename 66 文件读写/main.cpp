#include <iostream>
#include <fstream>
using namespace std;

void func1() {
	//打开文件
	const char* sourceFile = "source.txt";
	const char* tagrgetFile = "target.txt";
	ifstream fp(sourceFile, ios::in);
	ofstream ofp(tagrgetFile, ios::out | ios::app);//写入模式，追加写入

	//ifstream is;
	//is.open(file);

	if (!fp)
	{
		cout << "打开文件" << sourceFile << "失败！" << endl;
		return;
	}

	//读取
	char ch;
	while (fp.get(ch))
	{
		cout << ch;
		ofp.put(ch);
	}

	//关闭
	fp.close();
	ofp.close();
}

//二进制文件操作 对象序列化

class Person {
protected:
	//十六进制 0100 0000 0200 0000 0300 0000
	//所以，跟对象的属性排列先后顺序有关
	int mId; //0100 0000
	int mAge;//0200 0000
	int mSex;//0300 0000
public:
	Person() {
		mAge = 0;
		mId = 0;
		mSex = 0;
	}

	Person(int id, int age) : mId(id), mAge(age) {
		mSex = 0;
	}

	void show() {
		cout << "id = " << mId << " age = " << mAge << " sex = "<< mSex << endl;
	}
};

void func2() {
	const char* file = "Person.bin";
#if 0
	//将对象写入文件
	Person p1(1, 100);

	//以二进制写入方式打开文件
	ofstream ofp(file, ios::out | ios::binary);
	ofp.write((char*)&p1, sizeof(p1));
	ofp.close();
#endif // 0

	//以二进制读取方式打开
	ifstream fp(file, ios::in | ios::binary);
	Person pp;
	fp.read((char*)&pp, sizeof(pp));
	fp.close();

	pp.show();
}

int main() {

	//func1();
	func2();
}