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
        vll a(n);
        vll b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        for(int i = 0; i < n; i++) {
            cin >> b[i];  
        }
        ll dif = b[0] - a[0];
        for(int i = 0; i < n; i++) {
            dif = max(dif, a[i] - b[i]);
        }
        for(int i = 0; i < n; i++) {
            if(b[i] > a[i]) {
                cout << "NO" << endl;
                return;
            }
            else if(a[i] - b[i] != dif && b[i] != 0) {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
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
