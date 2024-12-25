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
    vector<int> arr(N);
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    ll ans = 1e18;
    for(int start = 0; start < N; start++)
    {
        ll curDist = 0;
        multiset<ll> cows{};
        for(int i = start; i < start + N; i++)
        {
            //dbg(arr[i % N]);
            for(int c = 0; c < arr[i % N]; c++)
            {
                cows.insert(i);
            }

            if(cows.empty())
            {
                curDist = 1e18;
                break;
            }

            ll cur = *cows.begin();
            cows.erase(cows.find(cur));
            curDist += (i - cur) * (i - cur);
        }

        //cout << start << ", " << curDist << endl;

        ans = min(ans, curDist);
    }

    cout << ans << endll;
}


int main()
{
    open("cbarn.in", "cbarn.out");
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++)
    {
        solve(t+1);
    }
}

