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
		cout << "1 - Проверка методов " << endl;
		cout << "2 - Замеры времени в файл time.txt " << endl;
		cout << "0 - Выход " << endl;
		cout << "Выберите пункт меню: ";
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

			cout << "Введите размер первой матрицы: " << endl;
			cin >> nA >> mA;
			aMatrix = inputMatrix(nA, mA);

			cout << "Введите размер второй матрицы: " << endl;
			cin >> nB >> mB;
			bMatrix = inputMatrix(nB, mB);
			cout << endl;

			try
			{
				product = multiplyStandart(aMatrix, bMatrix, nA, mA, nB, mB);
				cout << "Стандарт: " << endl;
				outputMatrix(product);
				cout << endl;

				product = multiplyVinograd(aMatrix, bMatrix, nA, mA, nB, mB);
				cout << "Виноград: " << endl;
				outputMatrix(product);
				cout << endl;

				cout << "Виноград улучшенный: " << endl;
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