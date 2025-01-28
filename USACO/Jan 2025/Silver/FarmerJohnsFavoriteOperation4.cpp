#include <bits/stdc++.h>
using namespace std;
#define min(a, b) ((a > b) ? b : a)
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
    vll s = mods;
    sort(s.begin(), s.end());
    ll n = s.size();
    ll ans = LLONG_MAX;

    ll k = (n + 1) / 2;
    for(int i = max(0LL, k - 2); i < min(n, k + 2); ++i) {
        ans = min(ans, cal(s, M, s[i]));
    }
        ans = min(ans, cal(s, M, s[0]));
        ans = min(ans, cal(s, M, s.back()));
        ans = min(ans, cal(s, M, (s[0] + M / 2) % M));
        ans = min(ans, cal(s, M, (s.back() + M / 2) % M));
        ans = min(ans, cal(s, M, s[0]));
        ans = min(ans, cal(s, M, s.back()));
        ans = min(ans, cal(s, M, (s[0] + M / 3) % M));
        ans = min(ans, cal(s, M, (s.back() + M / 2) % M));
        for(int i = max(0LL, k - 2); i < min(n, k + 2); ++i) {
            ans = min(ans, cal(s, M, s[i]));
        }
    

    cout << ans << endl;
    return;
}


void solve1(const vll& mods, ll m) {
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
        ll temp;
        vll mods(n);
        for(int i = 0; i < n; i++) {
            cin >> temp;
            mods[i] = temp % m;
        }


        if(m <= 10e4) {
            solve1(mods, m);
        }
        else if(n <= 10e4) {
            solve1(mods, m);
        }
        else {
            solve2(mods, m);
        }
        
    }
    return 0;
}