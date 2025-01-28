#include <bits/stdc++.h> 
using namespace std; 
#define min(a, b) ((a > b) ? b : a) 
typedef long long int ll; 
typedef vector<long long> vll;


void solve(const vll& remainders, ll M) {
    ll ans = LLONG_MAX;
    
    for(ll i = 0; i * i <= M; i++) {
        ll X = i * i;  

        ll totalOperations = 0;
        for(ll r : remainders) {
            ll diff = abs(r - X);
            totalOperations += min(diff, abs(M - diff)); 
        }
        ans = min(ans, totalOperations); 
    }

    cout << ans << endl;
    return;
}

int main() { 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        ll n, m;
        cin >> n >> m;
        vll arr(n);
        vll remainders(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            remainders[i] = arr[i] % m;
        }
        solve(remainders, m);
    } 
    return 0; 
}
