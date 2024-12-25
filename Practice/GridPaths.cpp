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
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    ll n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    ll ans = 0;
    vector<vector<ll>> dp(n, vector<ll>(n));
    if(grid[0][0] == '*') {
        cout << 0 << endl;
        return 0;
    }
    dp[0][0] = 1;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            if(grid[i][j] == '.') {
                if(i != 0 && j != 0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                else if((i != 0 && j == 0 && dp[i-1][j] == 1)) {
                    dp[i][j] = 1;
                }
                else if(j != 0 && i == 0 && dp[i][j-1] == 1) {
                    dp[i][j] = 1;
                }
                dp[i][j] %= mod;
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    cout << dp[n-1][n-1] % mod << endl;
    return 0; 
} 
