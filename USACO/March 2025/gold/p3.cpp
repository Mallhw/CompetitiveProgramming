#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll; 
const ll MOD = 1000000007;
void sol() {
    ll n, d, a, b;
    cin >> n >> d >> a >> b;
    vector<ll> m(n);
    for(int i = 0; i < n; i++) cin >> m[i];
    sort(m.begin(), m.end());
    for(int i = 0; i < d; i++) {
        for(int i = 0; i < a; i++) {
            m[n - i - 1] += 1;
        }
        for(int i = 0; i < b; i++) {
            m[n - i - 1] -= 1;
        }
        sort(m.begin(), m.end());
    }
    ll sum = 0;
    // for(int i = 0; i < n; i++) {
    //     cout << m[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i < n; i++) {
        ll x = ((m[i] % MOD) + MOD) % MOD;
        sum = (sum + (x * x) % MOD) % MOD;
    }
    cout << sum << endl;
}
int main() 
{ 
    sol();
    return 0; 
} 
