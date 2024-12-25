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
    vll dp(n);
    // dp[0] = 0;
    // for(ll i = 1; i < n; i++) {
    //     dp[i] = (1+2*dp[i-1]) % mod;
    // }
    dp[0] = 1;
    ll coins[] = {1, 2, 3, 4, 5, 6};
    for (int x = 1; x <= n; x++) {
        for (auto c : coins) {
            if (x-c >= 0) {
            dp[x] += dp[x-c];
        }
    }
}
    cout << (dp[n-1] + 1) << endl;
    return 0; 
} 
