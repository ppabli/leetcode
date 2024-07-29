#include <vector>

using namespace std;

class Solution {
public:
	int numTeams(vector<int>& rating) {

		const int n = rating.size();

		int result = 0;

		for (int x = 1; x < n - 1; x++) {

			int leftLess = 0;
			int leftGreater = 0;
			int rightLess = 0;
			int rightGreater = 0;

			for (int i = 0; i < x; i++) {
				if (rating[i] < rating[x]) {
					leftLess++;
				}
				else if (rating[i] > rating[x]) {
					leftGreater++;
				}
			}

			for (int i = x + 1; i < n; i++) {
				if (rating[i] < rating[x]) {
					rightLess++;
				}
				else if (rating[i] > rating[x]) {
					rightGreater++;
				}
			}

			result += leftLess * rightGreater + leftGreater * rightLess;

		}

		return result;

	}
};