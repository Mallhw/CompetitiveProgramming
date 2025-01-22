#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
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
#define MOD 998244353 

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        ll n;
        cin >> n;
        vll arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        ll ans = 0;
        vll dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n; i++) {
            if(arr[i] == arr[i - 1]) {
                dp[i] = (dp[i-1] + dp[i]) % MOD;
            }
            if(arr[i] == arr[i - 2] + 1) {
                dp[i] = (dp[i] + dp[i - 2]) % MOD;
            }
        }
        cout << dp[n] + dp[n-1] << endl;
    } 
    return 0; 
} 
