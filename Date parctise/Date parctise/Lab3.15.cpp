#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	Date testDate;
	int day;
	int month;
	int year;

	cout << "��J���~������ܦ�1" << endl;

	cout << "��J���~������ܦ�0" << endl;

	cout << "�п�J���: ";
	cin >> month;
	testDate.setMonth(month);

	cout << "�п�J���: ";
	cin >> day;
	testDate.setDay(day);

	cout << "�п�J�~��: ";
	cin >> year;
	testDate.setYear(year);

	testDate.displayDate();

	//============ ����get�禡 ===========
	cout << "����O: " << testDate.getMonth() << endl;
	cout << "����O: " << testDate.getDay() << endl;
	cout << "�~���O: " << testDate.getYear() << endl;


	system("pause");
}