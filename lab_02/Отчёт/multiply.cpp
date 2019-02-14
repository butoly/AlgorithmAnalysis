#include "Header.h"  
#include "ioMatrix.h"

using namespace std;

vector <vector<int>> multiplyStandart(vector <vector <int>> aMatrix, \
					vector <vector <int>> bMatrix, \ 
					  int nA, int mA, int nB, int mB)
{	
	vector <vector <int>> product(nA);

	for (int i = 0; i < nA; ++i)
	{
		product[i].resize(mB);
	}

	for (int row = 0; row < nA; row++)
	{
		for (int col = 0; col < mB; col++)
		{
			for (int inner = 0; inner < mA; inner++)
			{
				product[row][col] += aMatrix[row][inner] * \
						bMatrix[inner][col];
			}
		}
	}
	return product;
}

vector <vector<int>> multiplyVinograd(vector <vector <int>> aMatrix, \
					  vector <vector <int>> bMatrix, \ 
					    int nA, int mA, int nB, int mB)
{
	int d;
	vector<int> rowFactor(nA);
	vector<int> columnFactor(mB);
	
	vector<vector<int>> product(nA);
	for (int i = 0; i < nA; ++i)
	{
		product[i].resize(mB);
	}

	d = nB / 2;
	
	for (int i = 0; i < nA; ++i)
	{
		for (int j = 0; j < d; ++j)
		{
			rowFactor[i] = rowFactor[i] + (aMatrix[i][2*j] * \
							aMatrix[i][2*j + 1]);
		}
	}

	for (int i = 0; i < mB; ++i)
	{
		for (int j = 0; j < d; ++j)
		{
			columnFactor[i] = columnFactor[i] + \
					   (bMatrix[2 * j][i] * \
					     bMatrix[2 * j + 1][i]);
		}
	}

	for (int i = 0; i < nA; ++i)
	{
		for (int j = 0; j < mB; ++j)
		{
			product[i][j] = -rowFactor[i] - \
						columnFactor[j];
			for (int k = 0; k < d; ++k)
			{
				product[i][j] = product[i][j] + \
						    ( \
						       (aMatrix[i][2 * k] + \
						       bMatrix[2 * k + 1][j]) \
						           * \
						       (aMatrix[i][2 * k + 1] + \
						       bMatrix[2 * k][j]) \
						     );
			}
		}
	}

	if (nB % 2 != 0)
	{
		for (int i = 0; i < nA; ++i)
		{
			for (int j = 0; j < mB; ++j)
			{
				product[i][j] = product[i][j] + \
 						(aMatrix[i][nB - 1] * \
						    bMatrix[nB - 1][j]);
			}
		}
	}
	
	return product;
}

vector <vector<int>> multiplyVinogradImprove(vector <vector <int>> aMatrix, \ 
					      vector <vector <int>> bMatrix, \
					       int nA, int mA, int nB, int mB)
{
	int d;
	vector<int> rowFactor(nA);
	vector<int> columnFactor(mB);

	vector<vector<int>> product(nA);
	for (int i = 0; i < nA; ++i)
	{
		product[i].resize(mB);
	}

	d = nB / 2;

	for (int i = 0; i < nA; ++i)
	{
		for (int j = 0; j < d; ++j)
		{
			rowFactor[i] += (aMatrix[i][(j<<1)] * \
						aMatrix[i][(j<<1)|1]);
		}
	}

	for (int i = 0; i < mB; ++i)
	{
		for (int j = 0; j < d; ++j)
		{
			columnFactor[i] += (bMatrix[(j<<1)][i] * \
						bMatrix[(j<<1)|1][i]);
		}
	}

	if (nB % 2 == 0)
	{
		for (int i = 0; i < nA; ++i)
		{
			for (int j = 0; j < mB; ++j)
			{
				product[i][j] = -rowFactor[i] - columnFactor[j];
				for (int k = 0; k < d; ++k)
				{
					product[i][j] += ((aMatrix[i][(k << 1)] + \
					  bMatrix[(k << 1) | 1][j])* \
					   (aMatrix[i][(k << 1) | 1] \
						 + bMatrix[(k << 1)][j]));
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < nA; ++i)
		{
			for (int j = 0; j < mB; ++j)
			{
				product[i][j] = -rowFactor[i] - columnFactor[j];
				for (int k = 0; k < d; ++k)
				{
					product[i][j] += ((aMatrix[i][(k << 1)] + \
					  bMatrix[(k << 1) | 1][j])*\
					   (aMatrix[i][(k << 1) | 1] + \
    					  bMatrix[(k << 1)][j]) + \
						    (aMatrix[i][nB - 1] * \
						      bMatrix[nB - 1][j]));
				}
			}
		}
	}

	return product;
}
