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
#define MOD ll(1000000007)
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    cin >> T;

    vector<ll> arr(1e5+5);
    for(int i = 1; i < arr.size(); i++)
    {
        arr[i] = (arr[i-1] + (i/2 - (ll)(i%2 == 0))*2 + MOD) % MOD;
    }

    for(int i = 0; i < 10; i++) cout << arr[i] << endll;
    cout << endll;

    vector<ll> psum(arr.size() + 1);
    for(int i = 0; i < arr.size(); i++)
    {
        psum[i+1] = (psum[i] + arr[i]) % MOD;
    }

    for(ll t = 0; t < T; t++)
    {
        ll l, r; cin >> l >> r;
        cout << (psum[r] - psum[l-1] + MOD) % MOD << endll;
    }
}

