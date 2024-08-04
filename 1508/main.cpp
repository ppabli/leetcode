#include <vector>

using namespace std;

class Solution {
public:
	int rangeSum(vector<int>& nums, int n, int left, int right) {

		vector<int> sums;

		for(int x = 0; x < n; x++) {

			int sum = 0;

			for(int y = x; y < n; y++) {

				sum += nums[y];
				sums.push_back(sum);

			}

		}

		sort(sums.begin(), sums.end());

		long result = 0;

		for(int x = left - 1; x < right; x++) {

			result += sums[x];

		}

		return result % 1000000007;

	}
};