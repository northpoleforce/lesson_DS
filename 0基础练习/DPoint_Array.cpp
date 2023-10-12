#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>

using namespace std;

class Point
{
private:
	double x, y;
public:
	Point();
	Point(const Point &p);
	Point(double x_value, double y_value);      // 缺省构造函数，给 x, y 分别赋值为0
	~Point();                                   // 析构函数
	double getX();                              // 返回x的值
	double getY();                              // 返回y的值
	void setXY(double x1, double y1) { x = x1; y = y1; }
	void setX(double x_value);                  // 设置x的值
	void setY(double y_value);                  // 设置y的值
	double getDisTo(const Point& p);                  // 计算当前点到参数点p的距离
};
Point::Point(): x(0),y(0) {
	cout << "Constructor.\n";
}
Point::Point(const Point& p): x(p.x), y(p.y) {}
Point::Point(double x_value, double y_value) : x(x_value), y(y_value) {}
Point::~Point() {
	cout << "Distructor.\n";
}
double Point::getX() { return x; }
double Point::getY() { return y; }
void Point::setX(double x_value) { x = x_value; }
void Point::setY(double y_value) { y = y_value; }
double sqr(double x) { return x * x; }
double Point::getDisTo(const Point& p) {
	double dis = sqrt(sqr(p.x - x) + sqr(p.y - y));
	return dis;
}
void get_maxdis(int n, Point* p) {
	double res = 0;
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j)
			if (p[i].getDisTo(p[j]) > res) {
				res = p[i].getDisTo(p[j]);
				ans1 = i; ans2 = j;
			}
	cout << "The longeset distance is ";
	cout << fixed << setprecision(2) << res;
	printf(",between p[%d] and p[%d].\n", ans1, ans2);
	return;
}

int main()
{
	int t; cin >> t;
	int n, x, y;
	while (t--) {
		cin >> n;
		Point* p = new Point[n];
		for (int i = 0; i < n; ++i) {
			cin >> x >> y;
			p[i].setXY(x, y);
		}
		get_maxdis(n, p);
		delete[] p;
	}
	return 0;
}