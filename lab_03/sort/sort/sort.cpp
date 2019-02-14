#include"Header.h"

// Функция сортировки прямым выбором
void selectionSort(vector<int> &num, int size)
{
	int min, temp;
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (num[j] < num[min])
				min = j;
		}
		temp = num[i];
		num[i] = num[min];
		num[min] = temp;
	}
}

//Функция сортировки расчёской
void sortc(vector<int> &num, int size)
{
	double fakt = 1.2473309; // фактор уменьшения
	double step = size - 1;

	while (step >= 1)
	{
		for (int i = 0; i + step < size; ++i)
		{
			if (num[i] > num[i + step])
			{
				swap(num[i], num[i + step]);
			}
		}
		step /= fakt;
	}
	// сортировка пузырьком
	for (int i = 0; i < size - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (num[j] > num[j + 1]) {
				swap(num[j], num[j + 1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;
	}
}


// Функция сортировки прямыми вставками
void inclusionSort(vector<int> &num, int size)
{
	// Для всех элементов кроме начального
	for (int i = 1; i < size; i++)
	{
		int value = num[i]; // запоминаем значение элемента
		int index = i;     // и его индекс
		while ((index > 0) && (num[index - 1] > value))
		{   // смещаем другие элементы к концу массива пока они меньше index
			num[index] = num[index - 1];
			index--;    // смещаем просмотр к началу массива
		}
		num[index] = value; // рассматриваемый элемент помещаем на освободившееся место
	}
}