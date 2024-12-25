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
	int N, Q; cin >> N >> Q;
    vector<array<int, 3>> psum(N+1);

    for(int i = 0; i < N; i++) for(int j = 0; j < 3; j++) psum[i][j] = 0;
    
    for(int i = 0; i < N; i++)
    {
        int a; cin >> a;
        psum[i+1][a-1]++;
        for(int j = 0; j < 3; j++) psum[i+1][j] += psum[i][j];
    }

    for(int i = 0; i < Q; i++)
    {
        int l, r; cin >> l >> r;
        cout << psum[r][0] - psum[l-1][0] << " " << psum[r][1] - psum[l-1][1] << " " << psum[r][2] - psum[l-1][2] << endll;
    }
}


int main()
{
    open("bcount.in", "bcount.out");
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++)
    {
        solve(t+1);
    }
}

