#include "header2024.h"

/*
Your task is to create all permutations of a non-empty input string and remove duplicates, if present.
Create as many "shufflings" as you can!

Examples:
With input 'a':
Your function should return: ['a']
With input 'ab':
Your function should return ['ab', 'ba']
With input 'abc':
Your function should return ['abc','acb','bac','bca','cab','cba']
With input 'aabb':
Your function should return ['aabb', 'abab', 'abba', 'baab', 'baba', 'bbaa']

Note: The order of the permutations doesn't matter.
*/

vector<string> permutations(string input_str)
{
	sort(input_str.begin(), input_str.end());
	vector<string> result;

	do
	{
		result.push_back(input_str);
	} while (next_permutation(input_str.begin(), input_str.end()));

	return result;
}