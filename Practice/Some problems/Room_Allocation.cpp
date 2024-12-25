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
    cerr << endll;
	for (T &x : arr) {
		os << x.first << ", " << x.second << endll;
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
    int N; cin >> N;
    vector<pair<int, int>> entries{};
    for(int i = 0; i < N; i++)
    {
        int a, b; cin >> a >> b;
        entries.push_back({a, -(i+1)});
        entries.push_back({b, +(i+1)});
    }

    sort(all(entries));

    vector<int> ans(N);
    set<int> unused{};
    int nextRoom = 1;

    for(int i = 0; i < entries.size(); i++)
    {
        if(entries[i].second < 0)
        {
            if(unused.size() < 1)
            {
                unused.insert(nextRoom);
                nextRoom++;
            }

            int cur = *unused.begin();
            unused.erase(cur);

            ans[-1*(entries[i].second + 1)] = cur;
        }
        else 
        {
            unused.insert(ans[entries[i].second - 1]);
        }
    }

    cout << nextRoom - 1 << endll;
    for(int i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
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

