#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long

void solve() {
    ll a, b, k;
    cin >> a >> b >> k;

    vector<ll> boy(k), girl(k);
    for (ll i = 0; i < k; i++) {
        cin >> boy[i];
    }
    for (ll i = 0; i < k; i++) {
        cin >> girl[i];
    }

    map<ll, ll> boy_count, girl_count;
    for (ll i = 0; i < k; i++) {
        boy_count[boy[i]]++;
        girl_count[girl[i]]++;
    }

    ll ans = 0;
    for (ll i = 0; i < k; i++) {
        boy_count[boy[i]]--;
        girl_count[girl[i]]--;
        ans += k - boy_count[boy[i]] - girl_count[girl[i]] - 1;
    }

    cout << ans / 2 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}