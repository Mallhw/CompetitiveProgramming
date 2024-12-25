//All-Pairs Shortest Path - O(N^3) time, O(N^2) memory
//With negative edges
//Output: matrix of distances from node i to node j
//Input: adjacency matrix of graph
void floyd_warshall(vector<vector<ll>> &distance, vector<vector<ll>> &adj)
{
	int N = sz(adj);
	
	assert(sz(adj) == sz(distance));s
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) distance[i][j] = 0;
			else if (adj[i][j]) distance[i][j] = adj[i][j];
			else distance[i][j] = INF;
		}
	}
	
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				distance[i][j] = min(distance[i][j],
									distance[i][k]+distance[k][j]);
			}
		}
	}
}