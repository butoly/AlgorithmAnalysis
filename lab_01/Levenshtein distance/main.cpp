// main.cpp
//

#include "pch.h"
#include "time.h"
#include "levenshtein distance.h";

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choise = -1;
	while (choise != 0)
	{
		cout << "1 - Проверка  расстояний" << endl;
		cout << "2 - Замеры времени в файл time.txt " << endl;
		cout << "0 - Выход " << endl;
		cout << "Выберите пункт меню: ";
		cin >> choise;
		cout << endl;

		switch (choise)
		{
		case 1:
		{
			string src;
			string dst;

			int distance = 0;
			int dam_distance = 0;
			int rec_distance = 0;

			cout << "Введите первое слово: " << endl;
			//getline(cin, src);
			cin >> src;
			cout << "Введите второе слово: " << endl;
			//getline(cin, dst);
			cin >> dst;

			distance = levenshtein_distance(src, dst);
			dam_distance = damerau_levenshtein_distance(src, dst);
			rec_distance = recur_Lev(src, dst);
			cout << endl;
			cout << "Расстояние Левенштейна: " << distance << endl;
			cout << "Расстояние Дамерау - Левенштейна: " << dam_distance << endl;
			cout << "Расстояние Левенштейна рекурсивно: " << rec_distance << endl;
			cout << endl;
			break;

		}
		case 2:
		{
			time(); // Замеры
			break;
		}
		case 0:
		{
			break;
		}
		}
	}
	return 0;
}