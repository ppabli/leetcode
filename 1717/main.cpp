#include <iostream>

using namespace std;

class Solution
{
public:
	int maximumGain(string s, int x, int y) {
		int res = 0;
		string a = "ab", b = "ba";
		// To make sure x is always the larger score
		if (x < y) {
			swap(x, y);
			swap(a, b);
		}
		// a
		while (true) {
			int score = 0;
			string t;
			for (char c : s) {
				t.push_back(c);
				if (t.size() >= 2 && t.substr(t.size() - 2) == a) {
					score += x;
					t.pop_back();
					t.pop_back();
				}
			}
			if (score == 0) {
				break;
			}
			res += score;
			s = t;
		}
		// b
		while (true) {
			int score = 0;
			string t;
			for (char c : s) {
				t.push_back(c);
				if (t.size() >= 2 && t.substr(t.size() - 2) == b) {
					score += y;
					t.pop_back();
					t.pop_back();
				}
			}
			if (score == 0) {
				break;
			}
			res += score;
			s = t;
		}
		return res;
	}
};