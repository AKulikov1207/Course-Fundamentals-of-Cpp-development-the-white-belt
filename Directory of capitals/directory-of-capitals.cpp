#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int Q = 0;
	cin >> Q;

	string command;
	map<string, string> guide;

	while (Q) {
		cin >> command;

		if (command == "CHANGE_CAPITAL") {
			string country, new_capital;
			cin >> country >> new_capital;

			map <string, string> ::iterator it1;
			it1 = guide.find(country);
			
			if (it1 == guide.end()) {
				guide[country] = new_capital;
				cout << "Introduce new country " << country << " with capital " << new_capital << endl;
			}
			else if (it1 != guide.end()) {
				if (it1->second == new_capital) {
					cout << "Country " << country << " hasn't changed its capital" << endl;
				} 
				else if (it1->second != new_capital) {
					cout << "Country " << country << " has changed its capital from " << it1->second << " to " << new_capital << endl;
					it1->second = new_capital;
				}
			}

		}

		else if (command == "RENAME") {
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;

			map <string, string> ::iterator it1, it2;
			it1 = guide.find(old_country_name);
			it2 = guide.find(new_country_name);

			if (it1 == guide.end() || it2 != guide.end() || it1 == it2) {
				cout << "Incorrect rename, skip" << endl;
			} 
			else {
				cout << "Country " << old_country_name << " with capital " << it1->second << " has been renamed to " << new_country_name << endl;
				string capital = it1->second;
				guide.erase(old_country_name);
				guide[new_country_name] = capital;
			}
		}

		else if (command == "ABOUT") {
			string country;
			cin >> country;

			map <string, string> ::iterator it1;
			it1 = guide.find(country);

			if (it1 == guide.end()) {
				cout << "Country " << country << " doesn't exist" << endl;
			}
			else
				cout << "Country " << country << " has capital " << it1->second << endl;
		}

		else if (command == "DUMP") {
			if (guide.size() == 0) {
				cout << "There are no countries in the world" << endl;
			}
			else {
				for (const auto& it : guide) {
					cout << it.first << "/" << it.second << " ";
				}
			}
			cout << endl;
		}

		--Q;
	}

	return 0;
}
