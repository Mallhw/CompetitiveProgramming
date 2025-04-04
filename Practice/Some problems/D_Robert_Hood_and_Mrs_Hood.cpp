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
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,
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
    int N, D, K; 
    cin >> N >> D >> K;
    indexed_set starts, ends;
    //dbg(num_tc);

    for(int i = 0; i < K; i++)
    {
        int l, r; cin >> l >> r;
        starts.insert(l);
        ends.insert(r);
    }

    int a1 = 1e9, a2 = 0;
    int ans1 = 0, ans2 = 0;

    for(int i = N; i >= D; i--)
    {
        int start = i-D+1, end = i;
        int startsBeforeEnd = starts.order_of_key(end+1);
        int endsBeforeStart = ends.order_of_key(start);
        //dbg(start);
        //dbg(end);
        //dbg(startsBeforeEnd);
        //dbg(endsBeforeStart);

        a1 = min(a1, startsBeforeEnd - endsBeforeStart);
        if(a1 == startsBeforeEnd - endsBeforeStart) ans1 = start;

        a2 = max(a2, startsBeforeEnd - endsBeforeStart);
        if(a2 == startsBeforeEnd - endsBeforeStart) ans2 = start;
    }

    cout << ans2 << " " << ans1 << endll;
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

