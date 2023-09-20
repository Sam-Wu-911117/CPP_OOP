//Time.cpp
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Time.h"

using namespace std;

Time::Time(int h, int m, int s)
{
	Time::setTime(h, m, s);
}

//set funtion
void Time::setTime(int h, int m , int s)
{
	hour = h;
	minute = m;
	second = s;
}

void Time::setHour(int h)
{
	if (h >= 0 && h < 24)
	{
		hour = h;
	}
	else
		throw invalid_argument("小時數必須在0至23之間");
}
void Time::setMinute(int m)
{
	if (m >= 0 && m < 60)
	{
		minute = m;
	}
	else
		throw invalid_argument("分鐘數必須在0至59之間");
}
void Time::setSecond(int s)
{
	if (s >= 0 && s < 60)
	{
		second = s;
	}
	else
		throw invalid_argument("秒鐘數必須在0至59之間");
}

//get funtion
unsigned int Time::getHour() const
{
	return hour;
}
unsigned int Time::getMinute() const
{
	return minute;
}
unsigned int Time::getSecond() const
{
	return second;
}

void Time::printUniversal() const
{
	cout << setfill('0') << setw(2) << getHour() << ":" << setw(2) << getMinute() << ":" << setw(2) << getSecond();
}

void Time::printStandard() const
{
	cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":" << setfill('0') << setw(2) << getMinute() << ":" << setw(2) << getSecond() << (hour < 12 ? " AM" : " PM");
}

void Time::tick()
{
	int tempSecond = getSecond();
	int tempMinute = getMinute();
	int tempHour = getHour();

	if (tempSecond < 59)
	{
		setSecond(tempSecond + 1);
	}
	else
	{
		setSecond(0);
		//進位到分
		//判斷分
		if (tempMinute < 59)
		{
			setMinute(tempMinute + 1);
		}
		else
		{
			setMinute(0);
			if (tempHour < 23)
			{
				setHour(tempHour + 1);
			}
			else
			{
				setHour(0);
			}
		}
	}
}