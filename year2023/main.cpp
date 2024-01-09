#include "year2023.h"

int main()
{
	setlocale(LC_ALL, "RU");

	vector<pair<int, int>> inputInterval =
	{
		{0, 20},
		{-100000000, 10},
		{30, 40},
	};

	for (pair<int, int> p : inputInterval)
	{
		cout << '[' << p.first << ", " << p.second << "] ";
	}
	cout << "\n\n";

	cout << sum_intervals(inputInterval) << endl;

	return 0;
}