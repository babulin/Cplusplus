#include <iostream>
using namespace std;

class Teacher {
private:
	int mId;
	char *mName;
public:
	Teacher(int id,const char* name) {

		cout << "Teacher(int,char*)有参构造函数" << endl;

		mId = id;
		int len = strlen(name) + 1;//+1 结束符号\0
		mName = (char*)malloc(len);
		strcpy_s(mName, len, name);
	}

	void coutName() {
		cout << "姓名：" << mName << endl;
	}

	void updateName(const char* name) {
		strcpy_s(mName, strlen(name) + 1, name);
	}


	//显示一个深拷贝构造函数
	Teacher(const Teacher& ther) {
		mId = ther.mId;

		//为拷贝的对象新开辟指针空间，这是深拷贝
		int len = strlen(ther.mName) + 1;//+1 结束符号\0
		mName = (char*)malloc(len);
		strcpy_s(mName, len, ther.mName);
	}


	//析构函数
	~Teacher() {
		cout << "~Teacher()析构函数" << endl;

		if (mName != NULL)
		{
			//释放的是指针
			free(mName);
			mName = NULL;
		}
	}
};

int main(void) {

	Teacher t1(1, "张三");
	t1.coutName();

	//默认构造函数是浅拷贝
	Teacher t2(t1);
	//修改值
	t1.updateName("李四");

	//t2的名字也被修改【因为指向的同一个堆空间】
	t2.coutName();

	return 0;
}