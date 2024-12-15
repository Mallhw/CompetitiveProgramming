#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
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
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        ll ans = 0;
        for(ll x = l1; x <= r1; x++) {
            ll minN = max(0, (ll) ceil(log(l2 / (double) x) / log(k)));
            ll maxN = (ll) floor(log(r2 / (double)x) / log(k));
            if (minN <= maxN) {
                ans += (maxN - minN + 1);
            }
        }
        cout << ans << endl;
    } 
    return 0; 
} 
