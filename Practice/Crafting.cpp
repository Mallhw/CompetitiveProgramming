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
    vll a(n), b(n);

    FOR(i, n) cin >> a[i];
    FOR(i, n) cin >> b[i];

    ll neededToAdd = 0;     
    ll maxRed = INF; 
    bool possible = true;
    FOR(i, n) {
        if (a[i] < b[i]) {
            neededToAdd++;
            if (neededToAdd > 1) {
                possible = false; 
                break;
            }
        } else {
            maxRed = min(maxRed, a[i] - b[i]);
        }
    }
    if (!possible) {
        cout << "NO" << endl;
        return;
    }
    FOR(i, n) {
        if (a[i] < b[i]) {
            ll deficit = b[i] - a[i];
            if (deficit > maxRed) {
                cout << "NO" << endl;
                return;
            }
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
