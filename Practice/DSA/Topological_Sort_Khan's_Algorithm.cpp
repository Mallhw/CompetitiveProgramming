
//Topological Sort of a DAG
//Time - O(N + E), Space - O(N + E)
//Input: normal and reverse adjacency list
//Output: sorted order of nodes
bool topSort(vector<ll>& sorted, vector<unordered_set<ll>>& adjList, vector<unordered_set<ll>>& radjList)
{
	int N = sz(adjList);
	vector<ll> noEdge{};
	
	for(ll i = 0; i < N; i++)
	{
		if(adjList[i].size() == 0) noEdge.push_back(i);
	}
	
	while(!noEdge.empty())
	{
		ll cur = noEdge.back();
		noEdge.pop_back();
		
		sorted.push_back(cur);
		for(ll n : radjList[cur])
		{
			if(adjList[n].size() == 0) continue;
			
			adjList[n].erase(cur);
			if(adjList[n].size() == 0) noEdge.push_back(n);
		}
	}
	
	bool possible = true;
	for(ll i = 0; i < N; i++)
	{
		possible = possible && adjList[i].empty();
	}
	
	return possible;
}