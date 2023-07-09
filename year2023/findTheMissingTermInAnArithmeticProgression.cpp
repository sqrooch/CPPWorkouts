#include "year2023.h"

/*
�������������� ���������� ������������ ��� ����������,
� ������� ���������� ���������� ������� ����� ����������������� ������� ������� ���� �����.
��� ��������������� ���������������� �������� �������������� ����������.
������ ���� ���� ���������: � ������ �����, ������� ��� ����, ����������� ����� ���� ���� �� ��������� ����.
� ��������� ������ ����� ����� ��, ��� � � ������������ A�. ������� ����������� �������.

��� ����� �������� �������, ������� �������� ������, ������ ������ ������ ����� �� ����� 3 �����.
������������� ������� ������� �� ����� �� ������, �� ���������.

������: findMissing([1, 3, 5, 9, 11]) == 7
*/

long findMissing(vector<long> list)
{
	double d = double(list[list.size() - 1]) - double(list[0]);
	d /= list.size();
	for (int i = 1; i < list.size(); i++)
	{
		if ((list[i - 1] + d) != list[i])
		{
			return long(list[i - 1] + d);
		}
	}
}

//Best practice:
/*
long findMissing(vector<long> list)
{
  long long expectedSum = (list.front() + list.back()) * (list.size() + 1);
  long long actualSum = accumulate(list.begin(), list.end(), 0ll);

  return (expectedSum - 2 * actualSum) / 2;
}
*/