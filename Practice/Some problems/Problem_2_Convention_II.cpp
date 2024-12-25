/*
Author: taha-r
Bismillah
*/

#include <queue>
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
    vector<pair<pair<int, int>, int>> cows(N);
    for(int i = 0; i < N; i++)
    {
        cin >> cows[i].first.first >> cows[i].first.second;
        cows[i].second = -i;
    }

    sort(rall(cows));

    priority_queue<pair<int, pair<int, int>>> arrived{};

    ll nextTime = 0, ans = 0;
    while(!cows.empty() || !arrived.empty())
    {
        while(!cows.empty() && cows.back().first.first <= nextTime)
        {
            auto cur = cows.back();
            arrived.push({cur.second, cur.first});
            cows.pop_back();
        }

        if(arrived.empty())
        {
            auto cur = cows.back();
            arrived.push({cur.second, cur.first});
            cows.pop_back();

            nextTime = cur.first.first;
        }

        auto cur = arrived.top();
        arrived.pop();

        ll waitTime = nextTime - cur.second.first;
        nextTime += cur.second.second;

        ans = max(ans, waitTime);
    }

    cout << ans << endll;
}


int main()
{
    open("convention2.in", "convention2.out");
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++)
    {
        solve(t+1);
    }
}

