#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll; 
const ll MOD = 1000000007;
ll modPow(ll x, ll exp) {
    long long o = 1;
    x %= MOD;
    while(exp > 0) {
        if(exp & 1) o = (o * x) % MOD;
        x = (x * x) % MOD;
        exp >>= 1;
    }
    return o;
}

void sol() {
    ll k, n, l; string T;
    cin >> k >> n >> l >> T;
    ll ans = 1;
    ll M = 0;  
    if(k == 2) {
        cout << 1 << endl;
        return;
    }
    for(char c : T) {
        if(c == 'M') {
            M++;
        } 
        else {
            ans = (ans * M) % MOD;
            M--;
        }
    }
    if(k == 1 && l != 1) {
        cout << modPow(ans, l) % MOD << endl;
        return;
    }
    cout << ans % MOD;
    return;
}
 
int main(){
    sol();
    return 0;
}
