//#include <iostream>
//#include <fstream>
//#include <map>
//#include <set>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//class Rational {
//public:
//	Rational() {
//		p = 0;
//		q = 1;
//	}
//
//	Rational(int numerator, int denominator) {
//		if (denominator < 0) {
//			if (numerator < 0) {
//				denominator = abs(denominator);
//				numerator = abs(numerator);
//			}
//			else {
//				denominator = abs(denominator);
//				numerator = numerator - 2 * numerator;
//			}
//		}
//
//		if (numerator == 0)
//			denominator = 1;
//
//		int Gcd = nod(abs(numerator), abs(denominator));
//		p = numerator / Gcd;
//		q = denominator / Gcd;
//	}
//
//	int Numerator() const {
//		return p;
//	}
//
//	int Denominator() const {
//		return q;
//	}
//
//private:
//	int p;
//	int q;
//
//	int nod(int x, int y) {
//		while (x > 0 && y > 0) {
//			if (x > y)
//				x %= y;
//			else
//				y %= x;
//		}
//
//		return x == 0 ? y : x;
//	}
//};
//
//bool operator==(const Rational& lhs, const Rational& rhs) {
//	return ((lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator()));
//}
//
//bool operator<(const Rational& lhs, const Rational& rhs) {
//	return (lhs.Numerator() / (double)lhs.Denominator()) < (rhs.Numerator() / (double)rhs.Denominator());
//}
//
//bool operator>(const Rational& lhs, const Rational& rhs) {
//	return rhs < lhs;
//}
//
//Rational operator+(const Rational& lhs, const Rational& rhs) {
//	int p = (lhs.Numerator() * rhs.Denominator()) + (rhs.Numerator() * lhs.Denominator());
//	int q = lhs.Denominator() * rhs.Denominator();
//	return Rational(p, q);
//}
//
//Rational operator-(const Rational& lhs, const Rational& rhs) {
//	int p = (lhs.Numerator() * rhs.Denominator()) - (rhs.Numerator() * lhs.Denominator());
//	int q = lhs.Denominator() * rhs.Denominator();
//	return Rational(p, q);
//}
//
//Rational operator*(const Rational& lhs, const Rational& rhs) {
//	int p = (lhs.Numerator() * rhs.Numerator());
//	int q = (lhs.Denominator() * rhs.Denominator());
//	return Rational(p, q);
//}
//
//Rational operator/(const Rational& lhs, const Rational& rhs) {
//	int p = (lhs.Numerator() * rhs.Denominator());
//	int q = (lhs.Denominator() * rhs.Numerator());
//	return Rational(p, q);
//}
//
//ostream& operator<<(ostream& os, const Rational& rat) {
//	os << rat.Numerator() << "/" << rat.Denominator();
//	return os;
//}
//
//istream& operator>>(istream& is, Rational& rat) {
//	int p, q;
//	if (is >> p && is.ignore(1) && is >> q) {
//		rat = { p, q };
//	}
//	return is;
//}
//
//int main() {
//    {
//        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
//        if (rs.size() != 3) {
//            cout << "Wrong amount of items in the set" << endl;
//            return 1;
//        }
//
//        vector<Rational> v;
//        for (auto x : rs) {
//            v.push_back(x);
//        }
//        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
//            cout << "Rationals comparison works incorrectly" << endl;
//            return 2;
//        }
//    }
//
//    {
//        map<Rational, int> count;
//        ++count[{1, 2}];
//        ++count[{1, 2}];
//
//        ++count[{2, 3}];
//
//        if (count.size() != 2) {
//            cout << "Wrong amount of items in the map" << endl;
//            return 3;
//        }
//    }
//
//    cout << "OK" << endl;
//    return 0;
//}
