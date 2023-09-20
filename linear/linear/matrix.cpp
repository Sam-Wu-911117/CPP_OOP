#include <iostream>
using namespace std;

int main()
{
	int Row = 1; //m�C
	int Column = 1; //n��
	cout << "�п�J�A���x�}�n�h�֦C���:";
	cin >> Row >> Column;
	double** array;
	array = new double* [Row];
	//���x�}�� n �ӦC(rows); �� new �X n �� int *
	for (int i = 0; i < Row; i++)
	{
		array[i] = new double[Column];
		//�C�@�C�� m ��(columns); array[i] ���V�s new �X�� m �� int
	}
	//��ȶ�J�x�}��
	cout << "��J�x�}����:\n";
	for (int row = 0; row < Row; ++row)
	{
		for (int column = 0; column < Column; ++column)
		{
			cin >> array[row][column]; //��ȶ�J�x�}��
		}
	}
	//�L�X���ӯx�}
	cout << "�B��e���x�}:\n";
	for (int m = 0; m < Row; ++m)
	{
		for (int n = 0; n < Column; ++n)
		{
			cout << array[m][n] << "\t";
		}
		cout << endl;
	}
	//�p��Row-Echelon Form
	double memory; //�O��
	int time = 1; //�O��
	double times;//���v
	//�P�_row�Mcolumn�֤j
	int Small;
	if (Row >= Column)
	{
		Small = Column;
	}
	else
	{
		Small = Row;
	}
	for (int i = 0; i < Small; ++i)
	{
		//�̫e���Ʀr�O0�M��L�C�洫
		while (array[i][i] == 0 && time + i < Row)
		{
			for (int j = 0; j < Column; ++j)
			{
				memory = array[i + time][j];
				array[i + time][j] = array[i][j];
				array[i][j] = memory;
			}
			time++;
		}
		//�T�{�̫e��������p�G�٬O�O0�������L
		if (array[i][i] != 0)
		{
			//���e���Ʀr�ܦ�1
			memory = array[i][i];
			for (int j = 0; j < Column; ++j)
			{
				array[i][j] = array[i][j] / memory;
			}
			//��U���Ʀr�ܦ�0
			for (int j = i + 1; j < Row; ++j)
			{
				times = array[j][i];
				for (int k = 0; k < Column; ++k)
				{
					array[j][k] = array[j][k] - array[i][k] * times;
				}
			}
		}
	}
	
	//�L�XRow-Echelon Form���G
	cout << "Row-Echelon Form�x�}:\n";
	for (int row = 0; row < Row; ++row)
	{
		for (int column = 0; column < Column; ++column)
		{
			cout << array[row][column] << "\t";
		}
		cout << endl;
	}

	//�p��Redured Row-Echelon Form
	for (int i = Row - 1; i >= 0; --i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			times = array[j][i];
			for (int k = 0; k < Column; ++k)
			{
				array[j][k] = array[j][k] - array[i][k] * times;
			}
		}
	}
	//�L�XRedured Row-Echelon Form���G
	cout << "Redured Row-Echelon Form�x�}:\n";
	for (int row = 0; row < Row; ++row)
	{
		for (int column = 0; column < Column; ++column)
		{
			cout << array[row][column] << "\t";
		}
		cout << endl;
	}
	// �ʺA�x�}�ٰO����
	for (int i = 0; i < Row; i++)
	{
		delete[] array[i];
	}
	delete[] array;
	system("pause");
}
