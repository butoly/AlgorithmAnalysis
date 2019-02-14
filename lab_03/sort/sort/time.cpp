#include "Header.h"
#include "sort.h"

#define COUNT 100

vector<int> get_random(int n)
{
	vector<int> product(n);

	for (int i = 0; i < n; ++i)
	{
		product[i] = rand() % 100 - 50;
	}

	return product;
}

void time()
{
	setlocale(LC_ALL, "ru");
	ofstream fout("time.txt");

	unsigned __int64 start;
	unsigned __int64 end;

	unsigned __int64 sub_start;
	unsigned __int64 sub_end;

	vector<vector<int>> test1;
	vector<vector<int>> test2;

	int z = 1000;
	while (z != 11000)
	{
		fout << "Размерность массива " << z << endl;
		
		vector<int> test = get_random(z);


		fout << "Cортировка прямым выбором: " << endl;
		start = __rdtsc();
		for (int i = 0; i < COUNT; ++i)
		{
			vector<int> test1(test);
			selectionSort(test1, test1.size());
		}
		end = __rdtsc();
		fout << (end - start) / COUNT << endl;


		fout << "Сортировка расчёской: " << endl;
		start = __rdtsc();
		for (int i = 0; i < COUNT; ++i)
		{
			vector<int> test2(test);
			sortc(test2, test2.size());
		}
		end = __rdtsc();
		fout << (end - start) / COUNT << endl;

		fout << "Сортировка прямыми включениями: " << endl;
		start = __rdtsc();
		for (int i = 0; i < COUNT; ++i)
		{
			vector<int> test3(test);
			inclusionSort(test3, test3.size());
		}
		end = __rdtsc();
		fout << (end - start) / COUNT << endl;
		fout << endl;


		cout << "compleate" << z << endl;
		z += 1000;
	}
}