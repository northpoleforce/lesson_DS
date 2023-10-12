#include <iostream>
#include <cstdio>

using namespace std;

int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
class Date {
private:
	int year, month, day;
public:
	Date();                             // 缺省构造函数，给year、month、day分别赋值为1900、1、1
	Date(int y, int m, int d);          // 带参构造函数，给year、month、day分别赋参数的值
	int getYear();                      // 返回当前日期的年份
	int getMonth();                     // 返回当前日期的月份
	int getDay();                       // 返回当前日期的日
	void setDate(int y, int m, int d);  // 按参数重设日期的值
	void print();
	void addOneDay();                   // 在当前日期上加一天
};
Date::Date(): year(1900),month(1),day(1){}
Date::Date(int y, int m, int d): year(y), month(m), day(d) {}
int Date::getYear() { return year; }
int Date::getMonth() { return month; }
int Date::getDay() { return day; }
void Date::setDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
void Date::print()
{
	printf("%d/%02d/%02d\n", year, month, day);
}
void Date::addOneDay()
{
	day += 1;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		days[2] = 29;
	else
		days[2] = 28;
	if (day > days[month]) {
		day = 1;
		month += 1;
	}
	if (month > 12) {
		month = 1;
		year += 1;
	}
}

int main()
{
	int t; cin >> t;
	int y, m, d;
	Date date;
	for (int i = 0; i < t; ++i)
	{
		cin >> y >> m >> d;
		if (i % 2 == 0)
		{
			Date date(y, m, d);
			cout << "Today is ";
			date.print();
			cout << "Tomorrow is ";
			date.addOneDay(); date.print();
		}
		else
		{
			date.setDate(y, m, d);
			cout << "Today is ";
			date.print();
			cout << "Tomorrow is ";
			date.addOneDay(); date.print();
		}
	}
	return 0;
}