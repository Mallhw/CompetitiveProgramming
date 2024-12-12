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
    ll T; 
    cin >> T; 
    while (T--) { 
        ll n;
        cin >> n;
        multiset<ll> arr;
        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            arr.insert(x);
        }
        ll ans = 0;
        auto it = arr.begin();
        while (it != prev(arr.end())) {
            auto next_it = next(it);
            if (*it + *next_it <= *arr.rbegin()) {
                ans++;
            }
            it++;
        }
        cout << ans << endl;
    } 
    return 0; 
} 
