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
    int T; 
    cin >> T; 
    while (T--) { 
        ll a, s;
        ll ans = 0; ll count = 1;
        cin >> a >> s;
        ll i, j;
        while(a > 0) {
            i = a % 10; 
            j = s % 10;
            if(j < i) {
                s /= 10;
                j += s % 10 * 10;
            }
            if(i > j || (j-i) > 9) {
                ans = -1;
                break;
            }
            ans += count * (j-i);
            a = a / 10;
            s /= 10;
            count *= 10;
        }
        if(ans != -1) ans += count * s;
        cout << ans << endl;
    } 
    return 0; 
} 
