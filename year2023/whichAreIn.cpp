#include "year2023.h"

/*
���� ��� ������� ����� array1 � array2, ������� ���������� ��������������� ������ resultArr � ������������������ ������� ����� array1,
������� �������� ����������� ����� array2.

������ 1:
a1 = ["arp", "live", "strong"]
a2 = ["lively", "alive", "harp", "sharp", "armstrong"]
����� ["arp", "live", "strong"]

������ 2:
a1 = ["tarp", "mice", "bull"]
a2 = ["lively", "alive", "harp", "sharp", "armstrong"]
����� []
*/

vector<string> WhichAreIn::inArray(vector<string>& array1, vector<string>& array2)
{
	vector<string> result;
	for (int i = 0; i < array1.size(); i++)
	{
		for (int j = 0; j < array2.size(); j++)
		{
			if (array2[j].find(array1[i]) != string::npos)
			{
				result.push_back(array1[i]);
				break;
			}
		}
	}
	sort(begin(result), end(result));
	return result;
}

//Best practice:
/*
vector<string> WhichAreIn::inArray(vector<string>& array1, vector<string>& array2)
{
	vector<string> results;

	copy_if(array1.begin(), array1.end(), back_inserter(results), [&](const string& item1)
		{
			return any_of(array2.begin(), array2.end(), [&](const string& item2)
				{
					return item2.find(item1) != string::npos;
				}
			);
		}
	);

	sort(results.begin(), results.end());

	return results;
}
*/