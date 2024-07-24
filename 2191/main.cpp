#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

		vector<vector<int>> values;
		vector<int> result;

		for (int i = 0; i < nums.size(); i++) {

			int number = nums[i];

			if (number == 0) {
				values.push_back({mapping[0], 0});
				continue;
			}

			int newValue = 0;

			for(int p10 = 1; number > 0; p10 *= 10) {

				int digit = number % 10;

				newValue += mapping[digit] * p10;
				number /= 10;

			}

			values.push_back({newValue, nums[i]});

		}

		sort(values.begin(), values.end(), [](vector<int>& a, vector<int>& b) {
			return a[0] < b[0];
		});

		for (int i = 0; i < values.size(); i++) {
			result.push_back(values[i][1]);
		}

		return result;

	}
};