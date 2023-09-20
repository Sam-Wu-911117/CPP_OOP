#include <iostream>

using namespace std;

//衡程そ计ㄧΑ 
unsigned int gcd(int a, int b)
{
	//劣锣埃挡b = 0
	if (b == 0)
	{
		return a;
	}

	//ぃ氨秈︽劣锣埃猭b = 0
	else
	{
		return gcd(b, a % b);
	}
}


int main()
{
	//﹚竡XYㄢ跑计
	int x = 0;
	int y = 0;

	//X跑计
	int memory = 0;

	//恶XYㄢ
	cout << "叫块ㄢ计" << endl;
	cin >> x >> y;
	
	//浪琩x琌Y
	if (x >= y)
	{
		//程そ计
		cout << "程そ计: " << gcd(x, y) << endl;

		system("pause");
	}
	else
	{
		//XYユ传
		memory = x;
		x = y;
		y = memory;

		//程そ计
		cout << "程そ计: " << gcd(x, y) << endl;

		system("pause");
	}


	

}