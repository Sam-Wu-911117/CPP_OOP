#include <iostream>

using namespace std;

//��̤j���]�ƨ禡 
unsigned int gcd(int a, int b)
{
	//����۰������bb = 0
	if (b == 0)
	{
		return a;
	}

	//�����i������۰��k����b = 0
	else
	{
		return gcd(b, a % b);
	}
}


int main()
{
	//�w�qX�BY����ܼ�
	int x = 0;
	int y = 0;

	//���sX�Ȫ��ܼ�
	int memory = 0;

	//��JX�BY��ӭ�
	cout << "�п�J��ӼƦr" << endl;
	cin >> x >> y;
	
	//�ˬdx�O�_�j��Y
	if (x >= y)
	{
		//�L�X�̤j���]��
		cout << "�̤j���]�Ƭ�: " << gcd(x, y) << endl;

		system("pause");
	}
	else
	{
		//XY�ȥ洫
		memory = x;
		x = y;
		y = memory;

		//�L�X�̤j���]��
		cout << "�̤j���]�Ƭ�: " << gcd(x, y) << endl;

		system("pause");
	}


	

}