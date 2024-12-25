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
#define INF ll(2e50-1)

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


void solve(int num_tc)
{
    int N, M, H; cin >> N;

    set<int> horses{};
    for(int i = 0; i < H; i++) 
    {
        int a; cin >> a;
        horses.insert(a);
    }

    vector<pair<ll, ll>> adj[N];

    for(int i =0 ; i < M; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<array<ll, 2>> distance1(N, {INF, INF});
	priority_queue<array<ll, 3>> q{};
	
	distance1[0][0] = 0;
	q.push({0,0, 0});
	
	while (!q.empty()) 
	{
        auto cur = q.top();
		ll a = q.top()[1], b = q.top()[2];
        q.pop();
        
        if (b)
        {
		    for (auto u : adj[a]) 
		    {
		    	ll next = u.first, w = u.second/2;
		    	if (distance1[a][b] + w < distance1[next][b])
		    	{
		    		distance1[next][b] = distance1[a][b] + w;
		    		q.push({-distance1[next][b], next, b});
		    	}
		    }
        }
        else 
        {
		    for (auto u : adj[a]) 
		    {
		    	ll next = u.first, w = u.second;
		    	if (distance1[a][b] + w < distance1[next][b])
		    	{
		    		distance1[next][b] = distance1[a][b] + w;
		    		q.push({-distance1[next][b], next, b});
		    	}
		    }

            if(horses.count(a))
            {
                q.push({cur[0], cur[1], 1});
            }
        }
	}

    vector<array<ll, 2>> distance2(N, {INF, INF});
	q = priority_queue<array<ll, 3>>{};
	
	distance2[N-1][0] = 0;
	q.push({0,N-1, 0});
	
	while (!q.empty()) 
	{
        auto cur = q.top();
		ll a = q.top()[1], b = q.top()[2];
        q.pop();
        
        if (b)
        {
		    for (auto u : adj[a]) 
		    {
		    	ll next = u.first, w = u.second/2;
		    	if (distance2[a][b] + w < distance2[next][b])
		    	{
		    		distance2[next][b] = distance2[a][b] + w;
		    		q.push({-distance2[next][b], next, b});
		    	}
		    }
        }
        else 
        {
		    for (auto u : adj[a]) 
		    {
		    	ll next = u.first, w = u.second;
		    	if (distance2[a][b] + w < distance2[next][b])
		    	{
		    		distance2[next][b] = distance2[a][b] + w;
		    		q.push({-distance2[next][b], next, b});
		    	}
		    }

            if(horses.count(a))
            {
                q.push({cur[0], cur[1], 1});
            }
        }
	}

    ll ans = 1e18;
    cout << distance2[0][0] << endll;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++)
    {
        solve(t+1);
    }
}

