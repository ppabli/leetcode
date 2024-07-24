#include <iostream>
#include <vector>
#include <regex>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {

		string ans="";

		sort(strs.begin(), strs.end());

		int n=strs.size();

		string first = strs[0];
		string last = strs[n - 1];
		int maxLen = min(first.size(), last.size());

		for(int i = 0; i < maxLen; i++) {

			if(first[i] != last[i]) {

				return ans;

			}

			ans += first[i];

		}

		return ans;

	}
};