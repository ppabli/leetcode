#include <iostream>

using namespace std;

class Solution {
public:
	int minimumPushes(string word) {

		vector<int> freq(26, 0);

		for (char c : word) {
			freq[c - 'a']++;
		}

		sort(freq.begin(), freq.end(), greater<int>());

		int pushes = 1;
		int result = 0;

		for(int letterPos = 0; letterPos < 26 && freq[letterPos] != 0; letterPos++) {

			// Already used all the available keys and return to first one using one more push
			if (letterPos >= 8 && letterPos % 8 == 0) {
				pushes++;
			}

			result += freq[letterPos] * pushes;

		}

		return result;

	}
};