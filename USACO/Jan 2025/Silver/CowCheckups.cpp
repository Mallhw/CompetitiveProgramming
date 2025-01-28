#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll; 
typedef vector<long long> vll;

int main() 
{ 
    ll n;
    cin >> n;
    vll a(n);
    vll b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll ans = 0;


    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            ll totalCur = 0;
            vll temp = a;
            reverse(temp.begin() + i, temp.begin() + j + 1);

            for(int k = 0; k < n; k++) {
                if(temp[k] == b[k]) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0; 
} 
