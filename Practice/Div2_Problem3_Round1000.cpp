#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    vll arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll start = l - 1;    
    ll rangeLen = min(min(r - l + 1, r), n - start);
    vll left, right;
    for(ll i = 0; i < r; i++) {
        left.push_back(arr[i]);
    }
    for(ll i = start; i < n; i++) {
        right.push_back(arr[i]);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    ll lSum = 0; 
    ll rSum = 0;

    for(ll i = 0; i < rangeLen; i++) {
        if(i < left.size()) {
            lSum += left[i];
        }
        if(i < right.size()) {
            rSum += right[i];
        }
    }
    cout << min(lSum, rSum) << endl;
    return;
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
