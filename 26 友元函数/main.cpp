#include <iostream>
using namespace std;

///-------------------------------------------------------
//多文件类声明

//PointManager 依赖Point  所以先声明；
class Point;

//因为Point依赖PointManager 所以放前面
class PointManager {
public:
	double MDistance(Point& p1, Point& p2);
};

//声明point
class Point {
	//友元函数：声明全局函数
	friend double  Distance(Point& p1, Point& p2);
	friend double PointManager::MDistance(Point& p1, Point& p2);
private:
	int x;
	int y;
public:
	Point(int _x, int _y);
};


///-------------------------------------------------------
Point::Point(int _x, int _y) {
	x = _x;
	y = _y;
}

//PointManager类成员函数做为友元函数
//风险：来回引用
double PointManager::MDistance(Point& p1, Point& p2)
{
	double dis;
	int d_x = p1.x - p2.x;
	int d_y = p1.y - p2.y;

	//勾股定理
	dis = sqrt(d_x * d_x + d_y * d_y);
	return dis;
}

//全局函数是point的友元函数；有权访问：私有变量
double Distance(Point& p1, Point& p2)
{
	double dis;
	int d_x = p1.x - p2.x;
	int d_y = p1.y - p2.y;

	//勾股定理
	dis = sqrt(d_x * d_x + d_y * d_y);
	return dis;
}


int main() {
	Point p1(1, 2);
	Point p2(2, 2);
	cout << "距离是：" << Distance(p1, p2) << endl;

	PointManager pm;
	cout << "距离是：" << pm.MDistance(p1, p2) << endl;
}
