/*
Author: taha-r
Bismillah
*/

#include <algorithm>
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
    vector<string> grid(8);

    for(int i = 0; i < 8; i++)
    {
        cin >> grid[i];
    }

    vector<int> order{1, 2, 3, 4, 5, 6, 7, 8};
    ll ans = 0;
    do
    {
        set<int> a{}, b{};
        for(int i = 0; i < 8; i++)
        {
            int c = order[i] - 1;
            if(grid[i][c] == '*') 
            {
                break;
            }

            a.insert(c-i);
            b.insert(c+i);
        }

        ans += a.size() == 8 && b.size() == 8;
    } while (next_permutation(all(order)));

    cout << ans << endll;
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

