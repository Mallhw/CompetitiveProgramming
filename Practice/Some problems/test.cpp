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
#define MOD ll(3359232)
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

void feed(int val)
{
    cout << "feed " << val << endl;
    string s; cin >> s;
    if(s != "OK") exit(0);
}

int poop()
{
    cout << "poop" << endl;
    int x; cin >> x;
    return x;
}

ll binExp(ll a, ll b) {
  if (b == 0)
    return 1;

  ll res = binExp(a, b / 2) % MOD;
  if (b & 1) {
    return (a * ((res * res) % MOD)) % MOD;
  } else
    return (res * res) % MOD;
}

void solve(int num_tc)
{
    ll ans = 0;
    for(int i = 0; i < 100; i++) for(int j = i+1; j < 100; j++) for(int k = j+1; k < 100; k++) for(int l = k+1; l < 100; l++) for(int m = l+1; m < 100; m++)
    {
        set<int> digits{};
        digits.insert(i%10);
        digits.insert(j%10);
        digits.insert(k%10);
        digits.insert(l%10);
        digits.insert(m%10);
        digits.insert(i/10);
        digits.insert(j/10);
        digits.insert(k/10);
        digits.insert(l/10);
        digits.insert(m/10);

        if(digits.size() == 10) 
        {
            vector<int> v{i, j, k, l, m};
            cout << v << endl;
            ans += (i+j+k+l+m);
        }
    }

    cout << ans << endl;
}


int main()
{ 
    solve(0);
}

