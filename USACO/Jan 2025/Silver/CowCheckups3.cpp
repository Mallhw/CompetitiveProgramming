#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
typedef long long int ll; 
typedef vector<long long> vll;



int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    ll n;
    cin >> n;
    vll a(n);
    vll b(n);
    unordered_map<ll, vll> freq;

    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(ll i = 0; i < n; i++) {
        cin >> b[i];
        freq[b[i]].push_back(i);
    }



    
    ll ans = 0;
    for(ll k = 0; k < n; k++) {
        ll cur = a[k];
        if(a[k] == b[k]) {
            ll reversalsAsMedian = n + min(k, (n-1) - k) + (max((k * (k - 1)) / 2, 0LL) + max(((n - k - 2) * (n - k - 1) ) / 2, 0LL));
            ans += reversalsAsMedian;
            for(auto &i : freq[cur]) {
                if(k != i) ans += (min(min(k, i), (n-1) - max(k, i)) + 1);
            }
        }
        else {
            for(auto &i : freq[cur]) {
                if(k != i) ans += (min(min(k, i), (n-1) - max(k, i)) + 1);
            }
        }
    }
    cout << ans << endl;
    return 0; 
} 
