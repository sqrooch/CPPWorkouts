#include "year2023.h"

/*
Напишите функцию, которая принимает две квадратные матрицы (двумерные массивы N x N) и возвращает их сумму.
Обе матрицы, передаваемые в функцию, будут иметь размер N x N (квадрат) и содержать только целые числа.

Как суммировать две матрицы:
Возьмите каждую ячейку [n][m] из первой матрицы и добавьте к ней такую же ячейку [n][m] из второй матрицы.
Это будет ячейка [n][m] матрицы решения.
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