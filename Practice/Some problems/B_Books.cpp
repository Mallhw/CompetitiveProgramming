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
    int N, T; cin >> N >> T;
    vector<int> arr(N);
    for(int i = 0; i < N; i++) 
    {
        cin >> arr[i];
    }

    vector<int> psum(N+1);
    for(int i = 0; i < N; i++)
    {
        psum[i+1] = psum[i] + arr[i];
    }

    psum.push_back(psum.back());

    int ans = 0;

    for(int i = 0; i < N; i++)
    {
        int hi = N, lo = i;
        while(lo < hi)
        {
            int mid = (hi + lo) / 2;
            if(psum[mid+1] - psum[i] <= T)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }

        //dbg(i);
        //dbg(hi);
        ans = max(ans, hi - i);
    }

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

