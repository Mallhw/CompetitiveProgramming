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

vector<vector<pair<int, int>>> allPaths{};

int xDirs[] = {0, 0, 1, -1};
int yDirs[] = {1, -1, 0, 0};

void generatePaths(vector<pair<int, int>> cur)
{
    if(cur.size() == 49)
    {
        if(cur.back().first == 0 && cur.back().second == 7) allPaths.push_back(cur);
        return;
    }

    if(cur.back().first == 0 && cur.back().second == 7) return;

    vector<bool> toTravel(4, false);

    for(int i = 0; i < 4; i++)
    {
        int x = cur.back().first + xDirs[i];
        int y = cur.back().second + yDirs[i];
        if(x < 0 || y < 0 || x > 7 || y > 7) continue;
        if(count(all(cur), make_pair(x, y))) continue;

        toTravel[i] = true;
    }

    if(!toTravel[0] && !toTravel[1] && toTravel[2] && toTravel[3])
    {
        return;
    }

    if(!toTravel[0] && !toTravel[1] && toTravel[2] && toTravel[3])
    {
        return;
    }
    
    for(int i = 0; i < 4; i++)
    {
        int x = cur.back().first + xDirs[i];
        int y = cur.back().second + yDirs[i];
        if(toTravel[i])
        {
            cur.push_back({x, y});
            generatePaths(cur);
            cur.pop_back();
        }
    }
}

void solve(int num_tc)
{
    generatePaths({{0, 0}});
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

