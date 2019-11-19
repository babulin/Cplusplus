#include <iostream>
using namespace std;

///-------------------------------------------------------
//���ļ�������

//PointManager ����Point  ������������
class Point;

//��ΪPoint����PointManager ���Է�ǰ��
class PointManager {
public:
	double MDistance(Point& p1, Point& p2);
};

//����point
class Point {
	//��Ԫ����������ȫ�ֺ���
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

//PointManager���Ա������Ϊ��Ԫ����
//���գ���������
double PointManager::MDistance(Point& p1, Point& p2)
{
	double dis;
	int d_x = p1.x - p2.x;
	int d_y = p1.y - p2.y;

	//���ɶ���
	dis = sqrt(d_x * d_x + d_y * d_y);
	return dis;
}

//ȫ�ֺ�����point����Ԫ��������Ȩ���ʣ�˽�б���
double Distance(Point& p1, Point& p2)
{
	double dis;
	int d_x = p1.x - p2.x;
	int d_y = p1.y - p2.y;

	//���ɶ���
	dis = sqrt(d_x * d_x + d_y * d_y);
	return dis;
}


int main() {
	Point p1(1, 2);
	Point p2(2, 2);
	cout << "�����ǣ�" << Distance(p1, p2) << endl;

	PointManager pm;
	cout << "�����ǣ�" << pm.MDistance(p1, p2) << endl;
}
