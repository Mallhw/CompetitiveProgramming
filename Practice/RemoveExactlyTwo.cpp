#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
#define mod 1000000007 
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++) 
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
#define INF 1000000000000000003 
typedef long long int ll; 
typedef vector<long long> vll;
typedef vector<int> vi; 
typedef pair<int, int> pi; 
#define F first 
#define S second 
#define PB push_back 
#define POB pop_back 
#define MP make_pair 
void dfs(ll u, vector<vector<ll>> &adj, vector<bool> &visited, vector<ll> &degree) {
    visited[u] = true;
    for (ll v : adj[u]) {
        if (!visited[v] && degree[v] > 0) {
            dfs(v, adj, visited, degree);
        }
    }
}

void solve() {
    ll n;
        cin >> n;
        if(n == 2) {
            cout << 0 << endl;
            return;
        } 
        vector<vector<ll>> adj(n + 1);
        vector<ll> degree(n + 1, 0);

        // Read the tree edges
        for (ll i = 0; i < n - 1; ++i) {
            ll u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        // Sort nodes by degree
        vector<pair<ll, ll>> nodes; // {degree, node}
        for (ll i = 1; i <= n; ++i) {
            nodes.emplace_back(degree[i], i);
        }
        sort(nodes.rbegin(), nodes.rend());

        // Remove the two nodes with the highest degrees
        ll max_components = 0;
        for (int i = 0; i < 2; ++i) {
            ll node = nodes[i].second;

            // Remove this node and its edges
            for (ll neighbor : adj[node]) {
                degree[neighbor]--;
            }
            degree[node] = 0;
        }

        // Count connected components
        vector<bool> visited(n + 1, false);
        for (ll i = 1; i <= n; ++i) {
            if (!visited[i] && degree[i] > 0) {
                max_components++;
                dfs(i, adj, visited, degree);
            }
        }

        cout << max_components << endl;
}
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) {
        solve();
    } 
    return 0; 
} 
