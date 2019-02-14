#include"Header.h"

// ������� ���������� ������ �������
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

//������� ���������� ���������
void sortc(vector<int> &num, int size)
{
	double fakt = 1.2473309; // ������ ����������
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
	// ���������� ���������
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


// ������� ���������� ������� ���������
void inclusionSort(vector<int> &num, int size)
{
	// ��� ���� ��������� ����� ����������
	for (int i = 1; i < size; i++)
	{
		int value = num[i]; // ���������� �������� ��������
		int index = i;     // � ��� ������
		while ((index > 0) && (num[index - 1] > value))
		{   // ������� ������ �������� � ����� ������� ���� ��� ������ index
			num[index] = num[index - 1];
			index--;    // ������� �������� � ������ �������
		}
		num[index] = value; // ��������������� ������� �������� �� �������������� �����
	}
}