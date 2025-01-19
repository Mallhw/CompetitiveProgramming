#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
#define mod 1000000007 
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
void solve(const vector<ll>& arr, ll k) {
    unordered_map<ll, ll> map;
    ll ans = 0; 
    
    for (int num : arr) {
        map[num]++;
    }
    
    for (int num : arr) {
        int val = k - num;
        if (map[num] > 0 && map[val] > 0) {
            if (num == val && map[num] > 1) {
                ans++;
                map[num] -= 2;
            } else if (num != val) {
                ans++;
                map[num]--;
                map[val]--;
            }
        }
    }
    
    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    cin >> T; 
    while (T--) { 
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(arr, k);
    } 
    return 0;
}
