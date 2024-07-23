#include <vector>
#include <regex>

using namespace std;

class Solution {
public:
	vector<int> frequencySort(vector<int> &nums) {

		vector<int> map(201, 0);

		for (int num : nums) {
			map[num + 100]++;
		}

		sort(nums.begin(), nums.end(), [&](int a, int b) {

			int posA = a + 100;
			int posB = b + 100;

			if (map[posA] == map[posB]) {
				return a > b;
			}

			return map[posA] < map[posB];

		});

		return nums;

	}
};