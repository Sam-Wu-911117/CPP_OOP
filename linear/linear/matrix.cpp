#include <iostream>
using namespace std;

int main()
{
	int Row = 1; //m列
	int Column = 1; //n行
	cout << "請輸入你的矩陣要多少列跟行:";
	cin >> Row >> Column;
	double** array;
	array = new double* [Row];
	//此矩陣有 n 個列(rows); 先 new 出 n 個 int *
	for (int i = 0; i < Row; i++)
	{
		array[i] = new double[Column];
		//每一列有 m 行(columns); array[i] 指向新 new 出的 m 個 int
	}
	//把值填入矩陣內
	cout << "填入矩陣的值:\n";
	for (int row = 0; row < Row; ++row)
	{
		for (int column = 0; column < Column; ++column)
		{
			cin >> array[row][column]; //把值填入矩陣內
		}
	}
	//印出那個矩陣
	cout << "運算前的矩陣:\n";
	for (int m = 0; m < Row; ++m)
	{
		for (int n = 0; n < Column; ++n)
		{
			cout << array[m][n] << "\t";
		}
		cout << endl;
	}
	//計算Row-Echelon Form
	double memory; //記憶
	int time = 1; //記數
	double times;//倍率
	//判斷row和column誰大
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
		//最前面數字是0和其他列交換
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
		//確認最前面換完後如果還是是0直接跳過
		if (array[i][i] != 0)
		{
			//讓前面數字變成1
			memory = array[i][i];
			for (int j = 0; j < Column; ++j)
			{
				array[i][j] = array[i][j] / memory;
			}
			//把下面數字變成0
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
	
	//印出Row-Echelon Form結果
	cout << "Row-Echelon Form矩陣:\n";
	for (int row = 0; row < Row; ++row)
	{
		for (int column = 0; column < Column; ++column)
		{
			cout << array[row][column] << "\t";
		}
		cout << endl;
	}

	//計算Redured Row-Echelon Form
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
	//印出Redured Row-Echelon Form結果
	cout << "Redured Row-Echelon Form矩陣:\n";
	for (int row = 0; row < Row; ++row)
	{
		for (int column = 0; column < Column; ++column)
		{
			cout << array[row][column] << "\t";
		}
		cout << endl;
	}
	// 動態矩陣還記憶體
	for (int i = 0; i < Row; i++)
	{
		delete[] array[i];
	}
	delete[] array;
	system("pause");
}
