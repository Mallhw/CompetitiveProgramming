//Shortest distance from node X to all nodes in weighted graph (slow)
//Input: Edge List, node X, size of graph (N)
//Output: Distance array, bool - if contains neg cycle
//
//Time - O(NM), Space - O(N + M)
bool bellman_ford(vector<ll>& distance, vector<pair<pair<ll, ll>,ll>>& edges, ll x, ll n)
{
	for (int i = 0; i < n; i++) distance[i] = INF;
	distance[x] = 0;
	for (int i = 0; i < n-1; i++) 
	{
		for (auto e : edges) 
		{
			ll a, b, w;
			a = e.first.first;
			b = e.first.second;
			w = e.second;
			distance[b] = min(distance[b], distance[a] + w);
		}
	}
	
	bool negCycle = false;
	for (auto e : edges) 
	{
		ll a, b, w;
		a = e.first.first;
		b = e.first.second;
		w = e.second;
		if(distance[b] > distance[a] + w)
		{
			negCycle = true;
			break;
		}
	}
	
	return negCycle;
}