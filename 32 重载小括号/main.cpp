#include <iostream>
using namespace std;

class A {
private:
	int m_a;
public:
	A(int a) {
		m_a = a;
	}

	//()����:�º��� α���� 
	int operator()(int value) {
		return value * value;
	}

	//����
	int operator()(int value,int value1) {
		return value * value1;
	}
};

int main() {
	A a(10);

	int v = a(5);//a.operator()(5);
	cout << v << endl;	
	
	int v1 = a(5,10);//a.operator()(5);
	cout << v1 << endl;
}