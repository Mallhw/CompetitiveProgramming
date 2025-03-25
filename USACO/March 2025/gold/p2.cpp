#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll; 
void sol() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<pair<ll, ll>> queries(q);
    for (int i = 0; i < q; i++) cin >> queries[i].first >> queries[i].second;
    while(q--) {
        ll l, r;
        cin >> l >> r;
        l--; r--;
        cout << q + 2 << endl;
    }
    return;
}
int main() 
{ 
    sol();
    return 0; 
} 
