#include "pch.h"

using namespace std;

int min_3(int a, int b, int c)
{
	int min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return min;
}

int levenshtein_distance(const string & src, const string & dst)
{
	const int m = src.size();
	const int n = dst.size();

	if (m == 0)
		return n;
	if (n == 0)
		return m;

	vector <vector <int>> matrix(m + 1);

	for (int i = 0; i <= m; i++)
	{
		matrix[i].resize(n + 1);
		matrix[i][0] = i;
	}

	for (int i = 0; i <= n; i++)
	{
		matrix[0][i] = i;
	}

	int above_cell, left_cell, diagonal_cell, cost;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cost = src[i - 1] == dst[j - 1] ? 0 : 1;
			above_cell = matrix[i - 1][j];
			left_cell = matrix[i][j - 1];
			diagonal_cell = matrix[i - 1][j - 1];
			matrix[i][j] = min_3(above_cell + 1, left_cell + 1, diagonal_cell + cost);
		}
	}

	/*for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}*/

	return matrix[m][n];
}


int damerau_levenshtein_distance(const string & src, const string & dst)
{
	const int m = src.size();
	const int n = dst.size();

	if (m == 0)
		return n;
	if (n == 0)
		return m;

	vector <vector <int>> matrix(m + 1);

	for (int i = 0; i <= m; i++)
	{
		matrix[i].resize(n + 1);
		matrix[i][0] = i;
	}

	for (int i = 0; i <= n; i++)
	{
		matrix[0][i] = i;
	}

	int above_cell, left_cell, diagonal_cell, cost_replacement, cost_transposition, transposition_cell, dem_len;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cost_replacement = src[i - 1] == dst[j - 1] ? 0 : 1;
			above_cell = matrix[i - 1][j];
			left_cell = matrix[i][j - 1];
			diagonal_cell = matrix[i - 1][j - 1];


			cost_transposition = 2;
			if (i >= 2 and j >= 2)
			{
				transposition_cell = matrix[i - 2][j - 2];
				cost_transposition = src[i - 1] == dst[j - 2] and src[i - 2] == dst[j - 1] ? 1 : 2;
			}

			if (cost_transposition == 1)
			{
				matrix[i][j] = min_3(min(above_cell + 1, left_cell + 1), diagonal_cell + cost_replacement, transposition_cell + cost_transposition);
			}
			else if (cost_transposition == 2)
			{
				matrix[i][j] = min_3(above_cell + 1, left_cell + 1, diagonal_cell + cost_replacement);
			}
		}
	}

	/*
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}*/

	return matrix[m][n];
}

int recur_Lev(const string& src, const string& dst)
{
	int m = src.length();
	int n = dst.length();
	if (m == 1 && n == 1)
	{
		if (src == dst)
			return 0;
		else
			return 1;
	}
	else
	{
		if (m > n && n == 1)
			if (src.find_first_of(dst) == -1)
				return abs(m - n) + 1;
			else
				return abs(m - n);
		else if (n > m && m == 1)
			if (src.find_first_of(dst) == -1)
				return abs(m - n) + 1;
			else
				return abs(m - n);
	}

	int t;
	if (src[src.size() - 1] != dst[dst.size() - 1])
		t = 1;
	else
		t = 0;

	return min_3(recur_Lev(src.substr(0, m - 1), dst) + 1, recur_Lev(src, dst.substr(0, n - 1)) + 1, recur_Lev(src.substr(0, m - 1), dst.substr(0, n - 1)) + t);
}