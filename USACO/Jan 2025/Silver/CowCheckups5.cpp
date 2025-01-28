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
    int n;
    cin >> n;
    vll a(n);
    vll b(n);
    unordered_map<ll, vll> mapA;
    unordered_map<ll, vll> mapB;


    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        mapA[a[i]].push_back(i);
    }
    for(ll i = 0; i < n; i++) {
        cin >> b[i];
        mapB[b[i]].push_back(i);
    }
    ll ans = 0;
    // dbg(a);
    // dbg(b);
    for(int i = 0; i < n; i++) {
        ll curNum = a[i];
        dbg(ans);
        // Scnario 1 when the equal
        if(a[i] == b[i]) {
            
            // check just same
            ans += n;
            ans += min(i, (n-1) - i);
            ll left = max((i * (i - 1)), 0) / 2;
            ll right = max(((n - i - 2) * (n - i - 1) ), 0) / 2; 
            ans += (left + right);

            for(int j = 0; j < mapB[curNum].size(); j++) {
                if(i != mapB[curNum][j]) {
                    ll front = min(j, mapB[curNum][j]);
                    ll back = max(j, mapB[curNum][j]);
                    ans += (min(front, (n-1) - back) + 1);
                }      
            }
        }

        // Scenario 2 if jits dont equal
        if(a[i] != b[i]) {
            for(int j = 0; j < mapB[curNum].size(); j++) {
                if(i != mapB[curNum][j]) {
                    ll front = min(j, mapB[curNum][j]);
                    ll back = max(j, mapB[curNum][j]);
                    ans += (min(front, (n-1) - back) + 1);
                }      

            }
        }
    }
    cout << ans << endl;
    return 0; 
} 
