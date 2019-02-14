#include "Header.h"
#include "multiply.h"
#include "ioMatrix.h"
#include "time.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	
	int choise = -1;


	while (choise != 0)
	{
		cout << "1 - �������� ������� " << endl;
		cout << "2 - ������ ������� � ���� time.txt " << endl;
		cout << "0 - ����� " << endl;
		cout << "�������� ����� ����: ";
		cin >> choise;
		cout << endl;

		switch (choise)
		{
		case 1:
		{
			int nA, mA, nB, mB;
			vector <vector<int>> aMatrix;
			vector <vector<int>> bMatrix;
			vector <vector<int>> product;

			cout << "������� ������ ������ �������: " << endl;
			cin >> nA >> mA;
			aMatrix = inputMatrix(nA, mA);

			cout << "������� ������ ������ �������: " << endl;
			cin >> nB >> mB;
			bMatrix = inputMatrix(nB, mB);
			cout << endl;

			try
			{
				product = multiplyStandart(aMatrix, bMatrix, nA, mA, nB, mB);
				cout << "��������: " << endl;
				outputMatrix(product);
				cout << endl;

				product = multiplyVinograd(aMatrix, bMatrix, nA, mA, nB, mB);
				cout << "��������: " << endl;
				outputMatrix(product);
				cout << endl;

				cout << "�������� ����������: " << endl;
				product = multiplyVinogradImprove(aMatrix, bMatrix, nA, mA, nB, mB);
				outputMatrix(product);
				cout << endl;
			}
			catch (invalid_argument& e)
			{
				cerr << e.what() << endl;
				system("pause");
				return -1;
			}
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