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
    ll n, m;
        cin >> n >> m;
        vector<pair<vector<ll>, ll>> arr;
        for(ll i = 0; i < n; i++) {
            vector<ll> temp(m);
            for(ll j = 0; j < m; j++) {
                cin >> temp[j];
            }
            sort(temp.begin(), temp.end());
            arr.push_back({temp, i});
        }
        sort(arr.begin(), arr.end(), [](pair<vector<ll>, ll> i, pair<vector<ll>, ll> j) {
            return i.first[0] < j.first[0];
        });
        for(ll j = 0; j < m; j++) {
            for(ll i = 1; i < n; i++) {
            if(arr[i].F[j] <= arr[i-1].F[j]) {
                    cout << -1 << endl;
                    return;
                }
            }
        }
        
        for(ll i = 0; i < n; i++) {
            cout << arr[i].S + 1 << " ";
        }
        cout << endl;
        return;
}
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        solve();
    } 
    return 0; 
} 
