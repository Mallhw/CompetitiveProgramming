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
    int n, m, k;
        cin >> n >> m >> k;
        vll even(m);
        vll odds(m);
        vll evenSmall(m);
        vll oddsSmall(m);
        FOR(i, m) {
            FOR(j, k) {
                int x;
                cin >> x;
                if(x % 2 == 0) {
                    even[i] = max(even[i], x);
                    evenSmall[i] = min(even[i], x);
                } else {
                    odds[i] = max(odds[i], x);
                    oddsSmall[i] = min(odds[i], x);
                }
            } 
        }

        vll prefix(m+1, 0);
        for(int i = m; i > 0; i--) {
            prefix[i-1] = prefix[i] + min(even[i-1], odds[i-1]);  
        }



        for(int i = 0; i < m; i++) {
            if(n - prefix[i] <= 0) {
                cout << -1;
                return;
            }
            else {
                if(n - (prefix[i+1] + odds[i]) > 0) {
                    cout << "Even";
                    if(odds[i] == 0) {
                        n += evenSmall[i];
                    }
                    else {
                        n-= odds[i];
                    }
                }
                else {
                    cout << "Odd";
                    if(even[i] == 0) {
                        n += oddsSmall[i];
                    }
                    else {
                        n -= even[i];
                    }
                }
            }
            if(i != m-1) cout << " ";
        }
        cout << endl;
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
