#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
#define mod 1000000007 
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++) 
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
#define INF 1000000000000000003 
typedef long long int ll; 
typedef vector<long long> vll;
typedef vector<int> vi; 
typedef pair<int, int> pi; 
#define F first 
#define S second 
#define PB push_back 
#define POB pop_back 
#define MP make_pair 
#ifndef VECTORDBG_H
#define VECTORDBG_H

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T> arr) {
    os << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        os << arr[i] << " ";
    }
    os << "]";
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& grid) {
    os << "[\n";
    for (const auto& row : grid) {
        os << "  " << row << "\n";
    }
    os << "]";
    return os;
}

#endif
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> grid(n, vector<ll>(m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<ll>> max_neighbor_grid(n, vector<ll>(m, -1));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            ll max_neighbor = -1;
            if (i > 0) max_neighbor = max(max_neighbor, grid[i - 1][j]);
            if (j > 0) max_neighbor = max(max_neighbor, grid[i][j - 1]);
            if (i < n - 1) max_neighbor = max(max_neighbor, grid[i + 1][j]);
            if (j < m - 1) max_neighbor = max(max_neighbor, grid[i][j + 1]);
            max_neighbor_grid[i][j] = max_neighbor;
        }
    }  
    dbg(max_neighbor_grid);    
}
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        solve();
    } 
    return 0; 
} 
