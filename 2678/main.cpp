#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int countSeniors(vector<string>& details) {

		int result = 0;

		for (string detail : details) {

			int age = stoi(detail.substr(10, 2));

			if (age > 60) {
				result++;
			}

		}

		return result;

	}
};