#include "year2023.h"

/*
Напишите функцию с именем sumIntervals/sum_intervals, которая принимает массив интервалов и возвращает сумму всех длин интервалов.
Пересекающиеся интервалы следует учитывать только один раз.
Интервалы представлены парой целых чисел в виде массива. Первое значение интервала всегда будет меньше второго значения.
Пример интервала: [1, 5] — это интервал от 1 до 5. Длина этого интервала равна 4.

Пример пересекающихся интервалов:
[   [1, 4],
	[7, 10],
	[3, 5]    ]
Сумма длин этих интервалов равна 7. Поскольку [1, 4] и [3, 5] перекрываются, мы можем рассматривать интервал как [1, 5], длина которого равна 4.

Примеры:
sumIntervals([
	[1, 2],
	[6, 10],
	[11, 15]] ) => 9

sumIntervals([
	[1, 4],
	[7, 10],
	[3, 5]] ) => 7

sumIntervals([
	[1, 5],
	[10, 20],
	[1, 6],
	[16, 19],
	[5, 11]] ) => 19

sumIntervals([
	[0, 20],
	[-100000000, 10],
	[30, 40]] ) => 100000030

Тесты с большими интервалами:
Ваш алгоритм должен быть в состоянии обрабатывать большие интервалы. Все интервалы являются подмножествами диапазона [-1000000000, 1000000000].
*/

int sum_intervals(const vector<pair<int, int>>& intervals)
{
	vector<pair<int, int>> newItervals(intervals);
	sort(newItervals.begin(), newItervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return a.first < b.first; });

	size_t counter = 0;
	for (size_t i = 1; i < newItervals.size(); i++)
	{
		if (newItervals[i].first <= newItervals[i - 1].second)
		{
			if (newItervals[i].second > newItervals[i - 1].second)
			{
				newItervals[i - 1].second = newItervals[i].second;
			}
			newItervals.erase(newItervals.begin() + i--);
		}
	}

	for (pair<int, int> p : newItervals)
	{
		counter += p.second - p.first;
	}

	return counter;
}