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


void solve(int num_tc)
{
	ll N, Q; cin >> N >> Q;

    vector<vector<int>> grid(N+1, vector<int>(N+1));
    for(int i = 0; i < N; i++)
    {
        string s; cin >> s;
        for(int j = 0; j < N; j++)
        {
            grid[i+1][j+1] = s[j] == '*';
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            grid[i+1][j+1] += grid[i+1][j] + grid[i][j+1] - grid[i][j];
        }
    }

    for(int q = 0; q < Q; q++)
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << grid[x2][y2] - grid[x1-1][y2] - grid[x2][y1-1] + grid[x1-1][y1-1] << endll;
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

