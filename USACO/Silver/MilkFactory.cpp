#include <fstream>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
	std::ifstream read("factory.in");
	int station_num;
	read >> station_num;

	vector<vector<int>> neighbors(station_num);
	for (int w = 0; w < station_num - 1; w++) {
		int s1, s2;
		read >> s1 >> s2;
		neighbors[--s2].push_back(--s1);
	}

	// The station which all others should be able to reach
	int root = -1;
	// Check all stations and see if they can be the root
	for (int s = 0; s < station_num; s++) {
		vector<bool> visited(station_num);
		// We can always reach a station from itself
		visited[s] = true;

		// Our stack for DFS
		vector<int> todo{s};
		while (!todo.empty()) {
			int curr = todo.back();
			todo.pop_back();
			for (int n : neighbors[curr]) {
				// Make sure to only visited unvisited nodes
				if (!visited[n]) {
					visited[n] = true;
					todo.push_back(n);
				}
			}
		}

		// Check if all nodes have been visited
		bool valid = true;
		for (int check_s = 0; check_s < station_num; check_s++) {
			if (!visited[check_s]) {
				valid = false;
				break;
			}
		}

		if (valid) {
			root = s + 1;
			break;
		}
	}

	std::ofstream("factory.out") << root << endl;
}