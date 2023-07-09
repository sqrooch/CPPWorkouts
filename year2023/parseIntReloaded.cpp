#include "year2023.h"

/*
Преобразовать строку в целое число. Строки представляют числа словами.

Например:
"one" => 1
"twenty" => 20
"two hundred forty-six" => 246
"seven hundred eighty-three thousand nine hundred and nineteen" => 783919

Примечание:
Минимальное число - "ноль" (включительно), максимальное число = "миллион" (включительно).
Слово "and" в т.ч. в выражении "one hundred and twenty-four" опционально, может встречаться в выражении, а может и нет.
Делать проверку входящих сообщений на то, что это числа не надо. По умолчанию в сообщениях зашифрованы только числа.
*/

long parse_int(const string& number)
{
	map<string, char> digits // Словарь начала подстрок и соответствующих им цифр.
	{
		{"te", '0'},
		{"on", '1'},
		{"el", '1'},
		{"tw", '2'},
		{"th", '3'},
		{"fo", '4'},
		{"fi", '5'},
		{"si", '6'},
		{"se", '7'},
		{"ei", '8'},
		{"ni", '9'},
	};

	// Создаём динамический массив, где каждым элементом массива становится слово-число.
	vector<string> wordsArray;
	stringstream ss(number);
	string subWord;

	while (getline(ss, subWord, '-'))
	{
		stringstream subss(subWord);
		string subsubWord;

		while (getline(subss, subsubWord, ' '))
		{
			if (subsubWord != "and")
			{
				wordsArray.push_back(subsubWord);
			}
		}
	}

	// В английском языке числительные имеют определённые паттерны написания.
	// Анализируем каждое слово в массиве и вносим цифру в соответствующий разряд в результирующей строке.
	string resultStr = "000";
	for (auto word : wordsArray)
	{
		if (word == "million") // Если присутствует слово "million", сразу выходим согласно условию.
		{
			return 1000000;
		}

		if (word == "thousand") // Если присутствует слово "thousand", добавляем нужное количество разрядов.
		{
			resultStr += "000";
			continue;
		}

		if (word == "hundred") // Если присутствует слово "hundred", переносим предыдущую цифру на два разряда влево.
		{
			resultStr[resultStr.length() - 3] = resultStr[resultStr.length() - 1];
			resultStr[resultStr.length() - 1] = '0';
			continue;
		}

		// Пробежимся по нашему словарю и проверим слова на соответствия цифрам.
		for (auto pair : digits)
		{
			if (word.substr(0, pair.first.length()) == pair.first)
			{
				resultStr[resultStr.length() - 1] = pair.second;

				// Проанализируем окончания слов и перенесём цифры в соответствующий разряд.
				if (word.substr(word.length() - 3, 3) == "een"
					|| word.substr(word.length() - 3, 3) == "ten"
					|| (word.substr(word.length() - 3, 3) == "ven" && word.substr(0, 1) != "s")
					|| word.substr(word.length() - 3, 3) == "lve")
				{
					resultStr[resultStr.length() - 2] = '1';
				}
				else if (word.substr(word.length() - 2, 2) == "ty")
				{
					resultStr[resultStr.length() - 2] = pair.second;
					resultStr[resultStr.length() - 1] = '0';
				}
				break;
			}
		}
	}
	return stol(resultStr);
}

//Best practice:
/*
long parse_int(const string& number)
{
	map<string, int> mapping =
	{
		{"zero", 0},
		{"and", 0},
		{"one", 1},
		{"two", 2},
		{"three", 3},
		{"four", 4},
		{"five", 5},
		{"six", 6},
		{"seven", 7},
		{"eight", 8},
		{"nine", 9},
		{"ten", 10},
		{"eleven", 11},
		{"twelve", 12},
		{"thirteen", 13},
		{"fourteen", 14},
		{"fifteen", 15},
		{"sixteen", 16},
		{"seventeen", 17},
		{"eighteen", 18},
		{"nineteen", 19},
		{"twenty", 20},
		{"thirty", 30},
		{"forty", 40},
		{"fifty", 50},
		{"sixty", 60},
		{"seventy", 70},
		{"eighty", 80},
		{"ninety", 90},
		{"hundred", 100},
		{"thousand", 1000},
		{"million", 1000000}
	};

	long result = 0;

	auto add = [&](auto& w)
	{
		if (w.empty())
		{
			return;
		}
		auto i = mapping[w];
		if (i > 0 && i < 100)
		{
			result += i;
		}
		else if (i == 1000 || i == 1000000)
		{
			result *= i;
		}
		else if (i == 100)
		{
			result += 99 * (result % 100);
		}

		w = "";
	};

	string word;
	for (auto c : number)
	{
		if (word.size() > 0 && (c == ' ' || c == '-'))
		{
			add(word);
		}
		else
		{
			word.push_back(c);
		}
	}

	add(word);
	return result;
}
*/