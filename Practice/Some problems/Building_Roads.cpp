/*
Author: taha-r
Bismillah
*/

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

#define endll '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) ll((a).size())
#define MOD ll(1e9+7)
#define INF ll(2e63-1)

inline void open(const char *fin, const char *fout)
{
    freopen(fin, "r", stdin);
    freopen(fout, "w", stdout);
}

#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;

template <typename T> ostream &operator<<(ostream &os, vector<T> &arr) {
	os << "[";
	for (T &x : arr) {
		os << x << " ";
	}
	os << "]";
	return os;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &x) {
	os << "(" << x.first << ", " << x.second << ")";
	return os;
}


vector<vector<int>> adjList{};
vector<int> visited{};
map<int, int> reps{};

void dfs(int node, int comp)
{
    visited[node] = comp;
    reps[comp] = node;
    for(int neighbor : adjList[node])
    {
        if(!visited[neighbor]) dfs(neighbor, comp);
    }
}

void solve(int num_tc)
{
	int N, M; cin >> N >> M;
    adjList.resize(N);
    visited.resize(N);

    for(int i = 0; i < M; i++)
    {
        int u, v; cin >> u >> v;
        u--; v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int ans = 0;
    for(int i = 0; i < N; i++)
    {
        if(!visited[i])
        {
            ans++;
            dfs(i, ans);
        }
    }


    cout << ans-1 << endll;
    for(int i = 1; i < ans; i++)
    {
        cout << reps[i]+1 << " " << reps[i+1]+1 << endll;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++)
    {
        solve(t+1);
    }
}

