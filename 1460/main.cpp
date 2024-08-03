#include <vector>

using namespace std;

class Solution {
public:
	bool canBeEqual(vector<int>& target, vector<int>& arr) {

		vector<int> counter1(1001);
		vector<int> counter2(1001);

		for(int value : target) {
			counter1[value]++;
		}

		for(int value : arr) {
			counter2[value]++;
		}

		return counter1 == counter2;

	}
};