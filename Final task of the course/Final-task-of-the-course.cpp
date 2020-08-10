#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <stdexcept>

using namespace std;

class Date {
	public:
		Date() {}
		Date(int y, int m, int d) : year{ y }, month{ m }, day{ d } {
			if (!(m >= 1 && m <= 12))
				throw logic_error("Month value is invalid: " + to_string(m));

			if (!(d >= 1 && d <= 31))
				throw logic_error("Day value is invalid: " + to_string(d));
		}

		int GetYear() const { return year; };
		int GetMonth() const { return month; };
		int GetDay() const { return day; };
	private:
		int year;
		int month;
		int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() != rhs.GetYear()) 
		return lhs.GetYear() < rhs.GetYear();
	else if (lhs.GetMonth() != rhs.GetMonth())
		return lhs.GetMonth() < rhs.GetMonth();
	else if (lhs.GetDay() != rhs.GetDay())
		return lhs.GetDay() < rhs.GetDay();
};

Date Parse(string& date) {
	istringstream date_is(date);
	bool check = true;

	int year, month, day;
	check = check && (date_is >> year);
	check = check && (date_is.peek() == '-');
	date_is.ignore(1);

	check = check && (date_is >> month);
	check = check && (date_is.peek() == '-');
	date_is.ignore(1);

	check = check && (date_is >> day);
	check = check && date_is.eof();

	if (!check) {
		throw logic_error("Wrong date format: " + date);
	}

	return Date(year, month, day);
}

ostream& operator<<(ostream& os, const Date& d) {
	os << setfill('0') << setw(4) << to_string(d.GetYear()) << "-";
	os << setfill('0') << setw(2) << to_string(d.GetMonth()) << "-";
	os << setfill('0') << setw(2) << to_string(d.GetDay());
	return os;
}

class Database {
	public:
		Database() {}
		Database(map<Date, set<string>> db) : data_base{ db } {}

		void AddEvent(const Date& date, const string& event) {
			if (!event.empty())
				data_base[date].insert(event);
		}

		bool DeleteEvent(const Date& date, const string& event) {
			if (data_base.count(date) > 0 && data_base.at(date).count(event) > 0)
			{
				data_base[date].erase(event);
				return true;
			}
			return false;
		}

		size_t DeleteDate(const Date& date) {
			size_t count = 0;
			if (data_base.count(date) > 0)
			{
				count = data_base.at(date).size();
				data_base.erase(date);
			}
			return count;
		}

		set<string> Find(const Date& date) const {
			set<string> res;
			if (data_base.count(date) > 0) {
				res = data_base.at(date);
			}
			return res;
		}
  
		void Print() const {
			for (const auto& p : data_base) {
				for (auto& d : p.second) {
					cout << p.first << ' ' << d << endl;
				}
			}
		}
	private:
		map<Date, set<string>> data_base;
};

int main() {
	try {
		Database db;
		string command;

		while (getline(cin, command)) {
			if (command == "") continue;

			stringstream in(command);
			string op, date, event;
			Date d;
			in >> op;

			if (op == "Add") {
				in >> date >> event;

				if (event != "" || event != " ") {
					d = Parse(date);
					db.AddEvent(d, event);
				}
			}
			else if (op == "Del") {
				in >> date;
				d = Parse(date);

				if (!cin.eof()) {
					in >> event;
				}

				if (event.empty()) {
					const size_t count = db.DeleteDate(d);
					cout << "Deleted " << count << " events" << endl;
				}
				else {
					if (db.DeleteEvent(d, event)) {
						cout << "Deleted successfully" << endl;
					}
					else {
						cout << "Event not found" << endl;
					}
				}
			}
			else if (op == "Find") {
				in >> date;
				d = Parse(date);
				set<string> tmp = db.Find(d);
				for (const auto& i : tmp)
					cout << i << endl;
			}
			else if (op == "Print") {
				db.Print();
			}
			else
				throw logic_error("Unknown command: " + op);
		}
	}
	catch (const exception & ex) {
		cout << ex.what() << endl;
	}

  return 0;
}