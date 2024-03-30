#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void read_file(string file_name)  // функция для вывода содержимого файла
{
	string line;

	ifstream in(file_name);

	cout << "Input:" << endl;

	if (in.is_open())
	{
		while (getline(in, line))
		{
			cout << line << endl;
		}
	}
	in.close();
}


int main()
{
	read_file("Текст.txt"); // вывели содержимое файла для проверки

	ifstream in("Текст.txt");

	string num;

	map<string, string> connections;		// собственно карта {ребёнок : родственник}

	getline(in, num);
	
	int N = atoi(num.c_str());				// считали первую строчку и перевели в целое число
	
	vector <string> people;

	people.reserve(N);   // выделили память под N элементов в векторе с людьми
	
	cout << endl;
	cout << "Output:" << endl;


	string child;
	string parent;

	while (in >> child >> parent)
	{
		connections[child] = parent;

		if (find(people.begin(), people.end(), child) == people.end())
		{
			people.push_back(child);										// В этом блоке создали карту в которой ключ = ребёнок, значение - его родитель
		}
		if (find(people.begin(), people.end(), parent) == people.end()) 
		{
			people.push_back(parent);
		}
	}

	in.close();

	sort(people.begin(), people.end()); // отсортировали массив со всеми людьми так, чтобы они были в лексикографичеком порядке

	for (string person : people) // перебор всех строк из вектора people
	{
		int count = 0;

		string str = person;

		while (connections[str] != "") // проверяем по кажжому ключу на наличие значений, если значение не пустое, то прибавляем счётчик
		{
			count++;

			str = connections[str];
		}

		cout << person << " " << count << endl; // вывод
	}
	return 0;
}
