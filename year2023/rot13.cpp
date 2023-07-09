#include "year2023.h"

/*
��� � ��� �������� ����������� �� ����������?
Va gur ryringbef, gur rkgebireg ybbxf ng gur BGURE thl'f fubrf.

� ����� ��� ����� � USENET, �� �������� ���������. �����, �����������?
�������� ���������, ROT13 ����� ������������ ��� ����������� ����� � USENET.

��� ���� ������ �� ������ �������� ������ �������. ������ ������ �������, ����� ����������, ����� � �.�.

��������:
"EBG13 rknzcyr." -> "ROT13 example."
"This is my first ROT13 excercise!" -> "Guvf vf zl svefg EBG13 rkprepvfr!"
*/

string rot13(const string& str)
{
	string resultStr = "";
	for (char ch : str)
	{
		isalpha(ch) ? (int(ch) > 64 && int(ch) < 78) || (int(ch) > 96 && int(ch) < 110)
			? resultStr += char(int(ch) + 13) : resultStr += char(int(ch) - 13)
			: resultStr += ch;
	}

	return resultStr;
}