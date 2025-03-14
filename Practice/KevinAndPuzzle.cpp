#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
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
#define mod 998244353 
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        ll n;
        cin >> n;
        vll arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        ll ans = 0;
        ll numLiars = 0;
        for(int i = 0; i < n; i++) {
            ll liars = 0;
            bool check = true;
            for(int j = 0; j < n; j++) {
                if(j != i) {
                    dbg(arr[i]);
                    dbg(arr[j]);
                    dbg(liars);
                    if(arr[i] != arr[j] + liars) {
                        check = false;
                        break;
                    }
                    liars++;
                }
            }
            if(check) {
                ans++;
            }
        }
        cout << ans << endl;
    } 
    return 0; 
} 
