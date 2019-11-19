#include <iostream>
using namespace std;

class A {
	//friend A operator+(A& a1, A& a2);
private:
	int m_a;
	int m_b;
public:
	A(int a, int b) :m_a(a), m_b(b) {

	}

	void show() {
		cout << "m_a = " << m_a << " m_b = " << m_b << endl;
	}

	//成员函数 友元
	A operator+(A& other) {
		A temp(m_a + other.m_a, m_b + other.m_b);
		return temp;
	}
};

//全局函数 友元
#if 0
A operator+(A& a1, A& a2) {
	A temp(a1.m_a + a2.m_a, a1.m_b + a2.m_b);
	return temp;
}
#endif

int main() {

	A a1(1,2);
	A a2(1,2);

	//=号重载
	//operator+(a1,a2); 全局
	//a1.operator+(a2); 成员
	A a3 = a1 + a2;
	a3.show();

	A a4 = a1.operator+(a2);
	a4.show();

	//等价于(全局)
	//A a4 = operator+(a1,a2);
	//a4.show();

	//---------------------------------
	//操作符重载的规则

	//[1]不能重载的： .(成员选择符)   .* （成员对象选择符）   ::（域解析符）  ?: (条件操作符)
	//[2]可重载：new new[] delete delete[] + - * / % ^ & | ~ ! = < > += -= *= /= %= ^= &= |= << >> <<= >>= == != <= >= && || ++ -- , ->* -> () 函数调用符合  []下标符号
	//[3]不能改变运算操作个数: + 就是2个参数
	//[4]不能改变优先级： 例如： a1+a2*a3   
	//[5]不会改变结合性：a1 = a2 = a3  从左往右
	//[6]操作符不能有默认参数
	//[7]操作符重载至少有一个自定义类型：错误举例： operator+(int a,int b);没意义
	//[8]类对象重载的2个操作符例外： = 号  和  & 取地址
	//[9]重载操作符的功能与操作符功能一致：例如： +  就是 加法
	//[10]重载 是全局函数（友元函数），也可以是成员函数
}