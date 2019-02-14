#include "Header.h"
#include "sort.h"
#include "ioarray.h"
#include "time.h"

int main(void)
{
	setlocale(LC_ALL, "ru");

	int choise = -1;

	while (choise != 0)
	{
		cout << "1 - Проверка сортировок " << endl;
		cout << "2 - Замеры времени в файл time.txt " << endl;
		cout << "0 - Выход " << endl;
		cout << "Выберите пункт меню: ";
		cin >> choise;
		cout << endl;

		switch (choise)
		{
		case 1:
		{
			vector <int> array1;
			array1 = inputArray();
			vector<int> array2(array1);
			vector<int> array3(array1);

			cout << "Cортировка прямым выбором" << endl;
			selectionSort(array1, array1.size());
			outputArray(array1);
			cout << "Сортировка расчёской" << endl;
			sortc(array2, array2.size());
			outputArray(array2);
			cout << "Сортировка прямыми включениями" << endl;
			inclusionSort(array3, array3.size());
			outputArray(array3);
			cout << endl;
			
			break;
		}
		case 2:
		{
			time();
			break;
		}

		case 0:
		{
			break;
		}
		default:
			break;
		}
	}

	system("pause");
	return 0;
}