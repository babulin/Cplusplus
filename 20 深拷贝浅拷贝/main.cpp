#include <iostream>
using namespace std;

class Teacher {
private:
	int mId;
	char *mName;
public:
	Teacher(int id,const char* name) {

		cout << "Teacher(int,char*)�вι��캯��" << endl;

		mId = id;
		int len = strlen(name) + 1;//+1 ��������\0
		mName = (char*)malloc(len);
		strcpy_s(mName, len, name);
	}

	void coutName() {
		cout << "������" << mName << endl;
	}

	void updateName(const char* name) {
		strcpy_s(mName, strlen(name) + 1, name);
	}


	//��ʾһ��������캯��
	Teacher(const Teacher& ther) {
		mId = ther.mId;

		//Ϊ�����Ķ����¿���ָ��ռ䣬�������
		int len = strlen(ther.mName) + 1;//+1 ��������\0
		mName = (char*)malloc(len);
		strcpy_s(mName, len, ther.mName);
	}


	//��������
	~Teacher() {
		cout << "~Teacher()��������" << endl;

		if (mName != NULL)
		{
			//�ͷŵ���ָ��
			free(mName);
			mName = NULL;
		}
	}
};

int main(void) {

	Teacher t1(1, "����");
	t1.coutName();

	//Ĭ�Ϲ��캯����ǳ����
	Teacher t2(t1);
	//�޸�ֵ
	t1.updateName("����");

	//t2������Ҳ���޸ġ���Ϊָ���ͬһ���ѿռ䡿
	t2.coutName();

	return 0;
}