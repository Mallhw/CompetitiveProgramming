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
    dbg(num_tc);
    if(N%2==0)
    {
        ll K = 0;
        set<int> used{};
        vector<int> ans{};
        for(int i = 0; i < N; i++)
        {
            used.insert(i+1);
            K |= i+1;
        }

        used.erase(N);
        ans.push_back(N);

        for(int i = log2(N) - 1; i > 0; i--)
        {
            ans.push_back((1 << (i+1)) - 1);
            used.erase((1 << (i+1)) - 1);

            ans.push_back(1 << i);
            used.erase(1 << i);
            dbg(i);
        }

        while(!used.empty()) 
        {
            //ans.push_back(*used.begin());
            used.erase(used.begin());
        }

        cout << K << endll;
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endll;
    }
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

