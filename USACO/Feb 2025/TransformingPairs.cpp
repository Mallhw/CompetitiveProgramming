#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll; 
int main() 
{ 
    int t;
    cin >> t;
    while(t--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll ans = 0;
        ll gc = __gcd(c, d);
        ll ab = __gcd(a, b);
        if(gc != ab || (a > c || b > d)) {
            cout << -1 << "\n";
            continue;
        }
        while(c > a || d > b) {
            if(c < a || d < b) {
                break;
            }
            if (c >= d) {
                ll cuts = (c - max(a, d)) / d;
                if((c - max(a, d)) % d != 0) cuts++;
                if(cuts == 0) break;
                ans += cuts;
                c -= cuts * d;
            } 
            else {
                ll cuts = (d - max(b, c)) / c;
                if((d - max(b, c)) % c != 0) cuts++;
                if(cuts == 0) break;
                ans += cuts;
                d -= cuts * c;
            }
        }
        if(c == a && d == b) {
            cout << ans << endl;
        } 
        else {
            cout << -1 << endl;
        }
    }
    return 0; 
} 
