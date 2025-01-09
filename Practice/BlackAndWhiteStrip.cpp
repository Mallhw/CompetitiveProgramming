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
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T; 
    cin >> T; 
    while (T--) { 
        ll n, k;
        cin >> n >> k;
        vll arr(n);
        vll prefix(n+1);
        string s;
        cin >> s;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'W') arr[i] = 0;
            else if(s[i] == 'B') arr[i] = 1;
            prefix[i+1] = prefix[i] + arr[i];
        }
        ll ans = k;
        for(int i = k; i < n+1; i++){;
            ans = min(ans, k - (prefix[i] - prefix[i-k]));
        }
        cout << ans << endl;
    } 
    return 0; 
} 
