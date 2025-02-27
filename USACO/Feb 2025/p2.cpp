#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
void sol() {
    ll n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    vector<ll> counts(n + 1, 0);
    for(int i = 0; i < n; i++) {
        counts[sorted[i]]++;
    }
    ll ans[n + 1];
    ll total = 0;
    for(int i = 0; i < n + 1; i++) {
        if(counts[i] == 0) {
            cout << total << '\n';
            total++;
        }
        else {
            if(counts[i] < total) {
                cout << total << '\n';
            }
            else {
                cout << counts[i] << '\n';
            }
        }
    }
    return;
}
int main() 
{ 
    sol();
    return 0; 
} 

