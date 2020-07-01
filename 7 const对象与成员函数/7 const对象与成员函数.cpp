#include <iostream>
#include "app.h"

class Person {
private:
    int age = 0;
    const int total = 0;
public:
    //静态常量
    static const int sum;

    Person(int _age,int _total = 0):age(_age), total(_total){}

    //显示,但无法修改
    void show() const {
        //age = 10;//编译器报错
        //getAge();//也不能调用类中任何非const成员函数。 
        std::cout << "age:" << age << std::endl;
    }

    //const 编译器报错 无法返回可修改的引用
    int& getAge() /*const*/{
        //编译器报错
        return age;
    }
    
    int setAge(int _age){
        age = age;
        return age;
    }
};

//静态常量初始化
const int Person::sum = 10;

//声明其他文件的函数
void ShowAppVer();

int main()
{    
    //非const 对象 可调用 有无const修饰的
    Person p(100);
    p.show();

    //返回引用
    int& age = p.getAge();
    age++;

    //返回引用 直接++
    p.getAge()++;
    p.show();

    //因为age 是 P::age引用。所以跟着变
    std::cout << age << std::endl;

    //const 对象 只能调用 const安全的
    const Person per(200);
    per.show();                 //可以调 const修饰的安全的函数
    //per.getAge()++;           //不可调用无 const 安全的函数
    //per.setAge(1);            //无const 修改值


    //-------------------
    //调用其他app的函数
    ShowAppVer();

    //使用头文件常量 和 变量
    std::cout << app_ver << std::endl;
    std::cout << ++app_max << std::endl<<std::endl;

    //------------------------
    //[1]常量
    const int ia = 1;
    //ia++;
    int const ib = 2;
    //ib++;


    //-------------------
    //[2]常量指针 和 指针常量
    int a = 123;
    int* pA = &a;
    (*pA)++;
    std::cout << a << std::endl;

    //-------------------------
    //指针指向的内容是常量不可变
    int b = 222;
    const int* pA1 = &a;            //const 修饰为 指针指向常量
    //(*pA1)++;                     //指针指向的值 无法修改
    std::cout << *pA1 << std::endl;

    pA1 = &b;                       //但是指针变量的值是可以改的
    std::cout << *pA1 << std::endl;

    //-------------------------
    //指针本身是常量不可变 
    int* const pA2 = &a;
    //pA2 = &b;                       //const 修饰为 指针常量


    //都不能变
    const int* const pA3 = &a;
    //pA3 = &b;
    //(*pA3)++;
    int* na = const_cast<int*>(pA3);    //const_cast转换指针
    (*na)++;
    std::cout << *pA3 << std::endl;

    //--------------------------
    //[3]

    std::cout << static_cast<int>(app_max) << std::endl;


}

