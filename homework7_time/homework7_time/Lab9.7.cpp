#include <iostream>
#include "Time.h"

using namespace std;

const int MAX_TICK = 100;

int main()
{
	Time t(23, 58, 50);
	int ticks;
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	cout << "請輸入要設定的時: ";
	cin >> hours;
	cout << "請輸入要設定的分: ";
	cin >> minutes;
	cout << "請輸入要設定的秒: ";
	cin >> seconds;
	t.setHour(hours);
	t.setMinute(minutes);
	t.setSecond(seconds);

	for (ticks = 1; ticks < MAX_TICK; ++ticks)
	{
		t.printUniversal();
		cout << endl;
		t.printStandard();
		cout << endl;
		t.tick();
	}
}