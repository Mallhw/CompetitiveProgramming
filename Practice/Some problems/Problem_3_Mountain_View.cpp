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
    int N; cin >> N;
    vector<pair<int, int>> events{};
    vector<pair<int, int>> starts{};
    for(int i = 0; i < N; i++)
    {
        int a, b; cin >> a >> b;
        starts.push_back({a-b, b});
    }

    sort(all(starts));

    for(int i = 0; i < starts.size(); i++)
    {
        events.push_back({starts[i].first, i+1});
        events.push_back({starts[i].first + 2*starts[i].second, -(i+1)});
    }

    sort(all(events));

    set<int> active{};
    int ans = N;
    
    for(int i = 0; i < events.size(); i++)
    {
        if(events[i].second > 0)
        {
            //interval starting
            active.insert(events[i].second);
        }
        else 
        {
            //interval ending
            if(*active.begin() != -1*events[i].second)
            {
                ans--;
            }
            active.erase(-1*events[i].second);
        }
    }

    cout << ans << endll;
}


int main()
{
    //open("mountains.in", "mountains.out");
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++)
    {
        solve(t+1);
    }
}

