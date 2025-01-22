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
void solve() {
    ll n;
        cin >> n;
        map<ll, ll> counts;
        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            counts[x]++;
        }
        ll y = -1;
        for(auto &num : counts) {
            if (num.second >= 2) {
                y = num.first;
                counts[num.first] -= 2;
                if(counts[num.first] <= 0) {
                    counts.erase(num.first);
                }
                break;
            }
        }
        if(y == -1) {
            cout << -1 << endl;
            return;
        }
        vll vec;
        for(auto &num: counts) {
            for(ll i = 0; i < num.second; i++) {
                vec.push_back(num.first);
            }
        }
        sort(vec.begin(), vec.end());
        
            for(ll i = 0; i < vec.size()-1; i++) {
                ll a = vec[i];
                ll b = vec[i+1];
                if(abs(b - a) < 2 * y) {
                    cout << a << " " << b << " " << y << " " << y << endl;
                    return;
                }
            }
        
        cout << -1 << endl;
        return;
}
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    ll T; 
    cin >> T; 
    while (T--) { 
        solve();
    } 
    return 0; 
} 
