#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll m, k;
    cin >> m >> k;
    vector<ll> bases;
    string bits = bitset<5>(k).to_string();
    for(int i = 0; i < 5; i++) {
        if(bits[4 - i] == '1') {
            bases.push_back(pow(2, i));
        }
    }
    vector<ll> ans;
    ll total = 0;
    for(ll b : bases) {
        ll num = (pow(2, b)) - 1;
        ans.push_back(num);
        total += num;
    }
    
    if(total > m) {
        cout << -1 << endl;
        return;
    }

    // edge me harder bru when shi is exactly 1 kms
    if(m - total == 1) {
        bool fixed = false;
        for(auto &x : ans) {
            if(x == 1) {
                x = 2;
                total += 1;
                fixed = true;
                break;
            }
        }
        if(fixed) {
            cout << ans.size() << endl;
            for(ll x : ans){
                cout << x << " ";
            }
            cout << endl;
            return;
        }
    }

    bool pendingAdjust = false;
    if((total & 1LL) != (m & 1LL)) {
        ans.push_back(1);
        pendingAdjust = true;
        total += 1;
    }
    

    ll pre = 1;
    for(int i = 1; i < 31; i++) {
        ll cur = pre * 2; 
        if(((total >> i) & 1LL) == ((m >> i) & 1LL)) {
            pre = cur;
            continue;
        }
        if(pendingAdjust) {
            ans.push_back(cur);
            total += cur;
            pendingAdjust = false;
        } else {
            ans.push_back(pre);
            ans.push_back(pre);
            total += cur;
        }
        pre = cur;
    }
    if(pendingAdjust || total != m) {
        cout << -1 << endl;
        return;
    }
    
    cout << ans.size() << endl;
    for(auto v : ans)
        cout << v << " ";
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
