#include "year2023.h"

/*
�������� �������, ������� ��������� ��� ���������� ������� (��������� ������� N x N) � ���������� �� �����.
��� �������, ������������ � �������, ����� ����� ������ N x N (�������) � ��������� ������ ����� �����.

��� ����������� ��� �������:
�������� ������ ������ [n][m] �� ������ ������� � �������� � ��� ����� �� ������ [n][m] �� ������ �������.
��� ����� ������ [n][m] ������� �������.
*/

vector<vector<int>> matrixAddition(vector<vector<int>> a, vector<vector<int>> b)
{
	vector<vector<int>> resultMatrix = a;
	for (int i = 0; i < resultMatrix.size(); i++)
	{
		for (int j = 0; j < resultMatrix[i].size(); j++)
		{
			resultMatrix[i][j] = a[i][j] + b[i][j];
		}
	}
	return resultMatrix;
}

void viewMatrix(vector<vector<int>> matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << "\t";
		}

		cout << endl;
	}
}