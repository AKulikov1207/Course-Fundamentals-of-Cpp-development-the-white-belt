#include <vector>
#include <string>

using namespace std;

bool IsPalindrom(string s) {
	for (size_t i = 0; i < s.size() / 2; ++i) {
		if (s[i] != s[s.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> s;
	
	for (auto i : words) {
		if (IsPalindrom(i) && i.size() >= minLength)
			s.push_back(i);
	}
	
	return s;
}