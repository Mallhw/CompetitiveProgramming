long long prim(const vector<vector<pair<int, int>>> &neighbors) {

	const int n = neighbors.size();  // just a shorthand
	long long min_cost = 0;
	vector<long long> dist(n, std::numeric_limits<long long>().max());
	dist[0] = 0;
	std::priority_queue<pair<long long, int>> q;
	q.push({0, 0});
	vector<bool> visited(n);
	int added = 0;
	while (added < n) {

		if (q.empty()) { return -1; }
		auto [curr_cost, v] = q.top();
		q.pop();
		curr_cost *= -1;
		if (dist[v] < curr_cost) { continue; }

		added++;
		visited[v] = true;

		min_cost += curr_cost;
		for (auto &[next, n_cost] : neighbors[v]) {
			if (!visited[next] && n_cost < dist[next]) {
				dist[next] = n_cost;
				q.push({-n_cost, next});
			}
		}
	}

	return min_cost;
}