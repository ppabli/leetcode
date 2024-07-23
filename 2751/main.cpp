#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include <stack>

using namespace std;

class Solution {
public:
	vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

		vector<int> result;
		int n = positions.size();
		vector<int> indices(n);
		stack<int> stack;

		for (int i = 0; i < n; i++) {
			indices[i] = i;
		}

		sort(indices.begin(), indices.end(), [&](int a, int b) {
			return positions[a] < positions[b];
		});

		for (int i = 0; i < n; i++) {

			int index = indices[i];

			if (directions[index] == 'R') {

				stack.push(index);

			} else {

				while (!stack.empty() && healths[index] > 0) {

					int top = stack.top();
					stack.pop();

					if (healths[top] > healths[index]) {

						healths[top] -= 1;
						healths[index] = 0;
						stack.push(top);

					} else if (healths[top] < healths[index]) {

						healths[index] -= 1;
						healths[top] = 0;

					} else {

						healths[top] = 0;
						healths[index] = 0;

					}

				}

			}

		}

		for (int i = 0; i < n; i++) {

			if (healths[i] > 0) {

				result.push_back(healths[i]);

			}

		}

		return result;

	}

};