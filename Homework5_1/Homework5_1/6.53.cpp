#include <iostream>
#include "6.53.h"

using namespace std;

int main()
{
	//�p��Int�ۭ�
	int Int1, Int2;

	cout << "Input two integer values: " << endl;
	cin >> Int1 >> Int2;

	cout << "�ۭ����G��: " << Product(Int1, Int2) << endl;

	//�p��long�ۭ�
	long Long1, Long2;

	cout << "Input two Longinteger values: " << endl;
	cin >> Long1 >> Long2;

	cout << "�ۭ����G��: " << Product(Long1, Long2) << endl;

	//�p��double�ۭ�
	double Double1, Double2;

	cout << "Input two doublenumber values: " << endl;
	cin >> Double1 >> Double2;

	cout << "�ۭ����G��: " << Product(Double1, Double2) << endl;

	system("pause");
}