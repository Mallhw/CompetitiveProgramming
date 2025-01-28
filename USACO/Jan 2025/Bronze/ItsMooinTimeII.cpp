#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    cin >> n;
    vector<ll> arr(n);


    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll ans = 0;
    unordered_set<string> uniques;

    
    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int l = j + 1; l < n; l++) {
                if(arr[i] != arr[j] && arr[j] == arr[l]) {
                    string nm = to_string(arr[i]) + ' ' + to_string(arr[j]) + ' ' + to_string(arr[l]);
                    uniques.insert(nm);
                }
            }
        }
    }


    cout << uniques.size() << endl;
    return 0;
}