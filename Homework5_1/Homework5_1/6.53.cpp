#include <iostream>
#include "6.53.h"

using namespace std;

int main()
{
	//計算Int相乘
	int Int1, Int2;

	cout << "Input two integer values: " << endl;
	cin >> Int1 >> Int2;

	cout << "相乘結果為: " << Product(Int1, Int2) << endl;

	//計算long相乘
	long Long1, Long2;

	cout << "Input two Longinteger values: " << endl;
	cin >> Long1 >> Long2;

	cout << "相乘結果為: " << Product(Long1, Long2) << endl;

	//計算double相乘
	double Double1, Double2;

	cout << "Input two doublenumber values: " << endl;
	cin >> Double1 >> Double2;

	cout << "相乘結果為: " << Product(Double1, Double2) << endl;

	system("pause");
}