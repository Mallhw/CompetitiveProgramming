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


vector<string> grid;

void doGravity()
{
    for(int j = 0; j < 10; j++)
    {
        int ind = grid.size() - 1;
        for(int i = grid.size() - 1; i >= 0; i--)
        {
            grid[ind][j] = grid[i][j];
            if(grid[i][j] != '0') ind--;
        }

        for(; ind >= 0; ind--)
        {
            grid[ind][j] = '0';
        }
    }
}

vector<vector<bool>> visited{}, visited2;
int rDirs[] = {1, -1, 0, 0};
int cDirs[] = {0, 0, 1, -1};
int compSize = 0;

void dfs(int r, int c)
{
    visited[r][c] = true;
    compSize++;

    for(int k = 0; k < 4; k++)
    {
        int nr = r + rDirs[k], nc = c + cDirs[k];
        if(nr < 0 || nc < 0 || nr >= visited.size() || nc >= visited[0].size())
        {
            continue;
        }

        if(grid[nr][nc] == grid[r][c] && !visited[nr][nc])
        {
            dfs(nr, nc);
        }
    }
}

void dfs2(int r, int c)
{
    visited2[r][c] = true;
    for(int k = 0; k < 4; k++)
    {
        int nr = r + rDirs[k], nc = c + cDirs[k];
        if(nr < 0 || nc < 0 || nr >= visited2.size() || nc >= visited2[0].size())
        {
            continue;
        }

        if(grid[nr][nc] == grid[r][c] && !visited2[nr][nc])
        {
            dfs2(nr, nc);
        }
    }

    grid[r][c] = '0';
}

void solve(int num_tc)
{
	int N, K; cin >> N >> K;
    grid = vector<string>(N);
    
    for(int i = 0; i < N; i++) cin >> grid[i];

    while(true) 
    {
        visited = vector<vector<bool>>(N, vector<bool>(10));
        visited2 = vector<vector<bool>>(N, vector<bool>(10));

        bool found = false;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(grid[i][j] == '0') continue;
                if(!visited[i][j])
                {
                    compSize = 0;
                    dfs(i, j);
                    
                    if(compSize >= K)
                    {
                        found = true;
                        dfs2(i, j);
                    }
                }
            }
        }

        if(!found) break;

        doGravity();
    }

    for(int i = 0; i < N; i++) cout << grid[i] << endll;
}


int main()
{
    open("mooyomooyo.in", "mooyomooyo.out");
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++)
    {
        solve(t+1);
    }
}

