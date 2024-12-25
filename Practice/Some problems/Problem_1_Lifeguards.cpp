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
    int N; cin >> N;
    vector<pair<int, int>> arr{};
    int s = 1e9, e = 0;
    for(int i = 1; i <= N; i++)
    {
        int a, b; cin >> a >> b;
        arr.push_back({a, i});
        arr.push_back({b, -i});
    }

    sort(all(arr));
    set<int> active{};
    vector<int> ratings(N+1);
    int prev = arr[0].first, total = 0, prev2 = arr[0].first;
    for(int i = 0; i < arr.size(); i++)
    {
        if(active.size() >= 1)
        {
            total += arr[i].first - prev2;
        }

        if(arr[i].second < 0) 
        {
            if(active.size() == 1)
            {
                ratings[*active.begin()] += arr[i].first - prev;
            }

            active.erase(-1*arr[i].second);
            prev = arr[i].first;
        }
        else 
        {
            if(active.size() == 1)
            {
                ratings[*active.begin()] += arr[i].first - prev;
            }
            
            active.insert(arr[i].second);
        }

        prev2 = arr[i].first;
    }

    //dbg(ratings);

    int ans = 1e9;
    for(int i = 1; i <= N; i++) ans = min(ans, ratings[i]);
    cout << total - ans << endll;
}


int main()
{
    open("lifeguards.in", "lifeguards.out");
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++)
    {
        solve(t+1);
    }
}

