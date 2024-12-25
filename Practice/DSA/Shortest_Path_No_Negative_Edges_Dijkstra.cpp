
//Shortest distance from node X to all nodes in weighted graph (fast)
//Input: Adjacency List, node X, size of graph (N)
//Output: Distance array & parent array to reconstruct path
//
//Time - O(NM), Space - O(N + M)
void dijkstra(vector<ll>& distance, vector<ll> &parents, vector<vector<pair<ll, ll>>> &adj, ll x, ll n)
{
	vector<bool> processed(n);
	priority_queue<pair<ll, ll>> q{};
	
	for (int i = 0; i < n; i++) distance[i] = INF;
	distance[x] = 0;
	q.push({0,x});
	
	while (!q.empty()) 
	{
		ll a = q.top().second; q.pop();
		if (processed[a]) continue;
		processed[a] = true;
		
		for (auto u : adj[a]) 
		{
			ll b = u.first, w = u.second;
			if (distance[a] + w < distance[b]) 
			{
				distance[b] = distance[a] + w;
				parents[b] = a;
				q.push({-distance[b], b});
			}
		}
	}
}