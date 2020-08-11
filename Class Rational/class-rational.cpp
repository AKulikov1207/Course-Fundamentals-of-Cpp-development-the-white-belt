#include <iostream>
#include <exception>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

// представление рациональных чисел
class Rational {
public:
	Rational() {
		p = 0;
		q = 1;
	}

	Rational(int numerator, int denominator) {
		if (denominator < 0) {
			if (numerator < 0) {
				denominator = abs(denominator);          // если дробь вида -p/-q, делаем её вида p/q
				numerator = abs(numerator);
			}
			else {
				denominator = abs(denominator);          // если дробь вида p/-q, делаем её вида -p/q
				numerator = numerator - 2 * numerator;
			}
		}

		if (numerator == 0)
			denominator = 1;                                 // если числитель = 0, то знаменатель = 1 (по условию задачи)

		int Gcd = nod(abs(numerator), abs(denominator));         // НОД(числитель, знаменатель)

		p = numerator / Gcd;
		q = denominator / Gcd;
		if (q == 0) throw  invalid_argument("denominator = 0");  // выброс исключения "знаменатель = 0"
	}

	int Numerator() const {
		return p;
	}

	int Denominator() const {
		return q;
	}

private:
	int p;    // числитель
	int q;    // знаменатель (p/q)
	
	// наибольший общий делитель
	int nod(int x, int y) {
		while (x > 0 && y > 0) {
			if (x > y)
				x %= y;
			else
				y %= x;
		}

		return x == 0 ? y : x;
	}
};

// перегрузка логических операторов
bool operator==(const Rational& lhs, const Rational& rhs) {
	return ((lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator()));
}

bool operator<(const Rational& lhs, const Rational& rhs) {
	return (lhs.Numerator() / (double)lhs.Denominator()) < (rhs.Numerator() / (double)rhs.Denominator());
}

bool operator>(const Rational& lhs, const Rational& rhs) {
	return rhs < lhs;
}

// перегрузка арифметических операторов
Rational operator+(const Rational& lhs, const Rational& rhs) {
	int p = (lhs.Numerator() * rhs.Denominator()) + (rhs.Numerator() * lhs.Denominator());
	int q = lhs.Denominator() * rhs.Denominator();
	return Rational(p, q);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
	int p = (lhs.Numerator() * rhs.Denominator()) - (rhs.Numerator() * lhs.Denominator());
	int q = lhs.Denominator() * rhs.Denominator();
	return Rational(p, q);
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
	int p = (lhs.Numerator() * rhs.Numerator());
	int q = (lhs.Denominator() * rhs.Denominator());
	return Rational(p, q);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
	int p = (lhs.Numerator() * rhs.Denominator());
	int q = (lhs.Denominator() * rhs.Numerator());
	if (q == 0) throw  domain_error("division by zero");
	return Rational(p, q);
}

// вывод рационального числа в нужном формате
ostream& operator<<(ostream& os, const Rational& rat) {
	os << rat.Numerator() << "/" << rat.Denominator();
	return os;
}

istream& operator>>(istream& is, Rational& rat) {
	int p, q;
	if (is >> p && is.ignore(1) && is >> q) {
		rat = { p, q };
	}
	return is;
}