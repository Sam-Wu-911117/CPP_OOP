#include <iostream>

using namespace std;

void mystery1(char*, char*);

int main()
{
	//�w�q��Ӱ}�C
	char string1[80];
	char string2[80];

	cout << "Enter two strings: ";

	cin.getline(string1, 80, '\n');
	cin.getline(string2, 80, '\n');

	//�Ψ禡�ഫ�j�p�g
	mystery1(string1, string2);
	
	cout << string1 << string2 << endl;

	system("pause");
	

}

void mystery1(char* s1, char* s2)
{
	int i = 0;

	for (; i < 80; i++)
	{
		if (s1[i] >= 'a' && s1[i] <= 'z')
		{
			s1[i] -= 32;
		}

		if (s2[i] >= 'a' && s2[i] <= 'z')
		{
			s2[i] -= 32;
		}
	}
}