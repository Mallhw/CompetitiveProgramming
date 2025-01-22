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
        vll a(n);
        map<ll, ll> mp;
        priority_queue<ll> pq;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        for(int i = 0; i < m; i++) {
            ll temp;
            cin >> temp;
            pq.push(temp);
        }

        for(int i = 0; i < 2 * n - m; i++) {
            if(pq.empty()) {
                cout << "NO" << endl;
                return;
            }
            ll x = pq.top();
            pq.pop();
            if(mp[x] == 0) {
                pq.push(x / 2);
                pq.push((x+1) / 2);
            }
            else {
                mp[x]--;
            }
        }
        if(pq.empty()) {
            cout << "YES" << endl;
            return;
        }
        cout << "NO" << endl;
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
