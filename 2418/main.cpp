#include <vector>
#include <string>
#include <regex>

using namespace std;

class Solution {
public:
	vector<string> sortPeople(vector<string> &names, vector<int> &heights) {

		vector<string> result;
		int n = names.size();
		vector<int> indices(n);

		for (int i = 0; i < n; i++) {
			indices[i] = i;
		}

		// All heights are distinct
		sort(indices.begin(), indices.end(), [&](int a, int b) {
			return heights[a] > heights[b];
		});

		for (int i = 0; i < n; i++) {
			result.push_back(names[indices[i]]);
		}

		return result;

	}
};