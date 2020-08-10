#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
    /* Для тестирования код, реализующий различное поведение этой функии:
       * нормальный возврат строкового значения
       * выброс исключения system_error
       * выброс другого исключения с сообщением.
    */
	//string s = "01:01:01";
	//return s;
	//throw runtime_error("runtime_error");
	//throw system_error(error_code()); 
}

class TimeServer {
public:
    string GetCurrentTime() {
        /*
            * если AskTimeServer() вернула значение, записать его в last_fetched_time и вернуть
            * если AskTimeServer() бросила исключение system_error, вернуть текущее значение
            поля last_fetched_time
            * если AskTimeServer() бросила другое исключение, пробросить его дальше.
        */
		try {
			last_fetched_time = AskTimeServer();
			return last_fetched_time;
		}
		catch (const system_error&) {
			return last_fetched_time;
		}
		catch (const exception&) {
			throw;
		}
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убеждаемся, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
