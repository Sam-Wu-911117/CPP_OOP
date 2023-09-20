//main
#include "Complex.h"
#include <iostream>

using namespace std;

int main()
{
	Complex x(4.3, 8.2);
	Complex y(3.3, 1.1);
	Complex z(0, 0);

	z = x + y;
	cout << "結果是: " << endl;
	cout << x << "+" << y << "=" << z << endl;

	z = x - y;
	cout << "結果是: " << endl;
	cout << x << "-" << y << "=" << z << endl;
	cout << "請輸入複數x的實部 虛部" << endl;
	cin >> x;
	cout << x << endl;
	z = x * y;
	cout << x << "*" << y << "=" << z << endl;
	cout << "x是否等於y: ";
	if (x == y)
	{
		cout << "是" << endl;
	}
	else
	{
		cout << "不是" << endl;
	}
	cout << "x是否不等於y: ";
	if (x != y)
	{
		cout << "是" << endl;
	}
	else
	{
		cout << "不是" << endl;
	}
	system("pause");
}
