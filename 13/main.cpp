#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {

		map<char, int> roman;

		roman['I'] = 1;
		roman['V'] = 5;
		roman['X'] = 10;
		roman['L'] = 50;
		roman['C'] = 100;
		roman['D'] = 500;
		roman['M'] = 1000;

		int res = 0;

		for(int x = 0; x < s.size() - 1; x++) {

			if(roman[s[x]] < roman[s[x + 1]]) {

				res -= roman[s[x]];

			} else {
	
				res += roman[s[x]];

			}

		}

		res += roman[s[s.size() - 1]];

		return res;

	}
};