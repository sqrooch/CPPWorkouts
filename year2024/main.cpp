#include "header2024.h"

int main()
{
	setlocale(LC_ALL, "RU");

	string inputString = "bcad";
	vector<string> resultVectorString = permutations(inputString);

	cout << "[";
	for (auto iter = resultVectorString.begin(); iter != resultVectorString.end(); ++iter)
	{
		cout << *iter;
		if (next(iter) != resultVectorString.end())
		{
			cout << ", ";
		}
	}
	cout << "]";

	string testString = "test";
	

	return 0;
}