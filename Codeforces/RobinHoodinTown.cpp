#include "bits/stdc++.h" 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define mod 1e9 + 7 
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++) 
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
#define INF 1000000000000000003 
typedef long long int ll; 
typedef vector<long long> vll;
typedef vector<int> vi; 
typedef pair<int, int> pi; 
#define F first 
#define S second 
#define PB push_back 
#define POB pop_back 
#define MP make_pair 
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    ll  T; 
    cin >> T; 
    while (T--) { 
        ll  n;
        cin >> n;
        vi arr(n);
        ll sum = 0;
        for(ll i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        sort(arr.begin(), arr.end());
        ll middle = arr[n/2];
        //cout << middle << endl;
        ll ans = (middle) * (2 * n) + 1 - sum;
        //cout << ans << endl;
        if(n <= 2) {
            cout << -1 << endl;
        }
        else {
            cout << max(ans, 0) << endl;
        }
    } 
    return 0; 
} 
