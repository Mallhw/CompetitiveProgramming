#include <bits/stdc++.h> 
using namespace std; 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
typedef long long int ll; 
typedef vector<long long> vll;


int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int t; 
    cin >> t; 
    while (t--) { 
        ll n, m;
        cin >> n >> m;
        vll arr(n);
        vll mods(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            mods[i] = arr[i] % m;
        }


        ll ans = LLONG_MAX;
        for(auto x : mods) {
            ll cur = 0;
            for(ll val : mods) {
                ll d = abs(val - x);
                cur += min(d, m - d); 
            }
            ans = min(ans, cur); 
        }

    cout << ans << endl;
    } 
    return 0; 
} 
