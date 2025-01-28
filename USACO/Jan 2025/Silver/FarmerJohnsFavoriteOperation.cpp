#include <bits/stdc++.h> 
using namespace std; 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
typedef long long int ll; 
typedef vector<long long> vll;

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        ll n, m;
        cin >> n >> m;
        vll arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            ll remain = arr[i] % m;
            ans += min(remain, m - remain);
        }
        cout << ans << endl;
    } 
    return 0; 
} 
