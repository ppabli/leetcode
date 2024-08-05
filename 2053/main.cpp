#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	string kthDistinct(vector<string>& arr, int k) {

		unordered_map<string, int> counter;

		for (string& v : arr) {

			counter[v]++;

		}

		for (string& v : arr) {

			if (counter[v] == 1) {

				k--;

				if (k == 0) {

					return v;

				}

			}

		}

		return "";

	}
};