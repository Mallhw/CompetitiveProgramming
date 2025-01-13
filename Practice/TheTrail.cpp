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
void solve() {
    ll n, m;
    string path;
    cin >> n >> m >> path;
    vector<vector<ll>> grid(n, vector<ll>(m, 0));
    vll rowSum(n);
    vll colSum(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            rowSum[i] += grid[i][j];
            colSum[j] += grid[i][j];
        }
    }
    ll curRow = 0;
    ll curCol = 0;
    for(int i = 0; i < path.length(); i++) {
        if(path[i] == 'D') {
            grid[curRow][curCol] = -rowSum[curRow];
            colSum[curCol] += grid[curRow][curCol];
            rowSum[curRow] += grid[curRow][curCol];
            ++curRow;
        }
        else if(path[i] == 'R') {
            grid[curRow][curCol] = -colSum[curCol];
            rowSum[curRow] += grid[curRow][curCol];
            colSum[curCol] += grid[curRow][curCol];
            ++curCol;
        }
    }
    grid[curRow][curCol] = -rowSum[curRow];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
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
