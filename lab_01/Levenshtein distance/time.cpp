//#include <chrono>
#include "pch.h"
#include "levenshtein distance.h"

#define COUNT 100 // Количество замеров

using namespace std;

string get_random(int len)
{
	string s;

	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	
	for (int i = 0; i < len; ++i)
	{
		s += alphanum[rand() % (sizeof(alphanum) - 1)];
	}
	return s;
}

void time()
{
	setlocale(LC_ALL, "ru");
	ofstream fout("time.txt");

	string src;
	string dst;

	unsigned __int64 start;
	unsigned __int64 end;

	for (int j = 1; j <= 10; j += 1)
	{
		src = get_random(j);
		dst = get_random(j);

		fout << "Длина строки " << j << endl;
		
		
		fout << "Алгоритм Левенштейна:" << endl;
		start = __rdtsc();
		for (int i = 0; i < COUNT; ++i)
		{
			levenshtein_distance(src, dst);
		}
		end = __rdtsc();
		fout << (end - start) / COUNT << endl;
		
		
		fout << "Алгоритм Дамерау-Левенштейна:" << endl;
		start = __rdtsc();
		for (int i = 0; i < COUNT; ++i)
		{
			damerau_levenshtein_distance(src, dst);
		}
		end = __rdtsc();
		fout << (end - start) / COUNT << endl;
		

		
		fout << "Алгоритм Левенштейна рекурсивно:" << endl;
		start = __rdtsc();
		for (int i = 0; i < COUNT; ++i)
		{
			recur_Lev(src, dst);
		}
		end = __rdtsc();
		fout << (end - start) / COUNT << endl;
		fout << endl;
		
	}
}
