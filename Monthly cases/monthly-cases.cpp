#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int day = 0;
	string command;
	int Q;
	const vector<int> days_months = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
        // внешний вектор должен иметь длину, равную количеству дней в первом месяце;
        // все внутренние векторы по умолчанию пусты, потому что дел изначально нет
	vector<vector<string>> todo(days_months[day]);

	cin >> Q;

	while (Q > 0) {
		cin >> command;

		if (command == "ADD") {
			int d;
			string deal;

			cin >> d >> deal;
			todo[d - 1].push_back(deal);
		}

		if (command == "DUMP") {
			int d;
			cin >> d;
			
			// выводим список дел в конкретный день в нужном формате
			cout << todo[d - 1].size() << " ";
			for (auto w : todo[d - 1])
				cout << w << " ";
			cout << endl;
		}

		if (command == "NEXT") {
			vector<vector<string>> buf = todo;
			if (++day > 11)
				day = 0;

			todo.resize(days_months[day]);

			if (todo.size() < buf.size())
			{
				for (int i = todo.size(); i < buf.size(); i++)
				{
					todo[todo.size() - 1].insert(end(todo[todo.size() - 1]), begin(buf[i]), end(buf[i]));
				}
			}
		}
		
		--Q;
	}

	return 0;
}
