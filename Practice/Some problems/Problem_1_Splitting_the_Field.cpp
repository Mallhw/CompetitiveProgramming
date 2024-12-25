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

template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &x) {
	os << "(" << x.first << ", " << x.second << ")";
	return os;
}

template <typename T> ostream &operator<<(ostream &os, vector<T> &arr) {
	os << "[";
	for (T &x : arr) {
		os << x << ", ";
	}
	os << "]";
	return os;
}


void solve(int num_tc)
{
    int N; cin >> N;
    vector<pair<ll, ll>> points(N);
    vector<array<ll, 2>> suffixBounds(N+1, {(ll)1e9, 0});

    for(int i = 0; i < N; i++)
    {
        cin >> points[i].first >> points[i].second;
    }

    sort(all(points));

    for(int i = N - 1; i >= 0; i--)
    {
        suffixBounds[i][0] = min(suffixBounds[i+1][0], points[i].second);
        suffixBounds[i][1] = max(suffixBounds[i+1][1], points[i].second);
    }
    
    for(int i = 0; i < N; i++)
    {
    }

    //sort by x
    ll ans = 1e18, top = 0, bot = 1e9;
    for(int i = 0; i < N; i++)
    {
        top = max(top, points[i].second);
        bot = min(bot, points[i].second);

        if(i == N - 1 || points[i].first == points[i+1].first) continue;

        ll right = points[0].first, left = points[i].first;
        ll rect1 = (top - bot) * (left - right);

        ll rect2 = (points.back().first - points[i+1].first) * (suffixBounds[i+1][1] - suffixBounds[i+1][0]);
        //cout << points[i].first << ": " << suffixBounds[i+1][1] << ", "<< suffixBounds[i+1][0] << ", "<< suffixBounds[i+1][3] << ", " << suffixBounds[i+1][2] << endll;
        //cout << points[i].first << ": " << rect1 << ", " << rect2 << endll;
        ans = min(ans, rect2 + rect1);
    }

    for(int i = 0; i < N; i++)
    {
        swap(points[i].first, points[i].second);
    }

    sort(all(points));

    for(int i = N - 1; i >= 0; i--)
    {
        suffixBounds[i][0] = min(suffixBounds[i+1][0], points[i].second);
        suffixBounds[i][1] = max(suffixBounds[i+1][1], points[i].second);
    }

    //sort by x
    top = 0, bot = 1e9;
    for(int i = 0; i < N; i++)
    {
        top = max(top, points[i].second);
        bot = min(bot, points[i].second);

        if(i == N - 1 || points[i].first == points[i+1].first) continue;

        ll right = points[0].first, left = points[i].first;
        ll rect1 = (top - bot) * (left - right);

        ll rect2 = (points.back().first - points[i+1].first) * (suffixBounds[i+1][1] - suffixBounds[i+1][0]);
        //cout << points[i].first << ": " << suffixBounds[i+1][1] << ", "<< suffixBounds[i+1][0] << ", "<< suffixBounds[i+1][3] << ", " << suffixBounds[i+1][2] << endll;
        //cout << points[i].first << ": " << rect1 << ", " << rect2 << endll;
        ans = min(ans, rect2 + rect1);
    }

    cout << (top - bot) * (points.back().first - points.front().first) - ans << endll;
}


int main()
{
    open("split.in", "split.out");
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++)
    {
        solve(t+1);
    }
}

