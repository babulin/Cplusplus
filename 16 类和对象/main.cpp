#include <iostream>
using namespace std;

//�ṹ��
struct Hero 
{
	char name[64];
	int sex;
};

void coutHero(Hero &h) {
	cout << "struct Hero" << endl;
	cout << "name = " << h.name << endl;
	cout << "sex = " << h.sex << endl;
}

//��
class AdvHero
{
private:

public:
	char name[64];
	int sex;

	void coutHero() {
		cout << "class AdvHero" << endl;
		cout << "name = " << name << endl;
		cout << "sex = " << sex << endl;
	}

	void write() {
		cout << name << "��ʼд��" << endl;
	}
	void run() {
		cout << name << "��ʼ�ܲ�" << endl;
	}
};

int main(void) {

	////////////[�ṹ�������]/////////////
	Hero h;
	strcpy_s(h.name, "����");
	h.sex = 1;
	coutHero(h);

	////////////[�������]/////////////
	AdvHero advH;
	strcpy_s(advH.name, "����");
	advH.sex = 1;
	advH.coutHero();
	advH.write();

	AdvHero advH2;
	strcpy_s(advH2.name, "���");
	advH2.sex = 1;
	advH2.run();

	cin.get();
	return 0;
}