#include "Header.h"

using namespace std;

vector <vector <int>> inputMatrix(int n, int m)
{
	vector <vector <int>> matrix(n);
	for (int i = 0; i < n; i++)
	{
		matrix[i].resize(m);
	}

	cout << "¬ведите матрицу: " << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> matrix[i][j];
		}
	}

	return matrix;
}

void outputMatrix(vector <vector <int>> matrix)
{
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}