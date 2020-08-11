#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string command;
	int Q;
	map<string, vector<string>> bus_map;                        // автобус:остановки
	vector<string> stops;                                       // список остановок данного автобуса

	cin >> Q;                                                   // количество запросов

	while (Q > 0) {
		cin >> command;

		if (command == "NEW_BUS") {
			string bus, stop;                           // маршрут & остановка
			int stop_count = 0;                         // количество остановок 

			cin >> bus >> stop_count;                   // получаем маршрут и количество остановок
			stops.push_back(bus);

			while (stop_count) {
				cin >> stop;                        // получаем название новой остановки
				bus_map[bus].push_back(stop);       // и добавим к маршруту
				--stop_count;
			}

		}

		if (command == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;

			int k = 0;                                  // определитель наличия
			vector<string> v;

			for (const auto& f : bus_map) {
				for (const auto& s : f.second) {
					if (s == stop) {                   // ищем совпадение с остановкой и, если нашли, 
						v.push_back(f.first);	   // запишем найденный маршрут в вектор
						k++;                       // плюсуем наличие совпадения
					}
				}
			}

			if (k > 0) {                                       // если есть совпадения
				for (const auto& w : stops) {              // пролистаем общий вектор с маршрутами и для каждого маршрута
					for (auto z : v) {                 // будем просматривать вектор найденных маршрутов 
						if (z == w) {              // и при совпадении
							cout << w << " ";  // выводим маршрут
						}                          
					}
				}
			}
			else if (k == 0) 
				cout << "No stop";                         //если не нашли совпадение, так и пишем
			cout << endl;
		}

		if (command == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;

			int l = 0;                                                              // переменная для определения наличия нужного маршрута
			for (const auto& i : bus_map) {                                         // просматриваем контейнер
				if (i.first == bus) {                                           // если значение ключа совпало с названием маршрута
					for (const auto& m : i.second) {                        // для каждого значения этого ключа
						cout << "Stop " << m << ":";                    // пишем остановку
						int l2 = 0;                                     // переменная для определения наличия других маршрутов остановки, кроме первоначального
						vector<string> v;
						for (const auto& d : bus_map) {                 // снова пролистываем контейнер
							for (const auto& s : d.second) {        // просматриваем все значения остановок
								                                // и если значение остановки совпало со значением ключа m, но не равно введенному маршруту s
								if (s == m && d.first != bus) {
									v.push_back(d.first);   // запишем маршруты в вектор
									l2++;
								}
							}
						}
						if (l2 == 0) cout << " no interchange";
						else if (l2 > 0) {
							for (const auto& w : stops) {              // пролистаем общий вектор с маршрутами и для каждого маршрута
								for (const auto& z : v) {          // просматриваем вектор найденных маршрутов 
									if (z == w) {              // и при совпадении
										cout << " " << z;  // выводим маршрут
									}            
								}
							}
						}
						cout << endl;
					}
					l++;                                     // если маршрут нашелся, увеличиваем счётчик
				}
			}
			if (l == 0) 
				cout << "No bus" << endl;                        // если не нашлось маршрутов - так и пишем
		}

		if (command == "ALL_BUSES") {
			if (bus_map.size() > 0) {                                // если что-то есть
				for (const auto& p : bus_map) {                  // пролистаем контейнер и напишем, для каждой пары
					cout << "Bus " << p.first << ": ";       // название маршрута
					for (const auto& s : p.second)           // а также перечислим 
						cout << s << " ";                // название остановок
					cout << endl;
				}
			}
			else
				cout << "No buses" << endl;                      // если размер контейнера = 0, напишем что ничего нет
		}

		--Q;
	}

	return 0;
}