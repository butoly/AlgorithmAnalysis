#include "Header.h"

vector<int> inputArray()
{
	int size = 0;
	cout << "������� ������ �������: ";
	cin >> size;
	int num;
	vector<int> array;
	cout << "������� ������ ����� �����: ";
	for (int i = 0; i < size; ++i)
	{
		cin >> num; 
		array.push_back(num);
	}

	return array;
}

void outputArray(vector <int> &array)
{
	for (int i = 0; i < array.size(); ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}