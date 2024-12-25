#include <bits/stdc++.h> 
using namespace std; 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
#define max(a, b) (a < b ? b : a) 

typedef long long int ll; 
typedef vector<long long> vll;

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        int n;
        cin >> n;
        ll ans = 0;
        if(n <= 45) {
            cout << 0 << endl;
        }
        else{ 
            
            for(int i = 2; i <= floor(log10(n)); i++) {
                dbg(i);
                ll front_index = n / (ll) (pow(10, i));
                ll k = n;
                front_index %= 10;
                if(front_index == 0) {
                    ll val = 5 * max(1, pow(10, i-2));
                    ans += val;
                }
                
                for(int j = 0; j < front_index; j++) {
                    ll val = 5 * max(1, pow(10, i-2));
                    ans += val;
                    dbg(ans);
                }
                if(i == floor(log10(n))) {
                    ll end = pow(10, i) * front_index + 45 * pow(10, i-2);
                    ll extra = max(0, n - end + 1);
                    ans += extra;
                }
                
            }
            cout << ans << endl;
        }
       
    } 
    return 0; 
} 
