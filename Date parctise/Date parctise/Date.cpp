#include <iostream>
#include "Date.h"

using namespace std;

Date::Date(int m, int d, int y)
{
	setMonth(m);
	setDay(d);
	setYear(y);
}
void Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
	{
		month = m;
	}
	else
	{
		month = 1;
	}
}
int Date::getMonth(void)
{
	return month;
}
void Date::setDay(int d)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (d >= 1 && d <= 31)
		{
			day = d;
		}
		else
		{
			day = 0;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (d >= 1 && d <= 30)
		{
			day = d;
		}
		else
		{
			day = 0;
		}
	}
	else
	{
		if (d >= 1 && d <= 28)
		{
			day = d;
		}
		else
		{
			day = 0;
		}
	}
}
int Date::getDay(void)
{
	return day;
}
void Date::setYear(int y)
{
	year = y;
}
int Date::getYear(void)
{
	return year;
}
void Date::displayDate(void)
{
	cout << month << "/" << day << "/" << year << endl;
}