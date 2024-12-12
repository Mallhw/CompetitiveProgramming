#include <deque>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node) {
	for (int n : adj[node]) {
		if (!visited[n]) {
			visited[n] = true;
			dfs(n);
		}
	}
}

int main() {
	int n;
	int m;
	cin >> n >> m;
	adj = vector<vector<int>>(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[--a].push_back(--b);
		adj[b].push_back(a);
	}

	visited = vector<bool>(n);
	vector<int> city_reps;
	for (int i = 0; i < n; i++) {
		if (visited[i]) { continue; }

		visited[i] = true;
		city_reps.push_back(i);
		dfs(i);
	}

	cout << city_reps.size() - 1 << '\n';
	for (int i = 0; i < city_reps.size() - 1; i++) {
		cout << city_reps[i] + 1 << ' ' << city_reps[i + 1] + 1 << '\n';
	}
}
