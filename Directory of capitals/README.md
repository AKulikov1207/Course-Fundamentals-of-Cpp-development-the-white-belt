# Справочник столиц

Реализуйте справочник столиц стран.

На вход программе поступают следующие запросы:
* **CHANGE_CAPITAL country new_capital** — изменение столицы страны country на new_capital, либо добавление такой страны с такой столицей, если раньше её не было.
* **RENAME old_country_name new_country_name** — переименование страны из old_country_name в new_country_name.
* **ABOUT** country — вывод столицы страны country.
* **DUMP** — вывод столиц всех стран.

## Формат ввода
В первой строке содержится количество запросов Q, в следующих Q строках — описания запросов. Все названия стран и столиц состоят лишь из латинских букв, цифр и символов подчёркивания.

## Формат вывода
Выведите результат обработки каждого запроса:

В ответ на запрос **CHANGE_CAPITAL country new_capital** выведите
* **Introduce new country country with capital new_capital**, если страны country раньше не существовало;
* **Country country hasn't changed its capital**, если страна country до текущего момента имела столицу new_capital;
* **Country country has changed its capital from old_capital to new_capital**, если страна country до текущего момента имела столицу old_capital, название которой не совпадает с названием new_capital.

В ответ на запрос **RENAME old_country_name new_country_name** выведите
* **Incorrect rename, skip**, если новое название страны совпадает со старым, страна old_country_name не существует или страна new_country_name уже существует;
* **Country old_country_name with capital capital has been renamed to new_country_name**, если запрос корректен и страна имеет столицу capital.

В ответ на запрос **ABOUT country** выведите
* **Country country doesn't exist**, если страны с названием country не существует;
* **Country country has capital capital**, если страна country существует и имеет столицу capital.

В ответ на запрос **DUMP** выведите
* **There are no countries in the world**, если пока не было добавлено ни одной страны;
* последовательность пар вида **country/capital**, описывающую столицы всех стран, если в мире уже есть хотя бы одна страна. При выводе последовательности пары указанного вида необходимо упорядочить по названию страны и разделять между собой пробелом.

## Пример
### Ввод
6
CHANGE_CAPITAL RussianEmpire Petrograd
RENAME RussianEmpire RussianRepublic
ABOUT RussianRepublic
RENAME RussianRepublic USSR
CHANGE_CAPITAL USSR Moscow
DUMP

### Вывод
Introduce new country RussianEmpire with capital Petrograd
Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
Country RussianRepublic has capital Petrograd
Country RussianRepublic with capital Petrograd has been renamed to USSR
Country USSR has changed its capital from Petrograd to Moscow
USSR/Moscow






