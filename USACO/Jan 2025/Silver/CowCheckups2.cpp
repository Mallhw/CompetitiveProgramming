#include <bits/stdc++.h> 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
typedef long long int ll; 
typedef vector<long long> vll;

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    ll n;
    cin >> n;
    vll a(n);
    vll b(n);
    unordered_map<ll, ll> mapA;
    unordered_map<ll, ll> mapB;


    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        mapA[a[i]] = i;
    }
    for(ll i = 0; i < n; i++) {
        cin >> b[i];
        mapB[b[i]] = i;
    }
    ll ans = 0;
    // dbg(a);
    // dbg(b);
    for(int i = 0; i < n; i++) {
        ll curNum = a[i];

        // Scnario 1 when the equal
        if(mapA[curNum] == mapB[curNum]) {
            ans += n;
            ll total = pow(n-2, 2);
            ans += total;
            ans == min(mapA[curNum], (n-1) - mapA[curNum]);
        }

        // Scenario 2 if jits dont equal
        if(mapA[curNum] != mapB[curNum]) {
            ll front = min(mapA[curNum], mapB[curNum]);
            ll back = max(mapA[curNum], mapB[curNum]);
            ans += (min(front, (n-1) - back) + 1);
        }
    }
    cout << ans << endl;
    return 0; 
} 
