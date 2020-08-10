#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string command;
	int Q;
	map<string, vector<string>> bus_map;
	vector<string> stops;

	cin >> Q;

	while (Q > 0) {
		cin >> command;

		if (command == "NEW_BUS") {
			string bus, stop;                     // маршрут
			int stop_count = 0;                   //количество остановок 

			cin >> bus >> stop_count;             //прочитаем маршрут и количество остановок
			stops.push_back(bus);

			while (stop_count) {
				cin >> stop;                      //считаем название новой остановки
				bus_map[bus].push_back(stop);       //и добавим к маршруту
				--stop_count;
			}

		}

		if (command == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;

			int k = 0; //определитель наличия чего-нибудь
			vector<string> v;

			for (const auto& f : bus_map) {
				for (const auto& s : f.second) {
					if (s == stop) {                   //ищем совпадение с остановкой и, если нашли, 
						v.push_back(f.first);	       //запишем "найденный" маршрут в вектор
						k++;                           //плюсанули наличие совпадения
					}
				}
			}

			if (k > 0) {                              //если есть совпадения
				for (const auto& w : stops) {         //пролистаем общий вектор с маршрутами и для каждого маршрута
					for (auto z : v) {                //будем просматривать вектор "найденных" маршрутов 
						if (z == w) {                //и при совпадении
							cout << w << " ";          //выводим маршрут
						}                          
					}
				}
			}
			else if (k == 0) 
				cout << "No stop";                    //если не нашли совпадение, то так и пишем
			cout << endl;
		}

		if (command == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;

			int l = 0;                                                   //переменная для определения наличия нужного маршрута
			for (const auto& i : bus_map) {                            //просматриваем контейнер
				if (i.first == bus) {                                     //если значение ключа совпало с названием маршрута
					for (const auto& m : i.second) {                      // (п.1) то для каждого значения этого ключа
						cout << "Stop " << m << ":";                      //пишем остановку
						int l2 = 0;                                      //переменная для определения наличия других маршрутов остановки, кроме первоначального
						vector<string> v;
						for (const auto& d : bus_map) {                 //снова пролистываем контейнер
							for (const auto& s : d.second) {              //просматриваем все значения остановок
								                                          //и если значение остановки совпало со значением ключа m в п.1, но не равно "введенному" маршруту s
								if (s == m && d.first != bus) {
									v.push_back(d.first);                 //запишем маршруты в вектор
									l2++;
								}
							}
						}
						if (l2 == 0) cout << " no interchange";
						else if (l2 > 0) {
							for (const auto& w : stops) {               //пролистаем общий вектор с маршрутами и для каждого маршрута
								for (const auto& z : v) {                //будем просматривать вектор "найденных" маршрутов 
									if (z == w) {                        //и при совпадении
										cout << " " << z;                  //выводим маршрут
									}            
								}
							}
						}
						cout << endl;
					}
					l++;                                            //если маршрут нашелся, то плюсуем
				}
			}
			if (l == 0) 
				cout << "No bus" << endl;                             // если не нашлось маршрутов - так и пишем
		}

		if (command == "ALL_BUSES") {
			if (bus_map.size() > 0) {                               //если что-то есть
				for (const auto& p : bus_map) {                   //пролистаем контейнер и напишем, для каждой пары "ключ-значение"
					cout << "Bus " << p.first << ": ";                 //название маршрута
					for (const auto& s : p.second)                     //а также перечислим 
						cout << s << " ";                                 // название остановок
					cout << endl;
				}
			}
			else
				cout << "No buses" << endl;                              //если размер контейнера = 0, то напишем что ничего нет
		}

		--Q;
	}

	return 0;
}


/////////////////////////////////////////////////////////////////////
// ответ на запрос BUSES_FOR_STOP
void PrintBusesForStop(map<string, vector<string>>& stops_to_buses,
	const string& stop) {
	if (stops_to_buses.count(stop) == 0) {
		cout << "No stop" << endl;
	}
	else {
		for (const string& bus : stops_to_buses[stop]) {
			cout << bus << " ";
		}
		cout << endl;
	}
}

// ответ на запрос STOPS_FOR_BUS
void PrintStopsForBus(map<string, vector<string>>& buses_to_stops,
	map<string, vector<string>>& stops_to_buses,
	const string& bus) {
	if (buses_to_stops.count(bus) == 0) {
		cout << "No bus" << endl;
	}
	else {
		for (const string& stop : buses_to_stops[bus]) {
			cout << "Stop " << stop << ": ";

			// если через остановку проходит ровно один автобус,
			// то это наш автобус bus, следовательно, пересадки тут нет
			if (stops_to_buses[stop].size() == 1) {
				cout << "no interchange";
			}
			else {
				for (const string& other_bus : stops_to_buses[stop]) {
					if (bus != other_bus) {
						cout << other_bus << " ";
					}
				}
			}
			cout << endl;
		}
	}
}

// ответ на запрос ALL_BUSES
void PrintAllBuses(const map<string, vector<string>>& buses_to_stops) {
	if (buses_to_stops.empty()) {
		cout << "No buses" << endl;
	}
	else {
		for (const auto& bus_item : buses_to_stops) {
			cout << "Bus " << bus_item.first << ": ";
			for (const string& stop : bus_item.second) {
				cout << stop << " ";
			}
			cout << endl;
		}
	}
}

int main() {
	int q;
	cin >> q;

	map<string, vector<string>> buses_to_stops, stops_to_buses;

	for (int i = 0; i < q; ++i) {
		string operation_code;
		cin >> operation_code;

		if (operation_code == "NEW_BUS") {

			string bus;
			cin >> bus;
			int stop_count;
			cin >> stop_count;

			// с помощью ссылки дадим короткое название вектору
			// со списком остановок данного автобуса;
			// ключ bus изначально отсутствовал в словаре, поэтому он автоматически
			// добавится туда с пустым вектором в качестве значения
			vector<string>& stops = buses_to_stops[bus];
			stops.resize(stop_count);

			for (string& stop : stops) {
				cin >> stop;
				// не забудем обновить словарь stops_to_buses
				stops_to_buses[stop].push_back(bus);
			}

		}
		else if (operation_code == "BUSES_FOR_STOP") {

			string stop;
			cin >> stop;
			PrintBusesForStop(stops_to_buses, stop);

		}
		else if (operation_code == "STOPS_FOR_BUS") {

			string bus;
			cin >> bus;
			PrintStopsForBus(buses_to_stops, stops_to_buses, bus);

		}
		else if (operation_code == "ALL_BUSES") {

			PrintAllBuses(buses_to_stops);

		}
	}

	return 0;
}