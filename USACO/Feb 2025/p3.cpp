#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
void sol() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    if(k == 1) {
        cout << "YES" << '\n';
        return;
    }
    vector<vector<ll>> dp(n, vector<ll>(n, LLONG_MAX));
    for(int i = 0; i < n; i++){
        dp[i][i] = 1;
    }
    for(int s = 0; s < n + 1; s++){
        for(int i = 0; i < n - s + 1; i++){
            ll next = (i + s) - 1;
            for(int c = i; c < next; c++){
                if (dp[i][c] != LLONG_MAX && dp[c+1][next] != LLONG_MAX) {
                    dp[i][next] = min(dp[i][next], dp[i][c] + dp[c+1][next]);
                }
            }
            for(int p = 1; p < s + 1; p++){
                if(s % p == 0){
                    bool repeats = true;
                    for(int c = i; c < next + 1; c++){
                        ll dis = ((c - i) % p);
                        if(arr[c] != arr[i + dis]){
                            repeats = false;
                            break;
                        }
                    }
                    if(repeats && dp[i][i + p - 1] < dp[i][next]) dp[i][next] = min(dp[i][next], dp[i][i + p - 1]);
                }
            }
        }
    }
    if(dp[0][n - 1] < k + 1){
        cout << "YES" << '\n';
        return;
    }
    cout << "NO" << '\n';
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}