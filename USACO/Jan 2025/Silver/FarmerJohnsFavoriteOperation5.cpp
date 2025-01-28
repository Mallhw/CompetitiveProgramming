#include <bits/stdc++.h> 
using namespace std; 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
typedef long long int ll; 
typedef vector<long long> vll;




ll cal(const vll& mods, ll m, ll x) {
    ll ans = 0;
    for(ll r : mods) {
        ll d = abs(r - x);
        ans += min(d, m - d); 
    }
    return ans;
}

void solve2(const vll& mods, ll M) {
    ll ans = LLONG_MAX;
    for(auto &X : mods) {
        ll cur = 0;
        for(ll r : mods) {
            ll d = abs(r - X);
            cur += min(d, abs(M - d)); 
        }
        ans = min(ans, cur); 
    }

    cout << ans << endl;
    return;
}

void solve(const vector<ll>& mods, ll M, ll n) {
    ll l = 0, r = n - 1; 
    ll ans = LLONG_MAX;
    
    while (r - l >= 3582) {
        ll mid1 = l + ((r - l) / 3);
        ll mid2 = r - ((r - l) / 3);
        mid1 = max(mid1, l); 
        mid2 = min(mid2, r);  

        ll curl = cal(mods, M, mods[mid1]);
        ll curr = cal(mods, M, mods[mid2]);
        ans = min(ans, curl);
        ans = min(ans, curr);

        if (curl < curr) {
            r = mid2 - 1;
        } else {
            l = mid1 + 1;
        }
    }
    for (ll X = max(l - 1, 0LL); X <= min(r + 1, n - 1); X++) {
        ans = min(ans, cal(mods, M, mods[X]));
    }

    cout << ans << endl;
    return;
}



int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    ll T; 
    cin >> T; 
    while (T--) { 
        ll n, m;
        cin >> n >> m;
        ll temp;
        vll mods(n);
        for(ll i = 0; i < n; i++) {
            cin >> temp;
            mods[i] = temp % m;
        }


        sort(mods.begin(), mods.end());
        solve(mods, m, n);
    } 
    return 0; 
} 
