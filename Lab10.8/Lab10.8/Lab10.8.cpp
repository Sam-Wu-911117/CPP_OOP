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
	cout << "���G�O: " << endl;
	cout << x << "+" << y << "=" << z << endl;

	z = x - y;
	cout << "���G�O: " << endl;
	cout << x << "-" << y << "=" << z << endl;
	cout << "�п�J�Ƽ�x���곡 �곡" << endl;
	cin >> x;
	cout << x << endl;
	z = x * y;
	cout << x << "*" << y << "=" << z << endl;
	cout << "x�O�_����y: ";
	if (x == y)
	{
		cout << "�O" << endl;
	}
	else
	{
		cout << "���O" << endl;
	}
	cout << "x�O�_������y: ";
	if (x != y)
	{
		cout << "�O" << endl;
	}
	else
	{
		cout << "���O" << endl;
	}
	system("pause");
}
