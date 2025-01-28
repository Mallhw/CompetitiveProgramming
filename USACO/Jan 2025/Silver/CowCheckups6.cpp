#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
typedef long long int ll; 
typedef vector<long long> vll;


void solve(ll n, vll &a, vll &b, vll &match) {
    vll left(n);
    vll right(n);
    for(int i = 0; i < n; i++) {
        left[i] = max(0, i - (n - 1 - i));
        right[i] = min(n - 1, i + (n - 1 - i));
    }

    ll total = 0;

    for(int i = 0; i < n; i++) {
        total += match[i];
    }
    for(int i = 0; i < n; i++) {
        total += (ll) (right[i] - left[i] + 1) * match[i];
    }

    cout << total << endl;
}

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    ll n;
    cin >> n;
    vll a(n);
    vll b(n);
    vll match(n+1);
    vll prefix(n+1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        if(a[i] == b[i]) {
            match[i] = 1;
        }
        prefix[i+1] = prefix[i] + match[i];
    }

    // dbg(match);
    // dbg(prefix);

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(match[i]) {
            ans += n;
            ll numSubarrays = (ll) (i + 1) * (n - i);
            ans += numSubarrays;
        }
    }
    
    cout << ans << endl;
    return 0;
}

