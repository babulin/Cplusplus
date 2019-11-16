#include <iostream>
using namespace std;

//结构体
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

//类
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
		cout << name << "开始写字" << endl;
	}
	void run() {
		cout << name << "开始跑步" << endl;
	}
};

int main(void) {

	////////////[结构体与变量]/////////////
	Hero h;
	strcpy_s(h.name, "盖伦");
	h.sex = 1;
	coutHero(h);

	////////////[类与对象]/////////////
	AdvHero advH;
	strcpy_s(advH.name, "春哥");
	advH.sex = 1;
	advH.coutHero();
	advH.write();

	AdvHero advH2;
	strcpy_s(advH2.name, "表哥");
	advH2.sex = 1;
	advH2.run();

	cin.get();
	return 0;
}