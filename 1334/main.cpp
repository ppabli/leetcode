#include <vector>

using namespace std;

class Solution {
public:
	int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

		// Create a matrix to store the distances between the nodes
		vector<vector<int>> dist(n, vector<int>(n, numeric_limits<int>::max()));

		// Initialize the diagonal of the matrix to 0. Distances from a node to itself are 0
		for (int i = 0; i < n; i++) {

			dist[i][i] = 0;

		}

		// Populate the matrix with the data from the edges
		for (auto& edge : edges) {

			dist[edge[0]][edge[1]] = edge[2];
			dist[edge[1]][edge[0]] = edge[2];

		}

		// Floyd-Warshall algorithm
		for (int k = 0; k < n; k++) {

			for (int i = 0; i < n; i++) {
	
				for (int j = 0; j < n; j++) {

					if (dist[i][k] != numeric_limits<int>::max() && dist[k][j] != numeric_limits<int>::max()) {

						dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

					}

				}

			}

		}

		// Initialize the result to -1
		int res = -1;

		// Initialize the minimum number of reachable cities to n
		int minCities = n;

		// Iterate over the nodes
		for (int i = 0; i < n; i++) {

			// Initialize the number of reachable cities to 0
			int reachableCities = 0;

			// Iterate over the distances from the current node to the other nodes
			for (int j = 0; j < n; j++) {

				// If the distance is less than the threshold, increment the number of reachable cities
				if (dist[i][j] <= distanceThreshold) {

					reachableCities++;

				}

			}

			// If the number of reachable cities is less than the minimum number of reachable cities, update the result
			if (reachableCities <= minCities) {

				minCities = reachableCities;
				res = i;

			}

		}

		return res;

	}

};