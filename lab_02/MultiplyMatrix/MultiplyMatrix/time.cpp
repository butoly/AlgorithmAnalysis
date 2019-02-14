#include "Header.h"
#include "multiply.h"
#include "ioMatrix.h"

#define COUNT 10 // Количество замеров

using namespace std;

vector<vector<int>> get_random(int n, int m)
{
	vector <vector<int>> product(n);
	for (int i = 0; i < n; ++i)
	{
		product[i].resize(m);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			product[i][j] = rand() % 100 - 50;
		}
	}
	return product;
}

void time()
{
	setlocale(LC_ALL, "ru");
	ofstream fout("time.txt");

	unsigned __int64 start;
	unsigned __int64 end;

	vector<vector<int>> test1;
	vector<vector<int>> test2;

	int z = 100;
	while (z != 1100)
	{
		fout << "Размерность матриц " << z << endl;
		test1 = get_random(z, z);
		//outputMatrix(test1);

		test2 = get_random(z, z);
		//outputMatrix(test2);

		
		fout << "Cтандартное перемножение матрицы:" << endl;
		start = __rdtsc();
		for (int i = 0; i < COUNT; ++i)
		{
			multiplyStandart(test1, test2, z, z, z, z);
		}
		end = __rdtsc();
		fout << (end - start) / COUNT << endl;
		
		
		
		fout << "Алгоритм Винограда:" << endl;
		start = __rdtsc();
		for (int i = 0; i < COUNT; ++i)
		{
			multiplyVinograd(test1, test2, z, z, z, z);
		}
		end = __rdtsc();
		fout << (end - start) / COUNT << endl;

		fout << "Улучшенный алгоритм Винограда:" << endl;
		start = __rdtsc();
		for (int i = 0; i < COUNT; ++i)
		{
			multiplyVinogradImprove(test1, test2, z, z, z, z);
		}
		end = __rdtsc();
		fout << (end - start) / COUNT << endl;
		fout << endl;

		cout << z << " compleate" << endl;

		if (z % 100 == 0)
			z += 1;
		else if (z % 100 == 1)
			z += 99;

		//z += 100;
	}
}