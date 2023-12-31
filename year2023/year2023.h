﻿#pragma once
#include <iostream>
#include <sstream>
#include <ctime>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <map>
#include <utility>

using namespace std;

class WhichAreIn
{
public:
	static vector<string> inArray(vector<string>& array1, vector<string>& array2);
};

long findMissing(vector<long> list);
int score(const vector<int>& dice);
vector<vector<int>> matrixAddition(vector<vector<int>> a, vector<vector<int>> b);
void viewMatrix(vector<vector<int>> matrix);
long parse_int(const string& number);
string rot13(const string& str);
vector<vector<int>> matrix_multiplication(vector<vector<int>>& a, vector<vector<int>>& b, size_t n);
int sum_intervals(const vector<pair<int, int>>& intervals);