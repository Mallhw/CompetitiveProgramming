#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll; 
bool check(vector<ll> temp, vector<ll> ans) {
    for(ll i = 0; i < min(temp.size(), ans.size()); i++) {
        if(temp[i] > ans[i]) return true;
        if(temp[i] < ans[i]) return false;
    }
    if(temp.size() > ans.size()) {
        return true;
    }
    return false;
}
int main() 
{ 
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<ll> ans = arr;
        for(ll i = 0; i < n; i++) {
            for(ll j = i + 1; j < n; j++) {
                vector<ll> temp = arr;
                ll val = temp[j];
                temp.erase(temp.begin() + j);
                temp.insert(temp.begin() + i, val);
                if(check(temp, ans)) {
                    ans = temp;
                }
            }
        }

        
        vector<ll> b;
        ll cur = LLONG_MIN;
        for(ll i = n - 1; i >= 0; i--) {
            if(ans[i] >= cur) {
                b.push_back(ans[i]);      
                cur = ans[i];        
            }
        }
        for(ll i = b.size() - 1; i >= 0; i--) {
            cout << b[i];
            if(i != 0) cout << " ";
        }
        cout << endl;
    }
    return 0; 
} 
