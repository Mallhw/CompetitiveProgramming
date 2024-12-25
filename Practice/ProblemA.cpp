#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define min(a, b) ((a > b) ? b : a) 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        ll n;
        cin >> n;
        ll size = n/2 + 1;
        vector<ll> arr(n);
        vector<ll> prefix(n+1);
        ll totalSum = 0;
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            prefix[i+1] = prefix[i] + arr[i];
            totalSum += arr[i];
        }
        ll minSum = LLONG_MAX;
        for (ll i = 0; i <= n - size; i++) {
            ll cur = prefix[i+size] - prefix[i];
            minSum = min(minSum, cur);
        }
        ll bessie = minSum;
        cout << bessie << " " << totalSum - bessie << endl;
    }
    return 0;
}
