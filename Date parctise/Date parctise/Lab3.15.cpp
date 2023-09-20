#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	Date testDate;
	int day;
	int month;
	int year;

	cout << "輸入錯誤的月份變成1" << endl;

	cout << "輸入錯誤的日期變成0" << endl;

	cout << "請輸入月份: ";
	cin >> month;
	testDate.setMonth(month);

	cout << "請輸入日期: ";
	cin >> day;
	testDate.setDay(day);

	cout << "請輸入年份: ";
	cin >> year;
	testDate.setYear(year);

	testDate.displayDate();

	//============ 測試get函式 ===========
	cout << "月份是: " << testDate.getMonth() << endl;
	cout << "日期是: " << testDate.getDay() << endl;
	cout << "年份是: " << testDate.getYear() << endl;


	system("pause");
}