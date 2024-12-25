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
            int numDigits = floor(log10(n));
            ll k = 0;
            for(int i = 0; i < numDigits-1; i++) {
                k += 4;
                k *= 10;
            }
            k += 5;
            dbg(k);
            ll l = k;
            ll first_digit = n / ((ll) pow(10, numDigits));
            dbg(first_digit);
            for(int i = 0; i < numDigits-1; i++) {
                while(l <= n) {
                    l += pow(10, numDigits);
                    
                    if(i == numDigits-1) {
                        ll curDigit = (ll) (n / round((ll) pow(10, numDigits))) % 10;
                        ans += abs(curDigit - 5) * pow(10, i);
                    }
                    else {
                        ans += 5 * pow(10, i);
                    }
                    dbg(l);
                    dbg(ans);
                }
                l += (ll) (5 * ((ll) pow(10, i)));
                dbg(l);
                l -= round((first_digit * pow(10, numDigits)));
                dbg(( (first_digit * pow(10, numDigits))));
                dbg(l);
            }
            cout << ans << endl;
        }
       
    } 
    return 0; 
} 
